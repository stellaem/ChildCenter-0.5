#include "cabinet.h"

#include <QSqlQuery>
#include <QVariant>

/**************************************************************************************************/
const QString &Cabinet::getName() const
{
    return name;
}
/*------------------------------------------------------------------------------------------------*/
void Cabinet::setName(const QString &newName)
{
    if (name == newName)
        return;
    name = newName;
    emit nameChanged();
}
/*------------------------------------------------------------------------------------------------*/
int Cabinet::getId() const
{
    return id;
}
/**************************************************************************************************/
