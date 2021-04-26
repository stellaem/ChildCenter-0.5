#ifndef LOGINISVALID_H
#define LOGINISVALID_H

#include <QSqlError>
#include <QSqlQuery>
#include <QString>

bool loginIsValid(QString role, QString login, QString password )
{

    QSqlQuery q;
    if (role == QString("specialist"))
    {
        // TODO обратить внимание нужно ли в запросе указывать поле is_dev !!!
        q.prepare("select login from specialist where login = ? and password = ?");
        q.addBindValue(login);
        q.addBindValue(password);
    }
    else if (role == QString("administrator"))
    {
        q.prepare("select login from administrator where login = ? and password = ?");
        q.addBindValue(login);
        q.addBindValue(password);
    }
    else
    {
        q.prepare("select login from specialist where login = ? and password = ? and is_dev = 1");
        q.addBindValue(login);
        q.addBindValue(password);
    }

    if (q.exec() and q.next()) return true;
    return false;
}

#endif // LOGINISVALID_H
