#include "formdevgeneral.h"
#include "ui_formdevgeneral.h"

FormDevGeneral::FormDevGeneral(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormDevGeneral)
{
    ui->setupUi(this);
}

FormDevGeneral::~FormDevGeneral()
{
    delete ui;
}
