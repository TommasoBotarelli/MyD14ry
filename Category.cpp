//
// Created by tommaso on 16/12/20.
//

#include "Category.h"


void Category::getActivity(std::list<std::shared_ptr<Activity>> &actList) {
    for (auto i : activities) {
        actList.push_back(i);
    }
}

void Category::addActivity(std::shared_ptr<Activity> activity) {
    activities.push_back(activity);
}

void Category::removeActivity(std::shared_ptr<Activity> activity) {
    activities.remove(activity);
}

const QString &Category::getName() const {
    return name;
}

void Category::setName(const QString &name) {
    Category::name = name;
}

bool  Category::operator==(const Category &c)const  {
    if (c.getName() == this->getName())
        return true;
    else
        return false;
}
