//
// Created by tommaso on 16/12/20.
//

#ifndef MYD14RY_CATEGORY_H
#define MYD14RY_CATEGORY_H


#include <list>
#include "file_h/Activity.h"

class Category {
public:

    void getActivity(std::list<std::shared_ptr<Activity>> &actList);

    void addActivity(std::shared_ptr<Activity> activity);

    void removeActivity(std::shared_ptr<Activity> activity);

    const QString &getName() const;

    void setName(const QString &name);

    bool operator==(const Category &c) const;

private:
    std::list<std::shared_ptr<Activity>> activities;

    QString name;
};


#endif //MYD14RY_CATEGORY_H
