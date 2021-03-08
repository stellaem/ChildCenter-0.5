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
	int n_numCard;
	QDate d_firstConsult;
	QPixmap p_questionnaire;
	QPixmap p_contract;
	QList <QPixmap> l_survey;
	QList <Request> l_request;
    QList <Recommendation> l_recommendation;

};

class Recommendation
{
public:
	Recommendation() {};
	virtual ~Recommendation() {};
private:
	int i_id;
	int i_id_client;
	int i_type;
	QString s_text;
	QDate d_date;
	bool is_actual;
};

class Request
{
public:
	Request() {};
	virtual ~Request() {};
private:
	int i_id;
	int i_id_client;
	QString s_internalCode;
	QString s_complaint;
	QString s_goal;
	QString s_note;
	bool is_completed;
	QDate d_start;
	QDate d_end;
};

