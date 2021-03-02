#ifndef DIALOGENTER_H
#define DIALOGENTER_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class DialogEnter;
}

class DialogEnter : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEnter(QWidget *parent = nullptr);
    ~DialogEnter();

    QString login() {return edit_login->text();};

private:
    QLineEdit *edit_login;
    Ui::DialogEnter *ui;

};

#endif // DIALOGENTER_H
