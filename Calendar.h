//
// Created by marco on 24/10/20.
//

#ifndef MYD14RY_CALENDAR_H
#define MYD14RY_CALENDAR_H

#include "Subject.h"
#include <QDate>
#include <list>
#include "Event.h"
#include <memory>
#include "Observer.h"

class Calendar : public Subject{
public:

    void addEvent(Event *event);

    void removeEvent(Event *event);

    void removeObserver(Observer *o) override;

    void addObserver(Observer *o) override;

    void getListOfDay(QDate date, std::list<Event*>& l);

    void notify() const override;

    std::list<Event*> Events;

    std::list<Observer *> observers;

};


#endif //MYD14RY_CALENDAR_H
