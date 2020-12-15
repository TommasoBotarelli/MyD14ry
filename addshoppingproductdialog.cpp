#include "addshoppingproductdialog.h"
#include "ui_addshoppingproductdialog.h"

AddShoppingProductDialog::AddShoppingProductDialog(ShoppingList *sl, ListOfShoppingListController *slc, QWidget *parent)
        :
        shopList(sl), controller(slc), QDialog(parent),
        ui(new Ui::AddShoppingProductDialog) {
    ui->setupUi(this);
}

AddShoppingProductDialog::~AddShoppingProductDialog() {
    delete ui;
}

void AddShoppingProductDialog::on_AddButton_clicked() {
    if (getNameProduct() == "")
        ui->NameEdit->setText("INSERISCI PRODOTTO!!!");

    if (getNameProduct() != "" && getNameProduct() != "INSERISCI PRODOTTO!!!") {
        auto p = new ShoppingProduct();
        controller->setData(*shopList, *p, getNameProduct());

        this->close();
    }
}

QString AddShoppingProductDialog::getNameProduct() {
    return ui->NameEdit->text();
}
