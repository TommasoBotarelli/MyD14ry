#include "file_h/addeventdialog.h"

#include <utility>
#include "../file_ui/ui_addeventdialog.h"

AddEventDialog::AddEventDialog(CalendarController *c, std::shared_ptr<Event> e, QWidget *parent) :
        controller(c), event(std::move(e)), QDialog(parent),
        ui(new Ui::AddEventDialog) {
    ui->setupUi(this);

    ui->DateEdit->setDate(QDate::currentDate());
    ui->StartTimeEdit->setTime(QTime::currentTime());
    ui->EndTimeEdit->setTime(QTime::currentTime());
}

AddEventDialog::~AddEventDialog() {
    delete ui;
}

void AddEventDialog::on_AddButton_clicked() {

    QString name = getTask();

    if (getTask().replace(" ", "") != "") {

        if (name != "Inserire evento") {
            controller->setData(event, name, getDate(), getNote(),
                                getStartTime(), getEndTime(), getAllDay());

            this->close();
        }
    } else
        ui->NameLineEdit->setText("Inserire evento");

}

void AddEventDialog::on_AllDayCheckBox_stateChanged(int arg1) {
    if (arg1 == 2) {
        event->setAllDay(true);
        QTime startTime(0, 0);
        QTime endTime(23, 59);
        ui->StartTimeEdit->setTime(startTime);
        ui->EndTimeEdit->setTime(endTime);
    }

    if (arg1 == 0)
        event->setAllDay(false);
}

QString AddEventDialog::getTask() {
    return ui->NameLineEdit->text();
}

const QDate AddEventDialog::getDate() {
    return ui->DateEdit->date();
}

const QTime AddEventDialog::getStartTime() {
    return ui->StartTimeEdit->time();
}

const QTime AddEventDialog::getEndTime() {
    return ui->EndTimeEdit->time();
}

const bool AddEventDialog::getAllDay() {
    if (ui->AllDayCheckBox->isChecked())
        return true;
    else
        return false;
}

const QString AddEventDialog::getNote() {
    return ui->NoteEdit->toPlainText();
}