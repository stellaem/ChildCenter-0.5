#pragma once
#include <QObject>
#include <QString>
#include <QDate>
#include "objects/Note.h"


class Administrator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString login READ getLogin WRITE setLogin NOTIFY loginChanged)
    Q_PROPERTY(QString password READ getPassword WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString patronymic READ getPatronymic WRITE setPatronymic NOTIFY patronymicChanged)
    Q_PROPERTY(QString surname READ getSurname WRITE setSurname NOTIFY surnameChanged)
    Q_PROPERTY(QDate birthday READ getBirthday WRITE setBirthday NOTIFY birthdayChanged)
public:
    Administrator(int id, QObject *parent = nullptr);;
    virtual ~Administrator() {};
    int getId() const;
    const QString &getLogin() const;
    void setLogin(const QString &newLogin);
    const QString &getPassword() const;
    void setPassword(const QString &newPassword);
    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getPatronymic() const;
    void setPatronymic(const QString &newPatronymic);
    const QString &getSurname() const;
    void setSurname(const QString &newSurname);
    const QDate &getBirthday() const;
    void setBirthday(const QDate &newBirthday);

signals:
    void loginChanged();
    void passwordChanged();
    void nameChanged();
    void patronymicChanged();
    void surnameChanged();
    void birthdayChanged();

private:
    int id;
    QString login;
    QString password;
    QString name;
    QString patronymic;
    QString surname;
    QDate birthday;
    Note note;

};
