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
    explicit EventView(std::shared_ptr<Event> e, CalendarController *c, QWidget *parent = nullptr);

    ~EventView() override;

private slots:

    void on_DeleteButton_clicked();

private:
    Ui::EventView *ui;

    std::shared_ptr<Event> event;

    CalendarController *controller;
};

#endif // EVENTVIEW_H
