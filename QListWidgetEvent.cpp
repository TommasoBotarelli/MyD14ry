//
// Created by tommaso on 23/10/20.
//

#include "QListWidgetEvent.h"

Event *QListWidgetEvent::getEvent() {
    return event;
}
void QListWidgetEvent::setEvent(Event *event) {
    QListWidgetEvent::event = event;
}