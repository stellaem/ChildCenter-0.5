#pragma once
#include <QString>

class User
{
public:
    User(){i_position = 0, s_login = QString("привет");}
    int  position() { return i_position; };
    QString login() { return s_login; };
    void setLogin(QString login) { s_login = login; }
    void setPosition(int position) { i_position = position; }
    virtual ~User(){};
private:
    int  i_position;
    QString s_login;
};

