#ifndef WIDGETSTATISTIC_H
#define WIDGETSTATISTIC_H

#include <QWidget>

namespace Ui {
class WidgetStatistic;
}

class WidgetStatistic : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetStatistic(QWidget *parent = nullptr);
    ~WidgetStatistic();

private:
    Ui::WidgetStatistic *ui;
};

#endif // WIDGETSTATISTIC_H
