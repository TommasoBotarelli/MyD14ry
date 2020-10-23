//
// Created by tommaso on 23/10/20.
//

#include "Activity.h"


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

std::list<SubActivity *> &Activity::getSubActivities() {
    std::list<SubActivity *> list;

    for (auto i : Activity::subActivities)
        list.push_back((*i)->get());

    return &list;
}


void Activity::addsubActivity(SubActivity &subActivity) {
    std::unique_ptr<SubActivity> subA = std::make_unique(subActivity);  //FIXME controllare se la sintassi è giusta
    subActivities.push_back(subA);
}

void Activity::addObserver(Observer *o) {
    observers.push_back(o);
}

void Activity::removeObserver(Observer *o) {
    observers.remove(o);
}

void Activity::notify() const {
    for (auto i : observers)
        (*i)->update();
}


