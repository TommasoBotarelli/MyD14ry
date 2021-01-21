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

    void getSubActivities(std::list<std::shared_ptr<SubActivity>> &subAList) const;

    void addSubActivity(std::shared_ptr<SubActivity> &subActivity);

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() const override;

    ~Activity() override;

    const QString &getCategory() const;

    void setCategory(const QString &category);

    int getCount() const;

    void setCount(int count);

    bool operator==(const Activity &activity) const;

    void removeSubActivity(std::shared_ptr<SubActivity> subA);

    bool isHasDeadlineDate() const;

    void setHasDeadlineDate(bool hasDeadlineDate);

private:
    QString task;

    QDate deadlineDate;

    bool completed;

    QString note;

    std::list<std::shared_ptr<SubActivity>> subActivities;

    std::list<Observer *> observers;

    QString category;

    int count;

    bool hasDeadlineDate;
};


#endif //MYD14RY_ACTIVITY_H
