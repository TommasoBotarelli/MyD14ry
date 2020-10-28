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

void ActivityListController::searchActivityOfDay(QDate date, QListWidget &list) {
    std::list<Activity *> actList;

    activityList->getListOfDay(date, actList);

    list.clear();

    for (auto i : actList) {
        auto a = new QListWidgetActivity;

        a->setActivity(i);
        a->setText((*i).getTask());

        if ((*i).isCompleted())
            a->setCheckState(Qt::Checked);
        else
            a->setCheckState(Qt::Unchecked);

        list.addItem(a);
    }
}
