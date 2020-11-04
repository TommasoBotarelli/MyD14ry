#ifndef EVENTVIEW_H
#define EVENTVIEW_H

#include <QDialog>
#include "Event.h"
#include "CalendarController.h"

namespace Ui {
    class EventView;
}

class EventView : public QDialog {
Q_OBJECT

public:
    explicit EventView(Event *e, CalendarController *c, QWidget *parent = nullptr);

    ~EventView() override;

private slots:

    void on_DeleteButton_clicked();

private:
    Ui::EventView *ui;

    Event *event;

    CalendarController *controller;
};

#endif // EVENTVIEW_H
