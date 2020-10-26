//
// Created by tommaso on 23/10/20.
//

#include "Activity.h"
#include <memory>


const QString &Activity::getTask() const {
    return task;
}

void Activity::setTask(const QString &task) {
    Activity::task = task;
}

const QDate &Activity::getDate() const {
    return date;
}

void Activity::setDate(const QDate &date) {
    Activity::date = date;
}

const QDate &Activity::getDeadlineDate() const {
    return deadlineDate;
}

void Activity::setDeadlineDate(const QDate &deadlineDate) {
    Activity::deadlineDate = deadlineDate;
}

bool Activity::isCompleted() const {
    return completed;
}

void Activity::setCompleted(bool completed) {
    Activity::completed = completed;
}

const QString &Activity::getNote() const {
    return note;
}

void Activity::setNote(const QString &note) {
    Activity::note = note;
}

std::list<SubActivity *> Activity::getSubActivities() {
    std::list<SubActivity *> list;

    for (auto i = subActivities.begin(); i != subActivities.end(); ++i)
        list.push_back(i->get());

    return list;
}

void Activity::addSubActivity(SubActivity *subActivity) {
    if (subActivity != nullptr) {
        subActivities.push_back(std::make_unique<SubActivity>(*subActivity));
    }
    notify();
}

void Activity::addObserver(Observer *o) {
    observers.push_back(o);
}

void Activity::removeObserver(Observer *o) {
    observers.remove(o);
}

void Activity::notify() const {
    for (auto i : observers)
        (*i).update();
}

Activity::~Activity() {
    for (auto i : observers)
        i->detach();

    if (!subActivities.empty())
        subActivities.erase(subActivities.begin(), subActivities.end());
}



