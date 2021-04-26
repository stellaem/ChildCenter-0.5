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
    QLineEdit *editLogin;
    QLineEdit *editPassword;
    QComboBox *editRole;
    Ui::DialogEnter *ui;

public:
    explicit DialogEnter(QWidget *parent = nullptr);


    QString getLogin() {return editLogin->text();};
    QString getPassword() {return editPassword->text();}
    QString getRole() {return editRole->currentText();};



    ~DialogEnter();


};

#endif // DIALOGENTER_H
