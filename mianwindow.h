#ifndef MIANWINDOW_H
#define MIANWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDebug>
#include "DialogEnter/dialogenter.h"
#include "persons/Specialist.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;

};
#endif // MIANWINDOW_H
