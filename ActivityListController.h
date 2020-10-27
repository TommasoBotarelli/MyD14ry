//
// Created by tommaso on 24/10/20.
//

#ifndef MYD14RY_ACTIVITYLISTCONTROLLER_H
#define MYD14RY_ACTIVITYLISTCONTROLLER_H

#include <QString>
#include "Activity.h"
#include "ActivityList.h"

class ActivityListController {
public:
    ActivityListController(Activity *a, ActivityList *aL) : activity(a), activityList(aL) {}

    void setData(QString task, QDate date, QDate deadlineDate, bool completed, QString note);

    void remove();

private:
    Activity *activity;

    ActivityList *activityList;
};


#endif //MYD14RY_ACTIVITYLISTCONTROLLER_H
