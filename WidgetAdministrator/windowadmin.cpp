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

WindowAdmin::~WindowAdmin()
{
    delete ui;
    delete admin;
    delete wTimetable;
    delete wStarter;
}

void WindowAdmin::on_pushButton_timetable_clicked()
{
    wStarter = takeCentralWidget();
    setCentralWidget(wTimetable);
}




