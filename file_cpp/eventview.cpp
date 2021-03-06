#include "file_h/eventview.h"
#include "../file_ui/ui_eventview.h"

EventView::EventView(std::shared_ptr<Event> e, CalendarController *c, QWidget *parent) :
        event(std::move(e)), controller(c), QDialog(parent),
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
    if (event != nullptr) {
        controller->remove(event);
        this->close();
    }
}
