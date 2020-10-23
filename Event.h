//
// Created by marco on 23/10/20.
//

#ifndef MYD14RY_EVENT_H
#define MYD14RY_EVENT_H
#include <QString>
#include <QDate>
#include <QTime>

class Event {
public:
    const QString &getTask() const;

    void setTask(const QString &task);

    const QDate &getDate() const;

    void setDate(const QDate &date);

    void setStartTime(const Qtime &starTime);

    void setEndTime(const Qtime &endTime);

    const Qtime &getStartTime() const;

    const Qtime &getEndTime() const;

    void setAllDay(bool allDay);

    const bool &getAllDay() const;

    void setNote(const Qstring &note);

    const Qstring &getNote() const;

private:
    Qstring task;

    Qstring note;

    bool allDay;

    Qdate date;

    Qtime startTime;

    Qtime endTime;

};


#endif //MYD14RY_EVENT_H
