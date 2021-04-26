#ifndef LISTCABINET_H
#define LISTCABINET_H

#include <QObject>
#include <QDebug>

class ListCabinet : public QObject
{
    Q_OBJECT

public:
    explicit ListCabinet(QObject *parent = nullptr);
//    QList<QVariant> listCabinet() const { return m_listCabinet; };
//    void            setListCabinet(const QList<QVariant> &value){ m_listCabinet = value; };

    virtual ~ListCabinet(){};

    Q_INVOKABLE int www()  {
        qDebug() << 111;
        return m_www;  }



signals:
    void wwwChanged(int www);

private:
    int m_www;
//        Q_PROPERTY(QList<QVariant> listCabinet  WRITE    setListCabinet
//                                                READ     listCabinet
//                                                NOTIFY   listCabinetChanged)
//        Q_PROPERTY(int www  READ www NOTIFY wwwChanged)

//        QList<QVariant> m_listCabinet;







};

#endif // LISTCABINET_H
