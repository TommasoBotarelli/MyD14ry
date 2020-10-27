//
// Created by Tommaso on 24/10/2020.
//

#include "ActivityList.h"

std::list<Activity *> ActivityList::getActivity() {
    std::list<Activity *> list;

    for (auto i = activities.begin(); i != activities.end(); ++i)
        list.push_back(*i);

    return list;
}

void ActivityList::addActivity(Activity *activity) {
    if (activity != nullptr) {
        activities.push_back(activity);
    }
    notify();
}

void ActivityList::removeActivity(Activity *activity) {
    if (activity != nullptr) {
        activities.remove(activity);
    }
    notify();
}

void ActivityList::addObserver(Observer *o) {
    observers.push_back(o);
}

void ActivityList::removeObserver(Observer *o) {
    observers.remove(o);
}

void ActivityList::notify() const {
    for (auto i : observers)
        (*i).update();
}

void ActivityList::getListOfDay(QDate date, std::list <Activity*>& l) {
    for (auto i : l) {
        if ((*i).getDate() == date)
            l.push_back(i);
    }
}

ActivityList::~ActivityList() {
    activities.clear();

    for (auto i : observers)
        i->detach();
}
