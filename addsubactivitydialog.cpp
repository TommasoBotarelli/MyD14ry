#include "addsubactivitydialog.h"
#include "ui_addsubactivitydialog.h"

AddSubActivityDialog::AddSubActivityDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::AddSubActivityDialog) {
    ui->setupUi(this);
}

AddSubActivityDialog::~AddSubActivityDialog() {
    delete ui;
}

void AddSubActivityDialog::on_AddButton_clicked() {

}
