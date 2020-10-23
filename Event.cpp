//
// Created by marco on 23/10/20.
//

#include "Event.h"

const QString &Event::getTask() const {
    return task;
}

void Event::setTask(const QString &task) {
    Event::task = task;
}

const QDate &Event::getDate() const {
    return date;
}

void Event::setDate(const QDate &date) {
    Event::date = date;
}

bool Event::isAllDay() const {
    return allDay;
}

void Event::setAllDay(bool allDay) {
    Event::allDay = allDay;
}

const QTime &Event::getStartTime() const {
    return startTime;
}

void Event::setStartTime(const QTime &startTime) {
    Event::startTime = startTime;
}

const QTime &Event::getEndTime() const {
    return endTime;
}

void Event::setEndTime(const QTime &endTime) {
    Event::endTime = endTime;
}

const QString &Event::getNote() const {
    return note;
}

void Event::setNote(const QString &note) {
    Event::note = note;
}
