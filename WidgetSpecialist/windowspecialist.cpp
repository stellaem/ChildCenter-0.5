#include "windowspecialist.h"
#include "ui_windowspecialist.h"

#include <QSqlQuery>
#include <QDebug>
/**************************************************************************************************/
WindowSpecialist::WindowSpecialist(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowSpecialist)
{
    ui->setupUi(this);
}
/*------------------------------------------------------------------------------------------------*/
void WindowSpecialist::setSp(QString login)
{
    sp = new Specialist(login);
}
/*------------------------------------------------------------------------------------------------*/
WindowSpecialist::~WindowSpecialist()
{
    delete ui;
    delete sp;
    delete wClientBase;
    delete wTimetable;
    delete wStatistic;
    delete wProgram;
}
/*------------------------------------------------------------------------------------------------*/
void WindowSpecialist::on_pushButton_clientBase_clicked()
{
    wStarter = takeCentralWidget();
    wClientBase = new WidgetClientBase;
    setCentralWidget(wClientBase);
}
/*------------------------------------------------------------------------------------------------*/
void WindowSpecialist::on_pushButton_timetable_clicked()
{
    wTimetable = new WidgetTimetable;
    wStarter = takeCentralWidget();
    setCentralWidget(wTimetable);
}
/*------------------------------------------------------------------------------------------------*/
void WindowSpecialist::on_pushButton_statistic_clicked()
{
    wStatistic = new WidgetStatistic;
    wStarter = takeCentralWidget();
    setCentralWidget(wStatistic);
}
/*------------------------------------------------------------------------------------------------*/
void WindowSpecialist::on_pushButton_program_clicked()
{
    wProgram = new WidgetProgram;
    wStarter = takeCentralWidget();
    setCentralWidget(wProgram);
}
/**************************************************************************************************/
