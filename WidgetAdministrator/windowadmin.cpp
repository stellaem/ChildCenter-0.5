#include "windowadmin.h"
#include "ui_windowadmin.h"
#include <QSqlQuery>
#include <QDebug>

WindowAdmin::WindowAdmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowAdmin),
    wTimetable(new WidgetAdministratorTimetable)
{
    ui->setupUi(this);
}

void WindowAdmin::setAdmin(QString login)
{
    QSqlQuery *q = new QSqlQuery();
    q->prepare("select id from administrator where login = :login");
    q->bindValue(":login", login);
    if ( q->exec())
    {
        q->first();
        admin = new Administrator(q->value("id").toInt());
    } else qCritical() << "cannot execute query";
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




