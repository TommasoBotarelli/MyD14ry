#include "addsubactivitydialog.h"
#include "ui_addsubactivitydialog.h"

AddSubActivityDialog::AddSubActivityDialog(std::shared_ptr<Activity> act, ActivityListController *c, QWidget *parent) :
        activity(act), controller(c), QDialog(parent),
        ui(new Ui::AddSubActivityDialog) {
    ui->setupUi(this);
}

AddSubActivityDialog::~AddSubActivityDialog() {
    delete ui;
}

void AddSubActivityDialog::on_AddButton_clicked() {
    if (getTask() == "")
        ui->NameEdit->setText("INSERISCI SOTTO ATTIVITÀ!!!");

    if (getTask() != "" && getTask() != "INSERISCI SOTTO ATTIVITÀ!!!") {
        std::shared_ptr<SubActivity> subA(new SubActivity);
        controller->setData(subA, activity, getTask(), false);

        this->close();
    }
}

QString AddSubActivityDialog::getTask() {
    return ui->NameEdit->text();
}
