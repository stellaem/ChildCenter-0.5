#include "widgetclientbase.h"
#include "ui_widgetclientbase.h"

WidgetClientBase::WidgetClientBase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetClientBase)
{
    ui->setupUi(this);
}

WidgetClientBase::~WidgetClientBase()
{
    delete ui;
}
