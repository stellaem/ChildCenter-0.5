#ifndef CELLTIMETABLE_H
#define CELLTIMETABLE_H
#include <QDateTime>
#include <persons/Specialist.h>

class CellTimetable
{
public:
    CellTimetable() { }

    QDateTime getDateTimeStart() const { return dateAndTimeStart; }
    void setDateTimeStart(const QDateTime &value) { dateAndTimeStart = value; }

    QDateTime getDateTimeEnd()const { return dateAndTimeStart.addSecs(duration*60); }

    int getDuration() const { return duration; } // in minuts
    void setDuration(int value) { duration = value; } // in minuts


    int getIdSp() const { return idSp; }
    void setIdSp(int value) { idSp = value; }

    bool getIsNotEmpty() const { return isNotEmpty; }
    void setIsNotEmpty(bool value) { isNotEmpty = value; }

    QTime timeStart() { return dateAndTimeStart.time(); };
    QTime timeEnd() { return dateAndTimeStart.time().addSecs(duration*60); };

    ~CellTimetable() {};

private:
    QDateTime dateAndTimeStart;
    int duration; // in minuts
    int idSp;
    bool isNotEmpty;
};



#endif // CELLTIMETABLE_H
