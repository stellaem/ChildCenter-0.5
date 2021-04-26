#pragma once
#include <QDate>
#include <QPixmap>
#include <QList>
#include "Person.h"
class Recommendation;
class Request;

class Client : virtual public Person
{
public:
	Client() : Person() {};
	virtual ~Client() {};
private:
    int numCard;
    QDate firstConsult;
    QPixmap questionnaire;
    QPixmap contract;
    QList <QPixmap> listSurvey;
    QList <Request> listRequest;
    QList <Recommendation> listRecommendation;

};

class Recommendation
{
public:
	Recommendation() {};
	virtual ~Recommendation() {};
private:
    int id;
    int idClient;
    int type;
    QString text;
    QDate date;
    bool isActual;
};

class Request
{
public:
	Request() {};
	virtual ~Request() {};
private:
    int id;
    int idClient;
    QString internalCode;
    QString complaint;
    QString goal;
    QString note;
    bool completed;
    QDate start;
    QDate end;
};

