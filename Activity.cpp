//
// Created by tommaso on 23/10/20.
//

#include "Activity.h"

//TODO aggiungere definizioni

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
    return <#initializer#>;
}


void Activity::addsubActivity(SubActivity *subActivity) {

}

void Activity::removeSubActivity(SubActivity *subActivity) {

}

void Activity::addObserver(Observer *o) {

}

void Activity::removeObserver(Observer *o) {

}

void Activity::notify() {

}

