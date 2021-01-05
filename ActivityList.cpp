//
// Created by Tommaso on 24/10/2020.
//

#include "ActivityList.h"

void ActivityList::getCategory(std::list<Category> &catList) {
    for (auto &i : categories) {
        catList.push_back(i);
    }
}

void ActivityList::addActivity(QString category, Activity &activity) {
    for (auto &i : categories) {
        if (i.getName() == category) {
            i.addActivity(activity);
            break;
        }
    }

    notify();
}

void ActivityList::removeActivity(Category &c, Activity &activity) {
    for (auto &i : categories) {
        if (i.getName() == c.getName()) {
            i.removeActivity(activity);
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

ActivityList::~ActivityList() {
    categories.clear();

    for (auto i : observers)
        i->detach();
}

void ActivityList::addCategory(Category &c) {
    categories.push_back(c);

    notify();
}

void ActivityList::removeCategory(Category &c) {
    categories.remove(c);

    notify();
}
