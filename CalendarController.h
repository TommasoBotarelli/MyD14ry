//
// Created by Tommaso on 29/10/2020.
//

#ifndef MYD14RY_CALENDARCONTROLLER_H
#define MYD14RY_CALENDARCONTROLLER_H

#include <QString>
#include <QDate>
#include <QTime>
#include "Event.h"
#include "Calendar.h"
#include "QListWidgetEvent.h"

class CalendarController{
public:
    void setData(QString task, QDate date, QString note, QTime startTime, QTime endTime, bool allDay);
    void searchEventOfDay(QDate date, QListWidget &list);
    void remove();
private:
    Event* event;
    Calendar* calendar;


};


#endif //MYD14RY_CALENDARCONTROLLER_H
