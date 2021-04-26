#ifndef WIDGETPROGRAM_H
#define WIDGETPROGRAM_H

#include <QWidget>

namespace Ui {
class WidgetProgram;
}

class WidgetProgram : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetProgram(QWidget *parent = nullptr);
    ~WidgetProgram();

private:
    Ui::WidgetProgram *ui;
};

#endif // WIDGETPROGRAM_H
