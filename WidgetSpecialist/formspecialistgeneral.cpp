#include <QSqlQuery>

#include "WidgetSpecialist/formspecialistgeneral.h"
#include "ui_formspecialistgeneral.h"


FormSpecialistGeneral::FormSpecialistGeneral(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSpecialistGeneral),
    sp(new Specialist)
{
    ui->setupUi(this);
}

void FormSpecialistGeneral::setSpParam(QString login)
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

FormSpecialistGeneral::~FormSpecialistGeneral()
{
    delete ui;
    delete sp;
}

void FormSpecialistGeneral::on_pushButton_clientList_clicked()
{
    qDebug() << sp->name();
}
