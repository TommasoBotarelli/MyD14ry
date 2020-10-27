//
// Created by tommaso on 24/10/20.
//

#include "ActivityListController.h"

void ActivityListController::setData(QString task, QDate date, QDate deadlineDate, bool completed, QString note) {
    activity->setTask(task);
    activity->setDate(date);

    if (deadlineDate < date)
        activity->setDeadlineDate(date);
    else
        activity->setDeadlineDate(deadlineDate);

    activity->setCompleted(completed);
    activity->setNote(note);


    activityList->addActivity(activity);
}

void ActivityListController::remove() {
    activityList->removeActivity(activity);

    delete activity;
}
