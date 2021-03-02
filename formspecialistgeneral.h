#ifndef FORMSPECIALISTGENERAL_H
#define FORMSPECIALISTGENERAL_H

#include <QWidget>

namespace Ui {
class FormSpecialistGeneral;
}

class FormSpecialistGeneral : public QWidget
{
    Q_OBJECT

public:
    explicit FormSpecialistGeneral(QWidget *parent = nullptr);
    ~FormSpecialistGeneral();

private:
    Ui::FormSpecialistGeneral *ui;
};

#endif // FORMSPECIALISTGENERAL_H
