#include "windowdev.h"
#include "ui_windowdev.h"

WindowDev::WindowDev(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowDev)
{
    ui->setupUi(this);
}

WindowDev::~WindowDev()
{
    delete ui;
}
