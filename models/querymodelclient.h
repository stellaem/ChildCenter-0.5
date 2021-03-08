#ifndef QUERYMODELCLIENT_H
#define QUERYMODELCLIENT_H

#include <QSqlQueryModel>

class QueryModelClient : public QSqlQueryModel
{
    Q_OBJECT
public:
    QueryModelClient();
};

#endif // QUERYMODELCLIENT_H
