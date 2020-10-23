//
// Created by tommaso on 23/10/20.
//

#ifndef MYD14RY_QLISTWIDGETEVENT_H
#define MYD14RY_QLISTWIDGETEVENT_H

#include <QListWidgetItem>

//TODO inclusione del file di header del tipo dell'oggetto

class QListWidgetEvent : public QListWidgetItem {

public:
    Event *getEvent();

private:
    Event *event;
};


#endif //MYD14RY_QLISTWIDGETEVENT_H
