#ifndef WIDGETADMINISTRATORTIMETABLE_H
#define WIDGETADMINISTRATORTIMETABLE_H

#include <QWidget>
#include <QQuickWidget>
#include <QList>
#include <QSqlQueryModel>
#include <QMap>
#include <QVariant>
#include <QDate>

#include "models/tablemodeltask.h"

namespace Ui { class WidgetAdministratorTimetable; }

class WidgetAdministratorTimetable : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetAdministratorTimetable(QWidget *parent = nullptr);
    ~WidgetAdministratorTimetable();

private slots:
    void on_calendarWidget_clicked(const QDate &d);
private:
    QDate date;
    Ui::WidgetAdministratorTimetable *ui;
    QList<QVariant> listVCabinet;
    QSqlQueryModel *queryModelCabinet;
    QSqlQueryModel *queryModelClasses;
    TableModelTask *tableModelTask;

    void setModelCabinet(void);
    void reloadQueryModelClasses(void);
    void setQueryModelClasses(void);

};

#endif // WIDGETADMINISTRATORTIMETABLE_H
