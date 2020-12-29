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
#include <utility>
#include "Observer.h"
#include "SubActivity.h"


class Activity : public Subject {

public:

    Activity() = default;

    const QString &getTask() const;

    void setTask(const QString &task);

    const QDate &getDeadlineDate() const;

    void setDeadlineDate(const QDate &deadlineDate);

    bool isCompleted() const;

    void setCompleted(bool completed);

    const QString &getNote() const;

    void setNote(const QString &note);

    void getSubActivities(std::list<SubActivity> &subAList);

    void addSubActivity(SubActivity &subActivity);

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() const override;

    ~Activity() override;

    bool operator==(const Activity &activity)const;

private:
    QString task;
    QDate deadlineDate;
    bool completed;
    QString note;
    std::list<SubActivity> subActivities;
    std::list<Observer *> observers;
};


#endif //MYD14RY_ACTIVITY_H
