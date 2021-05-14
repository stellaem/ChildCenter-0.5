#pragma once
#include <QList>
#include <QObject>
#include <QString>
#include <QVariant>

class Cabinet: public QObject
{
    Q_OBJECT
public:
    Cabinet(QObject *parent = nullptr){};
    Cabinet(int m_id, QString m_name, QObject *parent = nullptr){};

    Q_PROPERTY(int id   WRITE   setId
                        READ    getId
                        NOTIFY  idChanged)

    Q_PROPERTY(QString name WRITE setName
                            READ getName
                            NOTIFY nameChanged)
    Q_INVOKABLE int getId() const;
    QString getName() const;

    virtual ~Cabinet(){};

private:
    QString m_name;
    int m_id;

public slots:
    void setId(int id);
    void setName(QString name);

signals:
    void idChanged(int id);
    void nameChanged(QString name);
};




Q_DECLARE_METATYPE( Cabinet )

