#include "widgetadministratortimetable.h"
#include "ui_widgetadministratortimetable.h"
#include "settings/settings.h"

#include <QMdiArea>
#include <QQmlApplicationEngine>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>
#include <QQmlContext>

#include <typeinfo>
#include <QVariant>
#include <QMetaObject>
#include <QQuickItem>


WidgetAdministratorTimetable::WidgetAdministratorTimetable(QWidget *parent) :
    QWidget(parent),
    date(QDate().currentDate()),
    ui(new Ui::WidgetAdministratorTimetable)
{
    Settings *settings = new Settings();
    createListCabinet();
    createQueryModelClasses();
    ui->setupUi(this);
    ui->quickWidget_timetable->rootContext()->setContextProperty("listVCabinet", listVCabinet);
    ui->quickWidget_timetable->rootContext()->setContextProperty("mapModelsClasses", mapQueryModelClassesInCabinet);
    ui->quickWidget_timetable->rootContext()->setContextProperty("settings", settings);

}

void WidgetAdministratorTimetable::createListCabinet()
{
    QSqlQuery q = QSqlQuery("select id, name from cabinet");
    while (q.next())
    {
        Cabinet *c = new Cabinet();
        c->setId(q.value("id").toInt());
        c->setName(q.value("name").toString());
        QVariant var = QVariant::fromValue(c);
        listVCabinet.append(var);
    }
}

void WidgetAdministratorTimetable::createQueryModelClasses()
{
    QVariant c;
    foreach(c, listVCabinet)
    {   int cabinetId = c.value<Cabinet*>()->getId();
        QSqlQueryModel *qModel = new QSqlQueryModel();
        qModel->setQuery("select id, TIME(date_and_time), cabinet, specialist, duration, type "
                         "from class where cabinet = " + QString::number(cabinetId) +
                         " and DATE(date_and_time) = '" + date.toString("yyyy-MM-dd") + "'");
        QVariant vModel = QVariant::fromValue(qModel);
        mapQueryModelClassesInCabinet.insert(QString::number(cabinetId), vModel);
    }
}

void WidgetAdministratorTimetable::reloadQueryModelClasses()
{
    QVariant c;
    foreach(c, listVCabinet)
    {
        int cabinetId = c.value<Cabinet*>()->getId();
        QSqlQueryModel *model = mapQueryModelClassesInCabinet.value(QString::number(cabinetId)).value<QSqlQueryModel*>();
        model->setQuery("select id, TIME(date_and_time), cabinet, specialist, duration, type "
                         "from class where cabinet = " + QString::number(cabinetId) +
                         " and DATE(date_and_time) = '" + date.toString("yyyy-MM-dd") + "'");

        qDebug() << 111;
        QMetaObject::invokeMethod(ui->quickWidget_timetable->rootObject(), "reloadItems");


    }
}

void WidgetAdministratorTimetable::on_calendarWidget_clicked(const QDate &d)
{
    date = d;
    reloadQueryModelClasses();
}

WidgetAdministratorTimetable::~WidgetAdministratorTimetable()
{
    delete ui;
//    qDeleteAll(listCabinet);
}
