//
// Created by tommaso on 24/10/20.
//

#include "ActivityListController.h"

void ActivityListController::setData(QString task, QDate date, QDate deadlineDate, bool completed, QString note) {
    activity->setTask(task);
    activity->setDate(date);
    activity->setDeadlineDate(deadlineDate);

    activity->setCompleted(completed);
    activity->setNote(note);


    activityList->addActivity(activity);
}

void ActivityListController::remove() {
    activityList->removeActivity(activity);
    activity = nullptr;
}

void ActivityListController::searchActivityOfDay(QDate date, QListWidget &list) {

    for (auto i : (activityList->getListOfDay(date))) {
        if (i != nullptr) {
            auto a = new QListWidgetTemplate<Activity>;

            a->set(i);
            a->setText((*i).getTask());

            if ((*i).isCompleted())
                a->setCheckState(Qt::Checked);
            else
                a->setCheckState(Qt::Unchecked);

            list.addItem(a);
        }
    }
}

void ActivityListController::setActivity(Activity *activity) {
    ActivityListController::activity = activity;
}
