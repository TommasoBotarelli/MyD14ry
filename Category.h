//
// Created by tommaso on 16/12/20.
//

#ifndef MYD14RY_CATEGORY_H
#define MYD14RY_CATEGORY_H


#include <list>
#include "Activity.h"

class Category {
public:

    void getActivity(std::list<Activity> &actList);

    void addActivity(Activity &activity);

    void removeActivity(Activity &activity);

    const QString &getName() const;

    void setName(const QString &name);

    bool const operator==(const Category &c);

    //Category& operator = (Category c);

private:
    std::list<Activity> activities;

    QString name;
};


#endif //MYD14RY_CATEGORY_H
