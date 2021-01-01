//
// Created by tommaso on 23/10/20.
//

#include "Activity.h"


const QString &Activity::getTask() const {
    return task;
}

void Activity::setTask(const QString &task) {
    if (task == "")
        Activity::task = "Attività";
    else
        Activity::task = task;
}

const QDate &Activity::getDeadlineDate() const {
    return deadlineDate;
}

void Activity::setDeadlineDate(const QDate &deadDate) {
    deadlineDate = deadDate;
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

void Activity::getSubActivities(std::list<SubActivity> &subAList) {   //FIXME
    for (auto i : subActivities) {
        subAList.push_back(i);
    }
}

void Activity::addSubActivity(SubActivity &subActivity) {

    subActivities.push_back(subActivity);

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
    subActivities.clear();
}

bool Activity::operator==(const Activity &activity)const {

    if (activity.isCompleted() == this->isCompleted() &&
        activity.getTask() == this->getTask() &&
        activity.getNote() == this->getNote() &&
        activity.getDeadlineDate() == this->getDeadlineDate() &&
        activity.getCount() == this->getCount())
        return true;

    else
        return false;
}

const QString &Activity::getCategory() const {
    return category;
}

void Activity::setCategory(const QString &category) {
    Activity::category = category;
}

int Activity::getCount() const {
    return count;
}

void Activity::setCount(int count) {
    Activity::count = count;
}




