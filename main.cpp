#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

#include "mianwindow.h"
#include "DialogEnter/dialogenter.h"
#include "loginIsValid.h"
#include "WidgetSpecialist/formspecialistgeneral.h"
#include "WidgetAdministrator/formadministratorgeneral.h"
#include "WidgetDev/formdevgeneral.h"


bool loginIsValid(QString login);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("sql/db.sqlite");
    db.open();

    DialogEnter d = DialogEnter();
    MainWindow win = MainWindow();

    if (d.exec() == QDialog::Accepted)
    {
        if (d.role() == QString("specialist") && loginIsValid(d.role(), d.login(), d.password()))
        {
            FormSpecialistGeneral *gWid = new FormSpecialistGeneral();
            gWid->setSpParam(d.login());
            win.setCentralWidget(gWid);
            win.show();
        }
        else if(d.role() == QString("administrator") && loginIsValid(d.role(), d.login(), d.password()))
        {
            FormAdministratorGeneral *gWid = new FormAdministratorGeneral();
            gWid->setAdminParam(d.login());
            win.setCentralWidget(gWid);
            win.show();
        }
        else if(d.role() == QString("program developer") && loginIsValid(d.role(), d.login(), d.password()))
        {
            FormDevGeneral *gWid = new FormDevGeneral();
            win.setCentralWidget(gWid);
            win.show();
        }
        else return 0;
    }
    else return 0;

    return a.exec();
}


