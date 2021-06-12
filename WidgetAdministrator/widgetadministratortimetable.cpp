#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>
#include <QQmlContext>
#include <typeinfo>
#include <QMetaObject>
#include <QQuickItem>

#include "widgetadministratortimetable.h"
#include "ui_widgetadministratortimetable.h"
#include "settings/settings.h"
#include "settings/appearance.h"

WidgetAdministratorTimetable::WidgetAdministratorTimetable(QWidget *parent) :
    QWidget(parent),
    date(QDate().currentDate()),
    ui(new Ui::WidgetAdministratorTimetable),
    queryModelClasses(new QSqlQueryModel),
    queryModelCabinet(new QSqlQueryModel),
    tableModelTask(new TableModelTask)
{
    extern Settings *settings;
    extern Appearance *appearance;
    setModelCabinet();
    setQueryModelClasses();
    tableModelTask->setDate(QDate().currentDate());
    qDebug() << tableModelTask->query().lastQuery();
    ui->setupUi(this);
    ui->quickWidget_timetable->rootContext()->setContextProperty("qMClasses", queryModelClasses);
    ui->quickWidget_timetable->rootContext()->setContextProperty("qMCabinet", queryModelCabinet);
    ui->quickWidget_timetable->rootContext()->setContextProperty("settings", settings);
    ui->quickWidget_timetable->rootContext()->setContextProperty("appearance", appearance);
    ui->quickWidget_header->rootContext()->setContextProperty("appearance", appearance);
    ui->quickWidget_tasks->rootContext()->setContextProperty("appearance", appearance);
    ui->quickWidget_tasks->rootContext()->setContextProperty("tableModelTask", tableModelTask);
}

void WidgetAdministratorTimetable::setModelCabinet(){ queryModelCabinet->setQuery("select id, name from cabinet"); }

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
    tableModelTask->setDate(date);
}

WidgetAdministratorTimetable::~WidgetAdministratorTimetable()
{
    delete ui;
}

