//
// Created by marco on 24/10/20.
//

#include "Calendar.h"


void Calendar::addEvent(Event &event) {
    Events.push_back(event);
    notify();
}

void Calendar::getEvent(std::list<Event> &list) {
    for (auto &i : Events)
        list.push_back(i);
}

void Calendar::removeEvent(Event &event) {
    for (auto &i : Events) {
        if (i == event) {
            Events.remove(event);
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

void Calendar::getListOfDay(QDate date, std::list<Event> &eList) {
    for (auto &i : Events)
        if (i.getDate() == date)
            eList.push_back(i);

}


