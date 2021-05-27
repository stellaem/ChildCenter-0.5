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
    ui(new Ui::WidgetAdministratorTimetable),
    queryModelClasses(new QSqlQueryModel),
    queryModelCabinet(new QSqlQueryModel)
{

    Settings *settings = new Settings();
    setModelCabinet();
    setQueryModelClasses();
    ui->setupUi(this);
    ui->quickWidget_timetable->rootContext()->setContextProperty("qMClasses", queryModelClasses);
    ui->quickWidget_timetable->rootContext()->setContextProperty("qMCabinet", queryModelCabinet);
    ui->quickWidget_timetable->rootContext()->setContextProperty("settings", settings);
}

void WidgetAdministratorTimetable::setModelCabinet()
{
    queryModelCabinet->setQuery("select id, name from cabinet");
}

void WidgetAdministratorTimetable::setQueryModelClasses()
{
    queryModelClasses->setQuery("select id, TIME(date_and_time), cabinet, specialist, duration, type "
                                "from class where DATE(date_and_time) = '" + date.toString("yyyy-MM-dd") + "'");
}

void WidgetAdministratorTimetable::reloadQueryModelClasses()
{
    setQueryModelClasses();
    QMetaObject::invokeMethod(ui->quickWidget_timetable->rootObject(), "reloadItems");
}

void WidgetAdministratorTimetable::on_calendarWidget_clicked(const QDate &d)
{
    date = d;
    reloadQueryModelClasses();
}

WidgetAdministratorTimetable::~WidgetAdministratorTimetable()
{
    delete ui;
}
