#include "widgettimetable.h"
#include "ui_widgettimetable.h"

WidgetTimetable::WidgetTimetable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetTimetable)
{
    ui->setupUi(this);
}

WidgetTimetable::~WidgetTimetable()
{
    delete ui;
}
