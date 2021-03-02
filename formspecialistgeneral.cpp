#include "formspecialistgeneral.h"
#include "ui_formspecialistgeneral.h"

FormSpecialistGeneral::FormSpecialistGeneral(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSpecialistGeneral)
{
    ui->setupUi(this);
}

FormSpecialistGeneral::~FormSpecialistGeneral()
{
    delete ui;
}
