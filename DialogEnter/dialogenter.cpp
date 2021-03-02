#include "dialogenter.h"
#include "ui_dialogenter.h"

DialogEnter::DialogEnter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEnter)
{
    ui->setupUi(this);
    edit_login = ui->lineEdit_login;
}



DialogEnter::~DialogEnter()
{
    delete ui;
    delete edit_login;
}



