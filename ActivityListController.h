//
// Created by tommaso on 24/10/20.
//

#ifndef MYD14RY_ACTIVITYLISTCONTROLLER_H
#define MYD14RY_ACTIVITYLISTCONTROLLER_H

#include <QString>
#include <QListWidget>
#include "Activity.h"
#include "ActivityList.h"
#include "QListWidgetActivity.h"
#include "QListWidgetTemplate.h"

class ActivityListController {
public:
    explicit ActivityListController(ActivityList *aL, Activity *a = nullptr) : activityList(aL), activity(a) {}

    void setData(QString task, QDate date, QDate deadlineDate, bool completed, QString note);

    void remove();

    void searchActivityOfDay(QDate date, QListWidget &list);

    void setActivity(Activity *activity);

private:
    ActivityList *activityList;

    Activity *activity;
};


#endif //MYD14RY_ACTIVITYLISTCONTROLLER_H
