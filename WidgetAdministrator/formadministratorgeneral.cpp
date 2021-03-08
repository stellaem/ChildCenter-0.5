#include "formadministratorgeneral.h"
#include "ui_formadministratorgeneral.h"


FormAdministratorGeneral::FormAdministratorGeneral(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAdministratorGeneral),
    admin(new Administrator)
{
    ui->setupUi(this);
}

void FormAdministratorGeneral::setAdminParam(QString login)
{

}

FormAdministratorGeneral::~FormAdministratorGeneral()
{
    delete ui;
    delete admin;
}
