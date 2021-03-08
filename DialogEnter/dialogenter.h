#ifndef DIALOGENTER_H
#define DIALOGENTER_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>

namespace Ui {
class DialogEnter;
}

class DialogEnter : public QDialog
{
    Q_OBJECT
private:
    QLineEdit *edit_login;
    QLineEdit *edit_password;
    QComboBox *edit_role;
    Ui::DialogEnter *ui;

public:
    explicit DialogEnter(QWidget *parent = nullptr);


    QString login() {return edit_login->text();};
    QString password() {return edit_password->text();}
    QString role() {return edit_role->currentText();};



    ~DialogEnter();


};

#endif // DIALOGENTER_H
