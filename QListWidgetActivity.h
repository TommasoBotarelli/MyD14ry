//
// Created by tommaso on 23/10/20.
//

#ifndef MYD14RY_QLISTWIDGETACTIVITY_H
#define MYD14RY_QLISTWIDGETACTIVITY_H

#include <QListWidgetItem>
#include "Activity.h"

class QListWidgetActivity : public QListWidgetItem {

public:
    Activity *getActivity();

private:
    Activity *activity;
};


#endif //MYD14RY_QLISTWIDGETACTIVITY_H
