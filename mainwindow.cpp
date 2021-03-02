#include <QSqlQuery>
#include <QSqlError>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "User.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , user(new User)


{
    ui->setupUi(this);
}
/*------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------*/
MainWindow::~MainWindow()
{
    delete ui;
}



