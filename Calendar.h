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

    void addEvent(std::shared_ptr<Event> event);

    void getEvent(std::list<std::shared_ptr<Event>> &list);

    void removeEvent(std::shared_ptr<Event> event);

    void removeObserver(Observer *o) override;

    void addObserver(Observer *o) override;

    void getListOfDay(QDate date, std::list<std::shared_ptr<Event>> &eList);

    void notify() const override;

private:

    std::list<std::shared_ptr<Event>> Events;

    std::list<Observer *> observers;

};


#endif //MYD14RY_CALENDAR_H
