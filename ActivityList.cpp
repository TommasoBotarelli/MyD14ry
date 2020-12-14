//
// Created by Tommaso on 24/10/2020.
//

#include "ActivityList.h"

void ActivityList::getActivity(std::list<Activity> &actList) {         //FIXME
    for (auto i : activities) {
        actList.push_back(i);
    }
}

void ActivityList::addActivity(Activity &activity) {
    activities.push_back(activity);

    notify();
}

void ActivityList::removeActivity(const Activity &activity) {
    for (auto i = activities.begin(); i != activities.end(); i++) {
        if (*i == activity) {
            activities.remove(activity);
            break;
        }
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

void ActivityList::getListOfDay(QDate date, std::list<Activity> &dayList) {     //FIXME
    for (auto i : activities) {
        if (i.getDate() == date)
            dayList.push_back(i);
    }
}

ActivityList::~ActivityList() {
    activities.clear();

    for (auto i : observers)
        i->detach();
}
