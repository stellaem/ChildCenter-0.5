#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDebug>
#include "DialogEnter/dialogenter.h"
#include "User.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setUserLogin(QString login){user->setLogin(login);};
    void setUserPosition(int position){user->setPosition(position);};
    QString userlogin(){return user->login();};
    int userPosition(){return user->position();};



private:
    Ui::MainWindow *ui;
    User *user;

};
#endif // MAINWINDOW_H
