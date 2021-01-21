//
// Created by marco on 23/10/20.
//

#include "../file_h/SubActivity.h"


void SubActivity::setTask(const QString &t) {
    task = t;
}

const QString &SubActivity::getTask() const {
    return task;
}

bool SubActivity::isCompleted() const {
    return completed;
}

void SubActivity::setCompleted(bool completed) {
    SubActivity::completed = completed;
}

SubActivity::SubActivity(const SubActivity &original) {
    task = original.getTask();
    completed = original.isCompleted();
}

