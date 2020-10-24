//
// Created by tommaso on 24/10/20.
//

#ifndef MYD14RY_ACTIVITYCONTROLLER_H
#define MYD14RY_ACTIVITYCONTROLLER_H

#include <QString>
#include "Activity.h"
#include "SubActivity.h"

class ActivityController {
public:
    ActivityController(Activity *a, SubActivity *subA) : activity(a), subActivity(subA) {};

    void setData(QString task, bool completed);

private:
    Activity *activity;

    SubActivity *subActivity;
};


#endif //MYD14RY_ACTIVITYCONTROLLER_H
