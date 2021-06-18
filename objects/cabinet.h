#pragma once
#include <QList>
#include <QObject>
#include <QString>
#include <QVariant>

class Cabinet: public QObject
{
    Q_OBJECT
public:
    Cabinet(int id, QObject *parent = nullptr) : QObject(parent), id(id) {}
    const QString &getName() const;
    void setName(const QString &newName);
    Q_INVOKABLE int getId() const;

signals:
    void nameChanged();

private:
    int id;
    QString name;

    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int id READ getId CONSTANT)
};




Q_DECLARE_METATYPE( Cabinet )

