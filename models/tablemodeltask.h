#ifndef TABLEMODELTASK_H
#define TABLEMODELTASK_H

#include <QSqlTableModel>
#include <QDate>

class TableModelTask : public QSqlTableModel
{
public:
    TableModelTask();
    void setDate(QDate date);
};

#endif // TABLEMODELTASK_H
