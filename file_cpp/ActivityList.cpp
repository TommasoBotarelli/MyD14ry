//
// Created by Tommaso on 24/10/2020.
//

#include "../file_h/ActivityList.h"

void ActivityList::getCategory(std::list<Category> &catList) {
    for (Category &i : categories) {
        catList.push_back(i);
    }
}

void ActivityList::addActivity(QString category, std::shared_ptr<Activity> activity) {
    for (Category &i : categories) {
        if (i.getName() == category) {
            i.addActivity(activity);
            break;
        }
    }

    notify();
}

void ActivityList::removeActivity(Category &c, std::shared_ptr<Activity> activity) {
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

void ActivityList::addCategory(const QString &name) {
    Category newCategory(name);

    categories.push_back(newCategory);

    notify();
}

void ActivityList::removeCategory(Category &c) {
    categories.remove(c);

    notify();
}
