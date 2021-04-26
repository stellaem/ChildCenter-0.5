#include "dialogenter.h"
#include "ui_dialogenter.h"

DialogEnter::DialogEnter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEnter)
{
    ui->setupUi(this);
    editLogin = ui->lineEdit_login;
    editRole = ui->comboBox_role;
    editPassword = ui->lineEdit_password;

}



DialogEnter::~DialogEnter()
{
    delete ui;
    delete editLogin;
}



