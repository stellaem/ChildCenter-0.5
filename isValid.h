#ifndef ISVALID_H
#define ISVALID_H

#include <QSqlError>
#include <QSqlQuery>
#include <QString>


bool loginIsValid(QString login)
{
    QSqlQuery q;
    q.prepare("select login from authorization where login = :login");
    q.bindValue(":login",login);
    if ( q.exec())
    {
        if (q.next())
        {
            return true;
        }
        else
        {
            qDebug() << QString("логин не существует");
            return false;
        }
    }
    else
    {
        qCritical() << "cannot execute query";
        QSqlError Err = q.lastError();
        qCritical() << Err.nativeErrorCode();
        qCritical() << Err.databaseText();
        qCritical() << Err.driverText();
        qCritical() << q.executedQuery();
    return false;
    }
}

#endif // ISVALID_H
