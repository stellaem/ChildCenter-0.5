#pragma once
#include <QDate>
#include <QString>

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
