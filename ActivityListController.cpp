//
// Created by tommaso on 24/10/20.
//

#include "ActivityListController.h"

void
ActivityListController::setData(const QString category, std::shared_ptr<Activity> activity, const QString task,
                                const QDate deadlineDate, bool completed,
                                const QString note) {
    activity->setTask(task);
    activity->setDeadlineDate(deadlineDate);

    activity->setCompleted(completed);
    activity->setNote(note);
    activity->setCategory(category);
    activity->setCount(0);

    /*std::list<Category> catList;
    std::list<std::shared_ptr<Activity>> actList;
    activityList->getCategory(catList);

    for (auto i : catList) {
        actList.clear();
        i.getActivity(actList);

        for (auto l : actList) {
            if (l == activity) {
                int count = activity.getCount();
                activity->setCount(count + 1);
            }
        }
    }*/         //FIXME

    activityList->addActivity(category, activity);
}

void ActivityListController::remove(std::shared_ptr<Activity> activity) {
    std::list<Category> catList;
    activityList->getCategory(catList);
    std::list<std::shared_ptr<Activity>> actList;

    for (auto i : catList) {
        actList.clear();
        i.getActivity(actList);

        for (auto l : actList) {
            if (l == activity) {
                activityList->removeActivity(i, activity);
            }
        }

    }

}

void ActivityListController::setData(std::shared_ptr<SubActivity> subA, std::shared_ptr<Activity> activity, QString t,
                                     bool c) {
    subA->setTask(t);
    subA->setCompleted(c);

    activity->addSubActivity(subA);
}

void ActivityListController::setData(Category &c, QString name) {
    c.setName(name);
    activityList->addCategory(c);
}

void ActivityListController::searchCategory(Category &c, const QString &name) {
    std::list<Category> catList;
    activityList->getCategory(catList);

    if (findCategory(name)) {

        for (auto i : catList) {

            if (i.getName() == name) {
                c = i;
                break;
            }

        }

    }
}

void ActivityListController::remove(Category &c) {
    activityList->removeCategory(c);
}

bool ActivityListController::findCategory(QString name) {
    std::list<Category> catList;
    activityList->getCategory(catList);

    bool find = false;

    for (auto i : catList) {
        if (i.getName() == name)
            find = true;
    }

    return find;
}
