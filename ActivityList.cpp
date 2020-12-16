//
// Created by Tommaso on 24/10/2020.
//

#include "ActivityList.h"

void ActivityList::getActivity(std::list<Activity> &actList) {
    for (auto i : activities) {
        actList.push_back(i);
    }
}

void ActivityList::addActivity(Category &c, Activity &activity) {
    for (auto i : categories)
        if (i == c)
            i.addActivity(activity);

    notify();
}

void ActivityList::removeActivity(Activity &activity) {
    std::list<Activity> actList;

    for (auto i : categories) {
        actList.clear();
        i.getActivity(actList);

        for (auto l : actList) {
            if (l == activity) {
                i.removeActivity(l);
                break;
            }
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

ActivityList::~ActivityList() {
    categories.clear();

    for (auto i : observers)
        i->detach();
}
