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

class ActivityList: public Subject {
public:
    void addActivity(Activity &activity);

    void getActivity(std::list<Activity> &actList);

    void removeActivity(const Activity &activity);

    void getListOfDay(QDate date, std::list<Activity> &);

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() const override;

    ~ActivityList() override;

private:
    std::list<Activity> activities;
    std::list<Observer *> observers;

};


#endif //MYD14RY_ACTIVITYLIST_H
