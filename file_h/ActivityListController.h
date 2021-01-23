//
// Created by tommaso on 24/10/20.
//

#ifndef MYD14RY_ACTIVITYLISTCONTROLLER_H
#define MYD14RY_ACTIVITYLISTCONTROLLER_H

#include <QString>
#include <QListWidget>
#include "../file_h/Activity.h"
#include "../file_h/ActivityList.h"
#include "QListWidgetTemplate.h"
#include "SubActivity.h"
#include "Category.h"

class ActivityListController {
public:
    explicit ActivityListController(ActivityList *aL) : activityList(aL) {}

    void setData(QString category, std::shared_ptr<Activity> activity, QString task, QDate deadlineDate, bool completed,
                 QString note);

    void addSubActivity(std::shared_ptr<Activity> activity, QString t, bool c);

    void addCategory(QString name);

    void remove(std::shared_ptr<Activity> activity);

    void removeAndMoveActivity(QString category);

    void removeCategoryAndActivity(QString category);

    void searchCategory(Category &c, const QString &name);

    bool findCategory(QString name);

    void modifyCategory(const QString &oldCategory, const QString &newCategory, std::shared_ptr<Activity>);

    void removeSubActivity(std::shared_ptr<SubActivity> subA, std::shared_ptr<Activity> act);


private:
    ActivityList *activityList;
};


#endif //MYD14RY_ACTIVITYLISTCONTROLLER_H
