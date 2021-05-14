#include "windowspecialist.h"
#include "ui_windowspecialist.h"
#include <QSqlQuery>
#include <typeinfo>
#include <QDebug>

WindowSpecialist::WindowSpecialist(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowSpecialist),
    sp(new Specialist)
{
    ui->setupUi(this);
}


void WindowSpecialist::setSpParam(QString login)
{
    QSqlQuery *q = new QSqlQuery();
    q->prepare("select id, name, patronymic, surname, login from specialist where login = :login");
    q->bindValue(":login", login);
    if ( q->exec())
    {
        q->first();

        sp->setId(q->value("id").toInt());
        sp->setName(q->value("name").toString());
        sp->setPatronymic(q->value("patronymic").toString());
        sp->setSurname(q->value("surname").toString());
        sp->setLogin(q->value("login").toString());
    }
    else qCritical() << "cannot execute query";

}

WindowSpecialist::~WindowSpecialist()
{
    delete ui;
    delete sp;
    delete wClientBase;
    delete wTimetable;
    delete wStatistic;
    delete wProgram;
}

void WindowSpecialist::on_pushButton_clientBase_clicked()
{
    wStarter = takeCentralWidget();
    wClientBase = new WidgetClientBase;
    setCentralWidget(wClientBase);
}

void WindowSpecialist::on_pushButton_timetable_clicked()
{
    wTimetable = new WidgetTimetable;
    wStarter = takeCentralWidget();
    setCentralWidget(wTimetable);
}

void WindowSpecialist::on_pushButton_statistic_clicked()
{
    wStatistic = new WidgetStatistic;
    wStarter = takeCentralWidget();
    setCentralWidget(wStatistic);
}

void WindowSpecialist::on_pushButton_program_clicked()
{
    wProgram = new WidgetProgram;
    wStarter = takeCentralWidget();
    setCentralWidget(wProgram);
}

void WindowSpecialist::on_actionOnStarter_triggered()
{
    setCentralWidget(wStarter);
}

