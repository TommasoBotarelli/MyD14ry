#include "addsubactivitydialog.h"
#include "ui_addsubactivitydialog.h"

AddSubActivityDialog::AddSubActivityDialog(ActivityController *c, QWidget *parent) :
        controller(c), QDialog(parent),
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
        controller->setData(getTask(), false);

        this->close();
    }
}

QString AddSubActivityDialog::getTask() {
    return ui->NameEdit->text();
}
