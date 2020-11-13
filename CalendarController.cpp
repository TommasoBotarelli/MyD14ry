//
// Created by Tommaso on 29/10/2020.
//

#include "CalendarController.h"

void CalendarController::setData(QString task, QDate date, QString note, QTime startTime, QTime endTime, bool allDay) {
    QTime start(0, 0);
    QTime end(23, 59);

    if (startTime == start && endTime == end)
        event->setTask(task + "(Tutto il giorno)");
    else
        event->setTask(task + "(" + startTime.toString() + " - " + endTime.toString() + ")");

    event->setDate(date);
    event->setNote(note);
    event->setStartTime(startTime);
    event->setEndTime(endTime);
    event->setAllDay(allDay);

    calendar->addEvent(event);
}

void CalendarController::searchEventOfDay(QDate date, QListWidget &list) {
    list.clear();

    for (auto i : calendar->getListOfDay(date)) {
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
