#include "addshoppinglistdialog.h"
#include "ui_addshoppinglistdialog.h"

AddShoppingListDialog::AddShoppingListDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::AddShoppingListDialog) {
    ui->setupUi(this);
}

AddShoppingListDialog::~AddShoppingListDialog() {
    delete ui;
}

void AddShoppingListDialog::on_AddShoppingProductButton_clicked() {

}

void AddShoppingListDialog::on_AddShoppingListButton_clicked() {

}
