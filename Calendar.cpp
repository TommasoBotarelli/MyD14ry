//
// Created by marco on 24/10/20.
//

#include "Calendar.h"


void Calendar::addEvent(std::shared_ptr<Event> event) {
    Events.push_back(event);
    notify();
}

void Calendar::getEvent(std::list<std::shared_ptr<Event>> &list) {
    for (const auto &i : Events)
        list.push_back(i);
}

void Calendar::removeEvent(std::shared_ptr<Event> event) {
    for (auto i : Events) {
        if (i == event) {
            Events.remove(event);
            event.reset();
            break;
        }
    }
    notify();
}

void Calendar::addObserver(Observer *o) {
    observers.push_back(o);
}

void Calendar::removeObserver(Observer *o) {
    observers.remove(o);
}

void Calendar::notify() const {
    for (auto i : observers)
        (*i).update();
}

void Calendar::getListOfDay(QDate date, std::list<std::shared_ptr<Event>> &eList) {
    for (const auto &i : Events)
        if (i->getDate() == date)
            eList.push_back(i);
}


