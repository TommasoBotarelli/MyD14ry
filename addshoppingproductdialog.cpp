#include "addshoppingproductdialog.h"
#include "ui_addshoppingproductdialog.h"

AddShoppingProductDialog::AddShoppingProductDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::AddShoppingProductDialog) {
    ui->setupUi(this);
}

AddShoppingProductDialog::~AddShoppingProductDialog() {
    delete ui;
}

void AddShoppingProductDialog::on_AddButton_clicked() {

}
