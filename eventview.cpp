#include "eventview.h"
#include "ui_eventview.h"

EventView::EventView(Event *e, CalendarController *c, QWidget *parent) :
        event(e), controller(c), QDialog(parent),
        ui(new Ui::EventView) {
    ui->setupUi(this);
    setWindowTitle(event->getTask());

    ui->dateEdit->setDate(event->getDate());
    ui->StartTimeEdit->setTime(event->getStartTime());
    ui->EndTimeEdit->setTime(event->getEndTime());
    ui->NoteEdit->setText(event->getNote());

}

EventView::~EventView() {
    delete ui;
}

void EventView::on_DeleteButton_clicked() {
    controller->remove();
    this->close();
}
