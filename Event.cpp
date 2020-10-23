//
// Created by marco on 23/10/20.
//

#include "Event.h"



const QString &Event::getTask() const {
    return task;
}

void Event::setTask(const QString &task) {
    Activity::task = task;
}

const QDate &Event::getDate() const {
    return date;
}

void Event::setDate(const QDate &date) {
    Event::date = date;
}

void Event::setStartTime(const int &starTime){
    Event::startTime = starTime;
}

const QDate &Event::setStartTime(const int &starTime) {
    return starTime;
}

void Event::setEndTime(const int &endTime) {
    Event::endTime = endTime;
}

const Qdate &Event::getEndTime() const {
    return endTime;
}

void Event::setAllDay(bool allDay) {
    Event::allDay= allDay;
}

const bool &Event::getAllDay() const {
    return allDay;
}

const QString &Event::getNote() const {
    return note;
}

void Event::setNote(const QString &note) {
    Event::note = note;
}