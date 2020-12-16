//
// Created by tommaso on 16/12/20.
//

#include "Category.h"


void Category::getActivity(std::list<Activity> &actList) {
    for (auto i : activities) {
        actList.push_back(i);
    }
}

void Category::addActivity(Activity &activity) {
    activities.push_back(activity);

    notify();
}

void Category::removeActivity(Activity &activity) {
    for (auto i = activities.begin(); i != activities.end(); i++) {
        if (*i == activity) {
            activities.remove(activity);
            break;
        }
    }
    notify();
}

void Category::addObserver(Observer *o) {
    observers.push_back(o);
}

void Category::removeObserver(Observer *o) {
    observers.remove(o);
}

void Category::notify() const {
    for (auto i : observers)
        (*i).update();
}

