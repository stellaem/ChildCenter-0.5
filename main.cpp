#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QQuickWindow>
#include <QSGRendererInterface>


#include "DialogEnter/dialogenter.h"
#include "loginIsValid.h"
#include "WidgetSpecialist/windowspecialist.h"
#include "WidgetAdministrator/windowadmin.h"
#include "WidgetDev/windowdev.h"
#include "models/modelclassesincabinet.h"
#include "settings/settings.h"
#include "settings/appearance.h"

Settings *settings = new Settings;
Appearance *appearance = new Appearance;


int main(int argc, char *argv[])
{
    qmlRegisterType <ModelClassesInCabinet> ("Timetable", 1, 0, "ModelTimetable");
    QApplication a(argc, argv);
    WindowSpecialist *winS;
    WindowAdmin *winA;
    WindowDev *winD;
    QQuickWindow::setGraphicsApi(QSGRendererInterface::OpenGLRhi);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".//db.sqlite");
    db.open();
    DialogEnter d = DialogEnter();
    if (d.exec() == QDialog::Accepted)
    {
        if (d.getRole() == QString("specialist") && loginIsValid(d.getRole(), d.getLogin(), d.getPassword()))
        {
            winS = new WindowSpecialist();
            winS->setSpParam(d.getLogin());
            winS->show();
        }
        else if(d.getRole() == QString("administrator") && loginIsValid(d.getRole(), d.getLogin(), d.getPassword()))
        {
            winA = new WindowAdmin();
            winA->setAdminParam(d.getLogin());
            winA->show();
        }
        else if(d.getRole() == QString("program developer") && loginIsValid(d.getRole(), d.getLogin(), d.getPassword()))
        {
            winD = new WindowDev();
            winD->show();
        }
        else return 0;
    }
    else return 0;

    return a.exec();
}


