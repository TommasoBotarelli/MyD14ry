#include "addeventdialog.h"
#include "ui_addeventdialog.h"

AddEventDialog::AddEventDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::AddEventDialog) {
    ui->setupUi(this);
}

AddEventDialog::~AddEventDialog() {
    delete ui;
}

void AddEventDialog::on_AddButton_clicked() {

}

void AddEventDialog::on_checkBox_stateChanged(int arg1) {
    //per settare come non modificabile gli orari
}
