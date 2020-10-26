//
// Created by Tommaso on 24/10/2020.
//

#ifndef MYD14RY_ACTIVITYLIST_H
#define MYD14RY_ACTIVITYLIST_H
#include "Observer.h"
#include "Activity.h"
#include "Subject.h"
#include <list>
#include<memory>
#include <QDate>

class ActivityList: public Subject {
public:
    void addActivity(std::unique_ptr<Activity> activity);

    std::list<Activity*> getActivity();

    void removeActivity(Activity *activity);

    std::list<Activity*> getListOfDay(QDate date);

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() const override;



private:
    std::list<Activity *> activities;
    std::list<Observer *> observers;





};


#endif //MYD14RY_ACTIVITYLIST_H
