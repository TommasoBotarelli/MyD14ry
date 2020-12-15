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

    bool isAllDay() const;

    void setAllDay(bool allDay);

    const QTime &getStartTime() const;

    void setStartTime(const QTime &startTime);

    const QTime &getEndTime() const;

    void setEndTime(const QTime &endTime);

    const QString &getNote() const;

    void setNote(const QString &note);

    bool operator==(const Event &compareEvent);

private:
    QString task;

    QDate date;

    bool allDay;

    QTime startTime;

    QTime endTime;

    QString note;

};


#endif //MYD14RY_EVENT_H
