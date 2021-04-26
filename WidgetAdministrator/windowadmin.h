#ifndef WINDOWADMIN_H
#define WINDOWADMIN_H

#include <QMainWindow>

#include "persons/Administrator.h"

#include "widgetadministratortimetable.h"

namespace Ui {
class WindowAdmin;
}

class WindowAdmin : public QMainWindow
{
    Q_OBJECT
public:
    explicit WindowAdmin(QWidget *parent = nullptr);
    void setAdminParam(QString login);
    ~WindowAdmin();

private slots:
    void on_pushButton_task_clicked();
    void on_pushButton_timetable_clicked();

private:
    Ui::WindowAdmin *ui;
    Administrator *admin;

    WidgetAdministratorTimetable *wTimetable;

    QWidget *wStarter;
};

#endif // WINDOWADMIN_H
