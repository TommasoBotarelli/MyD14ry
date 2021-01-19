//
// Created by Tommaso on 29/10/2020.
//

#include "file_h/CalendarController.h"

void CalendarController::setData(std::shared_ptr<Event> event, QString task, QDate date, QString note, QTime startTime,
                                 QTime endTime,
                                 bool allDay) {
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
    std::list<std::shared_ptr<Event>> eList;
    calendar->getListOfDay(date, eList);

    for (const auto &i : eList) {
        auto a = new QListWidgetTemplate<Event>;

        a->set(i);
        a->setText(i->getTask());

        list.addItem(a);
    }
}

void CalendarController::remove(std::shared_ptr<Event> event) {
    calendar->removeEvent(std::move(event));
}