#include "dialogenter.h"
#include "ui_dialogenter.h"

DialogEnter::DialogEnter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEnter)
{
    ui->setupUi(this);
    edit_login = ui->lineEdit_login;
    edit_role = ui->comboBox_role;
    edit_password = ui->lineEdit_password;

}



DialogEnter::~DialogEnter()
{
    delete ui;
    delete edit_login;
}



