#include "addeventdialog.h"
#include "ui_addeventdialog.h"

AddEventDialog::AddEventDialog(CalendarController *c, QWidget *parent) :
        controller(c), QDialog(parent),
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
    if (ui->AllDayCheckBox->isChecked())
        on_checkBox_stateChanged(2);

    if (getTask() == "")
        ui->NameLineEdit->setText("INSERISCI EVENTO!!!");

    if (getTask() != "INSERISCI EVENTO!!!" && getTask() != "") {
        controller->setData(getTask(), getDate(), getNote(),
                            getStartTime(), getEndTime(), getAllDay());

        (*this).close();
    }
}

void AddEventDialog::on_checkBox_stateChanged(int arg1) {
    if (arg1 == 2) {
        QTime startTime(0, 0);
        QTime endTime(23, 59);
        ui->StartTimeEdit->setTime(startTime);
        ui->EndTimeEdit->setTime(endTime);
    }
}

const QString AddEventDialog::getTask() {
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
