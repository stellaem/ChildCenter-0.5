#include "cabinet.h"
#include <QSqlQuery>
#include <QVariant>





// правильный вариант qvariant_cast<Cabinet*>(listCabinet[0])->getId()


int Cabinet::getId() const { return m_id; }

QString Cabinet::getName() const { return m_name; }

void Cabinet::setId(int id)
{
    if (m_id == id) return;
    m_id = id;
    emit idChanged(m_id);
}

void Cabinet::setName(QString name)
{
    if (m_name == name) return;
    m_name = name;
    emit nameChanged(m_name);
}
