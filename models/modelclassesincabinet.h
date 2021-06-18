#pragma once
#pragma warning(disable:4100)

#include <QAbstractListModel>
#include <QSqlQuery>
#include <QDateTime>
#include <QList>
#include <QMap>

#include "objects/cellclass.h"
#include "settings/settings.h"


class ModelClassesInCabinet : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ModelClassesInCabinet(QObject *parent = nullptr, int c = -1, QDate d = QDate());
    enum Roles
    {
        ColorRole = Qt::UserRole + 1,
        SizeRole
    };
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data( const QModelIndex &index, int role = Qt::DisplayRole)const override;
    virtual QHash<int, QByteArray> roleNames() const override;
    void reloadData(QDate d);

    virtual ~ModelClassesInCabinet();

    void setDate(const QDate &value);

private:
    Settings settings;
    int cabinet;
    QDate date;

    QMap<QTime, CellClass > mapCellClass; // сетка занятий
    QMap<QTime, CellClass > mapCellTimetable; // сводная сетка расписания
    QList<CellClass> listCellTimeTable;

    void findClassesInBase(void);
    void createTimetable(void);
    void createEmpryGrid(void);


};
Q_DECLARE_METATYPE( ModelClassesInCabinet )
