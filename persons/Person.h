#pragma once
#include <QObject>
#include <QString>
#include <QDate>
#include <QPixmap>
#include "objects/Note.h"


class Person
{
protected:
	Person() {};
public:
    int getId() { return id; };
    QString getName() { return name; };
    QString getPatronymic() { return patronymic; };
    QString getSurname() { return surname; };
    QDate getBirthday() { return birthday; };
    QPixmap getPhoto() { return photo; };
    Note getNote() { return note; };
    QString getLogin() { return login; };
    QString getPassword() { return password; };

    void setId(int value){ id = value; }
    void setName(const QString &value) { name = value; };
    void setPatronymic(const QString &value) {patronymic = value; }
    void setSurname(const QString &value) {surname = value; };
    void setBirthday(const QDate &value) {birthday = value; };
    void setPhoto(const QPixmap &value){ photo = value; };
    void setNote(const Note &value){ note = value; };
    void setLogin(const QString &value) { login = value; }
    void setPassword(const QString &value) { password = value; }

    virtual ~Person() {};

private:
    int id;
    QString login;
    QString password;
    QString name;
    QString patronymic;
    QString surname;
    QDate birthday;
    QPixmap photo;
    Note note;
};

