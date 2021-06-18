#pragma once

#include <QPixmap>
#include <QString>
#include <QDate>

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
