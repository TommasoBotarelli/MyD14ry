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
#include "Category.h"

class ActivityListController {
public:
    explicit ActivityListController(ActivityList *aL) : activityList(aL) {}

    void setData(QString category, std::shared_ptr<Activity> activity, QString task, QDate deadlineDate, bool completed,
                 QString note);

    void setData(std::shared_ptr<SubActivity> subA, std::shared_ptr<Activity> activity, QString t, bool c);

    void setData(Category &c, QString name);

    void remove(std::shared_ptr<Activity> activity);

    void remove(Category &c);

    void searchCategory(Category &c, const QString &name);

    //void getActivitiesForCategory(QListWidget &list);

    bool findCategory(QString name);

    void modifyCategory(const QString &oldCategory, const QString &newCategory, std::shared_ptr<Activity>);

private:
    ActivityList *activityList;
};


#endif //MYD14RY_ACTIVITYLISTCONTROLLER_H
