#include "tablemodeltask.h"

TableModelTask::TableModelTask()
{
    setTable("adm_task");
}

void TableModelTask::setDate(QDate date)
{
    setFilter(QString("DATE(datetime_plan) = '%1'").arg(date.toString("yyyy-MM-dd")));
    select();
}
