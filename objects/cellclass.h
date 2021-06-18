#pragma once
#include <QDateTime>
#include "persons/Specialist.h"
#include "persons/Client.h"
#include "objects/cabinet.h"


class CellClass: public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(int idType READ getIdType WRITE setIdType NOTIFY idTypeChanged)
    Q_PROPERTY(QDateTime dateAndTimeStart READ getDateAndTimeStart WRITE setDateAndTimeStart NOTIFY dateAndTimeStartChanged)
    Q_PROPERTY(int duration READ getDuration WRITE setDuration NOTIFY durationChanged)
    Q_PROPERTY(QList<QVariant> listVClient READ getListVClient WRITE setListVClient NOTIFY listVClientChanged)
    Q_PROPERTY(Cabinet * cabinet READ getCabinet WRITE setCabinet NOTIFY cabinetChanged)
    Q_PROPERTY(Specialist * specialist READ getSpecialist WRITE setSpecialist NOTIFY specialistChanged)
public:
    CellClass(int id, QObject *parent = nullptr);
    ~CellClass() {};
    // getters
    int getId() const;
    int getIdType() const;
    const QDateTime &getDateAndTimeStart() const;
    int getDuration() const;
    const QList<QVariant> &getListVClient() const;
    Specialist *getSpecialist() const;
    Cabinet *getCabinet() const;
    // setters
    void setId(int newId);
    void setIdType(int newIdType);
    void setDateAndTimeStart(const QDateTime &newDateAndTimeStart);
    void setDuration(int newDuration);
    void setListVClient(const QList<QVariant> &newListVClient);
    void setCabinet(Cabinet *newCabinet);
    void setSpecialist(Specialist *newSpecialist);

signals:
    void idChanged();
    void idCabinetChanged();
    void idSpChanged();
    void idTypeChanged();
    void dateAndTimeStartChanged();
    void durationChanged();
    void listVClientChanged();
    void cabinetChanged();
    void specialistChanged();

private:
    int id;
    Cabinet *cabinet;
    Specialist *specialist;
    int idType;
    QDateTime dateAndTimeStart;
    int duration;
    QList<QVariant> listVClient;

    void searchFromClassClient();
    void addToListVClient(int id_client);
};

Q_DECLARE_METATYPE( CellClass )



