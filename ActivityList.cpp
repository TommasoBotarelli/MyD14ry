//
// Created by Tommaso on 24/10/2020.
//

#include "ActivityList.h"

std::list<Activity *> ActivityList::getActivity() {
    std::list<Activity *> list;

    for (auto i = activities.begin(); i != activities.end(); ++i)
        list.push_back(i->get());

    return list;
}

void ActivityList::addActivity(std::unique_ptr<Activity> activity) {
    if ( activity!= nullptr) {
        activities.push_back(std::move(activity));
    }
}

void ActivityList::removeActivity(Activity *activity) {
    if (activity != nullptr) {
        activities.remove(activity);
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

std::list<Activity *> ActivityList::getListOfDay(QDate date) {
    std::list<Activity *> list;

    for (auto i = activities.begin(); i != activities.end(); ++i){
        if((*i)->getDate()==date)
            list.push_back(i->get());
    }
    return list;
}
