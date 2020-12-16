//
// Created by tommaso on 24/10/20.
//

#include "ActivityListController.h"

void ActivityListController::setData(Activity &activity, QString task, QDate deadlineDate, bool completed,
                                     QString note) {
    activity.setTask(task);
    activity.setDeadlineDate(deadlineDate);

    activity.setCompleted(completed);
    activity.setNote(note);


    activityList->addActivity(activity);
}

void ActivityListController::remove(Activity &activity) {
    activityList->removeActivity(activity);
}

void ActivityListController::searchActivity(QListWidget &list) {

    std::list<Activity> aList;
    activityList->getActivity(aList);

    for (auto i : aList) {

        auto a = new QListWidgetTemplate<Activity>;

        a->set(i);
        a->setText(i.getTask());

        if (i.isCompleted())
            a->setCheckState(Qt::Checked);
        else
            a->setCheckState(Qt::Unchecked);

        list.addItem(a);

    }
}

void ActivityListController::setData(SubActivity &subA, Activity &activity, QString t, bool c) {
    subA.setTask(t);
    subA.setCompleted(c);

    activity.addSubActivity(subA);
}
