#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

#include "mainwindow.h"
#include "DialogEnter/dialogenter.h"
#include "User.h"
#include "isValid.h"
#include "formspecialistgeneral.h"


bool loginIsValid(QString login);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("sql/db.sqlite");
    db.open();

    DialogEnter d = DialogEnter();
    MainWindow w;

    if (d.exec() == QDialog::Accepted)
    {
        if(loginIsValid(d.login()))
        {
            w.setUserLogin(d.login());
            w.setUserPosition(1);
            if (w.userPosition() ==1)
            {
                FormSpecialistGeneral *generalWidget = new FormSpecialistGeneral();
                w.setCentralWidget(generalWidget);
            }
            w.show();
        }
        else return 0;
    }
    else return 0;

    return a.exec();
}


