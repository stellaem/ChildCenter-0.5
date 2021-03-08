#pragma once
#include <QObject>
#include <QString>
#include <QDate>

#include "Person.h"

class Administrator : virtual public Person
{
public:
	Administrator() : Person() {};
	virtual ~Administrator() {};
};
