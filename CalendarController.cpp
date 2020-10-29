//
// Created by Tommaso on 29/10/2020.
//

#include "CalendarController.h"

void CalendarController::setData(QString task, QDate date, QString note, QTime startTime, QTime endTime, bool allDay) {
    event->setTask(task);
    event->setDate(date);
    event->setNote(note);
    event->setStartTime(startTime);
    event->setEndTime(endTime);
    event->setAllDay(allDay);
}

void CalendarController::searchEventOfDay(QDate date, QListWidget &list) {
    std::list<Event *> evList;

   calendar->getListOfDay(date,evList);

    list.clear();

    for (auto i : evList) {
        auto a = new QListWidgetEvent;

        a->setEvent(i);
        a->setText((*i).getTask());

        if ((*i).isAllDay())
            a->setCheckState(Qt::Checked);
        else
            a->setCheckState(Qt::Unchecked);

        list.addItem(a);
    }
}

void CalendarController::remove() {
    calendar->removeEvent(event);
}
