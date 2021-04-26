#include "widgetprogram.h"
#include "ui_widgetprogram.h"

WidgetProgram::WidgetProgram(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetProgram)
{
    ui->setupUi(this);
}

WidgetProgram::~WidgetProgram()
{
    delete ui;
}
