//
// Created by tommaso on 23/10/20.
//

#include "QListWidgetActivity.h"

Activity *QListWidgetActivity::getActivity() {
    return activity;
}

void QListWidgetActivity::setActivity(Activity *activity) {
    QListWidgetActivity::activity = activity;
}
