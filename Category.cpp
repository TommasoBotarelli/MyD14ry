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
}

void Category::removeActivity(Activity &activity) {
    for (auto i = activities.begin(); i != activities.end(); i++) {
        if (*i == activity) {
            activities.remove(activity);
            break;
        }
    }
}

const QString &Category::getName() const {
    return name;
}

void Category::setName(const QString &name) {
    Category::name = name;
}

bool Category::operator==(Category &c) {
    if (c.getName() == this->getName())
        return true;
    else
        return false;

}

