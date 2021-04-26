#ifndef WIDGETCLIENTBASE_H
#define WIDGETCLIENTBASE_H

#include <QWidget>

namespace Ui {
class WidgetClientBase;
}

class WidgetClientBase : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetClientBase(QWidget *parent = nullptr);
    ~WidgetClientBase();

private:
    Ui::WidgetClientBase *ui;
};

#endif // WIDGETCLIENTBASE_H
