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

std::list<Event*> &Calendar::getListOfDay(QDate date) {
    auto list = new std::list<Event*>;

    for (auto i : Events) {
        if (i->getDate() == date)
            list->push_back(i);
    }
    return *list;
    }


