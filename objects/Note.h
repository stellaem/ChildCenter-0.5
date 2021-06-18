#pragma once
#include <QString>

class Note
{
public:
	Note() {};
	virtual ~Note() {};
private:
    int id;
    QString text;
};

