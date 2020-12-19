//
// Created by tommaso on 24/10/20.
//

#include "ActivityListController.h"

void
ActivityListController::setData(const QString category, Activity &activity, const QString task,
                                const QDate deadlineDate, bool completed,
                                const QString note) {
    activity.setTask(task);
    activity.setDeadlineDate(deadlineDate);

    activity.setCompleted(completed);
    activity.setNote(note);

    activityList->addActivity(category, activity);
}

void ActivityListController::remove(Activity &activity) {
    std::list<Category> catList;
    activityList->getCategory(catList);
    std::list<Activity> actList;

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

/*void ActivityListController::getActivitiesForCategory(QListWidget &list) {

    std::list<Activity> actList;
    std::list<Category> catList;
    activityList->getCategory(catList);

    for (auto l : catList) {
        actList.clear();
        l.getActivity(actList);
        //list.addItem(l.getName());

        for (const Activity& i : actList) {

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
}*/

void ActivityListController::setData(SubActivity &subA, Activity &activity, QString t, bool c) {
    subA.setTask(t);
    subA.setCompleted(c);

    activity.addSubActivity(subA);
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
