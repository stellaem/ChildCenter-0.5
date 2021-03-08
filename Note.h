#pragma once
#include <QString>

class Note
{
public:
	Note() {};
	virtual ~Note() {};
private:
	int i_id;
	QString s_text;
};

