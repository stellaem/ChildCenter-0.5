#include "cellclass.h"
#include <QSqlQuery>

#include "persons/Client.h"

/**************************************************************************************************/
CellClass::CellClass(int id, QObject *parent) : QObject(parent), id(id)
{
    searchFromClassClient();
}
/*------------------------------------------------------------------------------------------------*/
void CellClass::searchFromClassClient()
{
    QSqlQuery q = QSqlQuery();
    q.prepare("select id_client from class_client where id_class = :id_class");
    q.bindValue(":id_class", id);
    q.exec();
    while(q.next())
    {
        addToListVClient(q.value("id_client").toInt());
    }
}
/*------------------------------------------------------------------------------------------------*/
void CellClass::addToListVClient(int id_client)
{
    Client *c = new Client(id_client);
    QVariant var = QVariant::fromValue(c);
    listVClient.append(var);
}
/*------------------------------------------------------------------------------------------------*/
int CellClass::getId() const
{
    return id;
}
/*------------------------------------------------------------------------------------------------*/
void CellClass::setId(int newId)
{
    if (id == newId)
        return;
    id = newId;
    emit idChanged();
}
/*------------------------------------------------------------------------------------------------*/
int CellClass::getIdType() const
{
    return idType;
}
/*------------------------------------------------------------------------------------------------*/
void CellClass::setIdType(int newIdType)
{
    if (idType == newIdType)
        return;
    idType = newIdType;
    emit idTypeChanged();
}
/*------------------------------------------------------------------------------------------------*/
const QDateTime &CellClass::getDateAndTimeStart() const
{
    return dateAndTimeStart;
}
/*------------------------------------------------------------------------------------------------*/
void CellClass::setDateAndTimeStart(const QDateTime &newDateAndTimeStart)
{
    if (dateAndTimeStart == newDateAndTimeStart)
        return;
    dateAndTimeStart = newDateAndTimeStart;
    emit dateAndTimeStartChanged();
}
/*------------------------------------------------------------------------------------------------*/
int CellClass::getDuration() const
{
    return duration;
}
/*------------------------------------------------------------------------------------------------*/
void CellClass::setDuration(int newDuration)
{
    if (duration == newDuration)
        return;
    duration = newDuration;
    emit durationChanged();
}
/*------------------------------------------------------------------------------------------------*/
const QList<QVariant> &CellClass::getListVClient() const
{
    return listVClient;
}
/*------------------------------------------------------------------------------------------------*/
void CellClass::setListVClient(const QList<QVariant> &newListVClient)
{
    if (listVClient == newListVClient)
        return;
    listVClient = newListVClient;
    emit listVClientChanged();
}
/*------------------------------------------------------------------------------------------------*/
Cabinet *CellClass::getCabinet() const
{
    return cabinet;
}
/*------------------------------------------------------------------------------------------------*/
void CellClass::setCabinet(Cabinet *newCabinet)
{
    if (cabinet == newCabinet)
        return;
    cabinet = newCabinet;
    emit cabinetChanged();
}
/*------------------------------------------------------------------------------------------------*/
Specialist *CellClass::getSpecialist() const
{
    return specialist;
}
/*------------------------------------------------------------------------------------------------*/
void CellClass::setSpecialist(Specialist *newSpecialist)
{
    if (specialist == newSpecialist)
        return;
    specialist = newSpecialist;
    emit specialistChanged();
}
/**************************************************************************************************/
