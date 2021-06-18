#pragma once
#include <QDate>
#include <QString>

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
