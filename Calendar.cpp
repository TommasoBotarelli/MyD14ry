//
// Created by marco on 24/10/20.
//

#include "Calendar.h"


void Calendar::addEvent(Event *event) {
    if(event!= nullptr)
        Events.push_back(event);
    notify();
}

std::list<Event *> Calendar::getEvent() {
    std::list<Event *> list;

    for (auto i = Events.begin(); i != Events.end(); ++i)
        list.push_back(*i);

    return list;
}

void Calendar::removeEvent(Event *event) {
    if(event!= nullptr){
        Events.remove(event);
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

void Calendar::getListOfDay(QDate date, std::list<Event *> &l) {
    for (auto i : l) {
        if ((*i).getDate() == date)
            l.push_back(i);
    }
}

