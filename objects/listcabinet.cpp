#include "listcabinet.h"
#include <QSqlQuery>
#include "objects/cabinet.h"

ListCabinet::ListCabinet(QObject *parent) : QObject(parent)
{
    m_www = 1;

//    QSqlQuery query = QSqlQuery();
//    query.exec("select id, name from cabinet");
//    while (query.next())
//    {
//        Cabinet *cabinet = new Cabinet(query.value("id").toInt(), query.value("name").toString());
//        QVariant var = QVariant();
//        var.setValue(cabinet);
//        m_listCabinet.append(var);
//    }
}
