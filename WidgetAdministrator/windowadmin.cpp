#include "windowadmin.h"
#include "ui_windowadmin.h"

WindowAdmin::WindowAdmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowAdmin),
    admin(new Administrator),
    wTimetable(new WidgetAdministratorTimetable)
{
    ui->setupUi(this);
}

void WindowAdmin::setAdminParam(QString login)
{

}

WindowAdmin::~WindowAdmin()
{
    delete ui;
    delete admin;
    delete wTimetable;
    delete wStarter;
}

void WindowAdmin::on_pushButton_task_clicked()
{

}

void WindowAdmin::on_pushButton_timetable_clicked()
{
    wStarter = takeCentralWidget();
    setCentralWidget(wTimetable);
}
