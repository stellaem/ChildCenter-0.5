#ifndef FORMDEVGENERAL_H
#define FORMDEVGENERAL_H

#include <QWidget>

namespace Ui {
class FormDevGeneral;
}

class FormDevGeneral : public QWidget
{
    Q_OBJECT

public:
    explicit FormDevGeneral(QWidget *parent = nullptr);
    ~FormDevGeneral();

private:
    Ui::FormDevGeneral *ui;
};

#endif // FORMDEVGENERAL_H
