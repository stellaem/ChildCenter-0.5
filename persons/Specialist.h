#pragma once

#include <QList>
#include "Person.h"

class Qualification;

class Specialist : virtual public Person // name, patronymic, surname, birthday, photo, note
{
public:
	Specialist() : Person() {};


    QList<Qualification> qualification() const { return l_qualification; };


    void setQualification(const QList<Qualification> & value) { l_qualification = value; };

	virtual ~Specialist() {};

private:

    QList<Qualification> l_qualification;
};


class Qualification
{
public:
    Qualification() {};
	virtual ~Qualification() {};
private:
	QString s_name;
	QPixmap p_document;
	QDate d_confirm;
};

