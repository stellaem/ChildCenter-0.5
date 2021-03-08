#pragma once
#include <QObject>
#include <QString>
#include <QDate>
#include <QPixmap>
#include "Note.h"


class Person
{
protected:
	Person() {};
public:
    int id() { return i_id; };
	QString name() { return s_name; };
	QString patronymic() { return s_patronymic; };
	QString surname() { return s_surname; };
	QDate birthday() { return d_birthday; };
	QPixmap photo() { return p_photo; };
	Note note() { return no_note; };
    QString login() { return s_login; };
    QString password() { return s_password; };

    void setId(int value){ i_id = value; }
    void setName(const QString &value) { s_name = value; };
    void setPatronymic(const QString &value) {s_patronymic = value; }
    void setSurname(const QString &value) {s_surname = value; };
    void setBirthday(const QDate &value) {d_birthday = value; };
    void setPhoto(const QPixmap &value){ p_photo = value; };
    void setNote(const Note &value){ no_note = value; };
    void setLogin(const QString &value) { s_login = value; }
    void setPassword(const QString &value) { s_password = value; }

    virtual ~Person() {};

private:
    int i_id;
    QString s_login;
    QString s_password;
    QString s_name;
    QString s_patronymic;
	QString s_surname;
	QDate d_birthday;
	QPixmap p_photo;
	Note no_note;
};

