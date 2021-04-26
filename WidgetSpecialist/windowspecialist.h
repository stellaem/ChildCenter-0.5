#ifndef WINDOWSPECIALIST_H
#define WINDOWSPECIALIST_H

#include <QMainWindow>

#include <persons/Specialist.h>

#include "widgetclientbase.h"
#include "widgettimetable.h"
#include "widgetstatistic.h"
#include "widgetprogram.h"

namespace Ui {
class WindowSpecialist;
}

class WindowSpecialist : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowSpecialist(QWidget *parent = nullptr);
    void setSpParam(QString login);
    ~WindowSpecialist();

private slots:
    void on_pushButton_clientBase_clicked();
    void on_pushButton_timetable_clicked();
    void on_pushButton_statistic_clicked();
    void on_pushButton_program_clicked();

    void on_actionOnStarter_triggered();

private:
    Ui::WindowSpecialist *ui;
    Specialist *sp;
    WidgetClientBase *wClientBase;
    WidgetTimetable *wTimetable;
    WidgetStatistic *wStatistic;
    WidgetProgram *wProgram;
    QWidget *wStarter;
};

#endif // WINDOWSPECIALIST_H
