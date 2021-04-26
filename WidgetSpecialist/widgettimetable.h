#ifndef WIDGETTIMETABLE_H
#define WIDGETTIMETABLE_H

#include <QWidget>

namespace Ui {
class WidgetTimetable;
}

class WidgetTimetable : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetTimetable(QWidget *parent = nullptr);
    ~WidgetTimetable();

private:
    Ui::WidgetTimetable *ui;
};

#endif // WIDGETTIMETABLE_H
