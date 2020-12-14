//
// Created by tommaso on 24/10/20.
//

#ifndef MYD14RY_ACTIVITYLISTCONTROLLER_H
#define MYD14RY_ACTIVITYLISTCONTROLLER_H

#include <QString>
#include <QListWidget>
#include "Activity.h"
#include "ActivityList.h"
#include "QListWidgetTemplate.h"
#include "SubActivity.h"

class ActivityListController {
public:
    explicit ActivityListController(ActivityList *aL) : activityList(aL) {}

    void setData(Activity &activity, QString task, QDate date, QDate deadlineDate, bool completed, QString note);

    void setData(SubActivity &subA, Activity &activity, QString t, bool c);

    void remove(Activity &activity);

    void searchActivityOfDay(QDate date, QListWidget &list);

private:
    ActivityList *activityList;
};


#endif //MYD14RY_ACTIVITYLISTCONTROLLER_H
