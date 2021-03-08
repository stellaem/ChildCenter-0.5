#ifndef FORMADMINISTRATORGENERAL_H
#define FORMADMINISTRATORGENERAL_H

#include <QWidget>
#include "persons/Administrator.h"

namespace Ui {
class FormAdministratorGeneral;
}

class FormAdministratorGeneral : public QWidget
{
    Q_OBJECT

public:
    explicit FormAdministratorGeneral(QWidget *parent = nullptr);
    void setAdminParam(QString login);
    ~FormAdministratorGeneral();

private:
    Ui::FormAdministratorGeneral *ui;
    Administrator *admin;
};

#endif // FORMADMINISTRATORGENERAL_H
