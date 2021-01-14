//
// Created by marco on 23/10/20.
//

#include "file_h/Event.h"

const QString &Event::getTask() const {
    return task;
}

void Event::setTask(const QString &task) {
    if (task=="")
        Event::task="Evento";
    else
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
    if (endTime<=Event::startTime) {
      QTime eTime=startTime.addSecs(3600);
        Event::endTime = eTime;
    }
    else
    Event::endTime = endTime;
}

const QString &Event::getNote() const {
    return note;
}

void Event::setNote(const QString &note) {
    Event::note = note;
}

bool Event::operator==(const Event &compareEvent)const {
    if (this->getTask() == compareEvent.getTask() &&
        this->getDate() == compareEvent.getDate() &&
        this->getNote() == compareEvent.getNote() &&
        this->getEndTime() == compareEvent.getEndTime() &&
        this->getStartTime() == compareEvent.getStartTime())
        return true;

    else
        return false;
}
