#include <QDebug>
#include <QDate>
#include <QSqlError>

#include "objects/celltimetable.h"
#include "modelclassesincabinet.h"

/**************************************************************************************************/
ModelClassesInCabinet::ModelClassesInCabinet(QObject *parent, int c, QDate d):
    settings(Settings()), cabinet(c), date(d)
{
    createEmpryGrid();
    findClassesInBase();
    createTimetable();
}
/*------------------------------------------------------------------------------------------------*/
int ModelClassesInCabinet::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return mapCellTimetable.size();
}
/*------------------------------------------------------------------------------------------------*/
QVariant ModelClassesInCabinet::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant();
    switch (role) {
    case Qt::DisplayRole: return listCellTimeTable[index.row()].getDateTimeStart().time().toString("hh:mm");
    case SizeRole: return listCellTimeTable[index.row()].getDuration();
    default: return QVariant();
    }
}
/*------------------------------------------------------------------------------------------------*/
QHash<int, QByteArray> ModelClassesInCabinet::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[ColorRole] = "color";
    roles[SizeRole] = "size";
    return roles;
}

void ModelClassesInCabinet::reloadData(QDate d)
{
    setDate(d);
    createEmpryGrid();
    findClassesInBase();
    createTimetable();
    endResetModel();
}
/*------------------------------------------------------------------------------------------------*/
void ModelClassesInCabinet::createEmpryGrid()
{
    mapCellTimetable.clear();
    for (int numCell = 0; numCell < settings.countSegments(); numCell++ )
    {
        CellTimetable cell = CellTimetable();
        cell.setIdSp(-1);
        cell.setDateTimeStart(QDateTime ( date, QTime( settings.getStartCenter().addSecs(
                                                       numCell * settings.secInSegment() ) ) ) );
        cell.setDuration(settings.minInSegment());
        cell.setIsNotEmpty(false);
        mapCellTimetable.insert(cell.timeStart(), cell);
    }
}
/*------------------------------------------------------------------------------------------------*/
void ModelClassesInCabinet::findClassesInBase()
{
    mapCellClass.clear();
    QSqlQuery query;
    query.prepare("select id, date_and_time, cabinet, specialist, duration, type "
                  "from class where cabinet = ? and DATE(date_and_time) = ?");
    query.addBindValue(QString::number(cabinet));
    query.addBindValue(date.toString("yyyy-MM-dd"));

    if (query.exec())
    {
        while (query.next())
        {
            CellTimetable cell = CellTimetable();
            cell.setDateTimeStart(query.value("date_and_time").toDateTime());
            cell.setDuration(query.value("duration").toInt());
            cell.setIsNotEmpty(true);
            cell.setIdSp(query.value("specialist").toInt());
            mapCellClass.insert(cell.timeStart(), cell);
        }
    }
}
/*------------------------------------------------------------------------------------------------*/
void ModelClassesInCabinet::createTimetable()
{
    listCellTimeTable.clear();
    foreach(CellTimetable cell, mapCellClass.values())
    {
        // BUG если продолжительность занятия не кратно minInSegment,
        // то count_cell будет не действительно, так как не целое число. нужно исправить
        int count_cell = cell.getDuration() / settings.minInSegment();
        for(int i = 0; i < count_cell; i++)
        {
            QMap<QTime, CellTimetable>::iterator elem = mapCellTimetable.find(
                        cell.getDateTimeStart().time().addSecs(i*settings.secInSegment()));
            mapCellTimetable.erase(elem);
        }
        mapCellTimetable.insert(cell.getDateTimeStart().time(), cell);
    }
    QMapIterator<QTime, CellTimetable> cell(mapCellTimetable);
    while (cell.hasNext()) {
        cell.next();
        listCellTimeTable.append(cell.value());
    }
}
/*------------------------------------------------------------------------------------------------*/
void ModelClassesInCabinet::setDate(const QDate &value)
{
    date = value;
}
/*------------------------------------------------------------------------------------------------*/
ModelClassesInCabinet::~ModelClassesInCabinet()
{
    //BUG почему-то не работает qDelete
//    qDeleteAll(mapCellClass);
//    qDeleteAll(mapCellTimetable);
//    qDeleteAll(listCellTimeTable);
}

/**************************************************************************************************/
