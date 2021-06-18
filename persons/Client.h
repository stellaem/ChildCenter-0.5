#pragma once

#include <QObject>
#include <QDate>
#include <QPixmap>
#include <QList>

#include "objects/Note.h"
#include "objects/recommendation.h"
#include "objects/request.h"

class Client: public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId CONSTANT)
    Q_PROPERTY(int numCard READ getNumCard CONSTANT)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QDate birthday READ getBirthday WRITE setBirthday NOTIFY birthdayChanged)
public:
    Client(int id, QObject *parent = nullptr);
    virtual ~Client() {};
    int getId() const;
    int getNumCard() const;
    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getPatronymic() const;
    void setPatronymic(const QString &newPatronymic);
    const QString &getSurname() const;
    void setSurname(const QString &newSurname);
    const QDate &getBirthday() const;
    void setBirthday(const QDate &newBirthday);

signals:
    void nameChanged();
    void patronymicChanged();
    void surnameChanged();
    void birthdayChanged();

private:
    int id;
    int numCard;

    QString name;
    QString patronymic;
    QString surname;
    QDate birthday;
    QPixmap photo;

    QDate firstConsult;
    Note note;

    QPixmap questionnaire;
    QPixmap contract;

    QList <QPixmap> listSurvey;
    QList <Request> listRequest;
    QList <Recommendation> listRecommendation;

};

Q_DECLARE_METATYPE( Client )


