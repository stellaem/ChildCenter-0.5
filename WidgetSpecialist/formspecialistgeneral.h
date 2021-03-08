#ifndef FORMSPECIALISTGENERAL_H
#define FORMSPECIALISTGENERAL_H

#include <QWidget>
#include "persons/Specialist.h"

namespace Ui {
class FormSpecialistGeneral;
}

class FormSpecialistGeneral : public QWidget
{
    Q_OBJECT

public:
    explicit FormSpecialistGeneral(QWidget *parent = nullptr);

    void setSpParam(QString login);


    ~FormSpecialistGeneral();

private slots:
    void on_pushButton_clientList_clicked();

private:
    Ui::FormSpecialistGeneral *ui;
    Specialist *sp;
};

#endif // FORMSPECIALISTGENERAL_H
