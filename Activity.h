//
// Created by tommaso on 23/10/20.
//

#ifndef MYD14RY_ACTIVITY_H
#define MYD14RY_ACTIVITY_H

#include <QString>
#include <QDate>
#include <QTime>
#include "Subject.h"
#include <memory>

//TODO includere subactivity e observer

class Activity : public Subject {

public:
    const QString &getTask() const;

    void setTask(const QString &task);

    const QDate &getDate() const;

    void setDate(const QDate &date);

    const QDate &getDeadlineDate() const;

    void setDeadlineDate(const QDate &deadlineDate);

    bool isCompleted() const;

    void setCompleted(bool completed);

    const QString &getNote() const;

    void setNote(const QString &note);

    std::list<SubActivity *> &getSubActivities();

    void addsubActivity(SubActivity *subActivity);

    void removeSubActivity(SubActivity *subActivity);

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() override;

private:
    QString task;
    QDate date;
    QDate deadlineDate;
    bool completed;
    QString note;
    std::list<std::unique_ptr<SubActivity>> subActivities;
    std::list<Observer *> observers;
};


#endif //MYD14RY_ACTIVITY_H
