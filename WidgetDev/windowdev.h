#ifndef WINDOWDEV_H
#define WINDOWDEV_H

#include <QMainWindow>

namespace Ui {
class WindowDev;
}

class WindowDev : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowDev(QWidget *parent = nullptr);
    ~WindowDev();

private:
    Ui::WindowDev *ui;
};

#endif // WINDOWDEV_H
