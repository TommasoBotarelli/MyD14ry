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

        auto i = activities.begin();

        while (i != activities.end()) {

            if (&(**i) == activity) {
                //activities.erase(i);
                delete activity;
            }

            i = std::next(i, 1);
        }
        notify();
    }
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

std::list<Activity *> &ActivityList::getListOfDay(QDate date) {
    auto list = new std::list<Activity *>;

    for (auto i : activities) {
        if (i->getDate() == date)
            list->push_back(i);
    }

    return *list;
}

ActivityList::~ActivityList() {
    activities.clear();

    for (auto i : observers)
        i->detach();
}
