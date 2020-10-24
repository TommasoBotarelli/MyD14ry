//
// Created by marco on 24/10/20.
//

#include "Calendar.h"


void Calendar::addEvent(std::unique_ptr<Event> event) {
    if(event!= nullptr)
        Events.push_back(std::move(event));
    notify();
}

void Calendar::removeEvent(std::unique_ptr<Event> event) {
    if(event!= nullptr)
        Events.remove(event);
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

std::list<Event*> Calendar::getListOfDay(QDate date) {
    std::list<Event *> list;

    for(auto i= Events.begin();i!=Events.end();i++){
        if((*i)->getDate()==date)
            list.push_back(i->get());
    }
    return list;
}
