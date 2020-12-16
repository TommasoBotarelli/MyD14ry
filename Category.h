//
// Created by tommaso on 16/12/20.
//

#ifndef MYD14RY_CATEGORY_H
#define MYD14RY_CATEGORY_H


#include <list>
#include "Activity.h"
#include "Subject.h"
#include "Observer.h"

class Category : public Subject {
public:
    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() const override;

    void getActivity(std::list<Activity> &actList);

    void addActivity(Activity &activity);

    void removeActivity(Activity &activity);

    ~Category() override = default;

private:
    std::list<Activity> activities;

    QString name;

    std::list<Observer *> observers;
};


#endif //MYD14RY_CATEGORY_H
