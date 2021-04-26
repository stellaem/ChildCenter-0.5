#pragma once

#include <QList>
#include "Person.h"

class Qualification;

class Specialist : virtual public Person // name, patronymic, surname, birthday, photo, note
{
public:
	Specialist() : Person() {};

    void setQualification(const QList<Qualification> & value) { listQualification = value; };
	virtual ~Specialist() {};

    QList<Qualification> getQualification() const{ return listQualification; };

    int getId() const{ return id; };
    void setId(int value){ id = value; }
;

private:
    int id;
    QList<Qualification> listQualification;
};

class Qualification
{
public:
    Qualification() {};
    virtual ~Qualification() {};
private:
    QString name;
    QPixmap document;
    QDate confirm;
};

