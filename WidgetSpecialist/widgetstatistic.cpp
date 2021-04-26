#include "widgetstatistic.h"
#include "ui_widgetstatistic.h"

WidgetStatistic::WidgetStatistic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetStatistic)
{
    ui->setupUi(this);
}

WidgetStatistic::~WidgetStatistic()
{
    delete ui;
}
