//
// Created by tommaso on 24/10/20.
//

#include "ActivityController.h"


void ActivityController::setData(QString task, bool completed) {
    subActivity->setTask(task);
    subActivity->setCompleted(completed);

    activity->addSubActivity(std::move(std::make_unique<SubActivity>(*subActivity)));

}

