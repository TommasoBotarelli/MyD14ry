//
// Created by Tommaso on 24/10/2020.
//

#ifndef MYD14RY_ACTIVITYLIST_H
#define MYD14RY_ACTIVITYLIST_H
#include "Observer.h"
#include "Activity.h"
#include "Subject.h"
#include "SubActivity.h"
#include <list>
#include<memory>
#include <QDate>
#include "Category.h"

class ActivityList : public Subject {
public:
    void addActivity(QString category, Activity &activity);

    void addCategory(Category &c);

    void removeCategory(Category &c);

    void getCategory(std::list<Category> &catList);

    void removeActivity(Category &c, Activity &activity);

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() const override;

    ~ActivityList() override;

private:
    std::list<Category> categories;
    std::list<Observer *> observers;
};


#endif //MYD14RY_ACTIVITYLIST_H
