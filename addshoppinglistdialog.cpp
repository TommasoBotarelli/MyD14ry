#include "addshoppinglistdialog.h"
#include "ui_addshoppinglistdialog.h"

AddShoppingListDialog::AddShoppingListDialog(ShoppingList *sL, ListOfShoppingListController *c, QWidget *parent) :
        shopList(sL), controller(c), QDialog(parent),
        ui(new Ui::AddShoppingListDialog) {
    ui->setupUi(this);
    attach();
}

AddShoppingListDialog::~AddShoppingListDialog() {
    delete ui;
}

void AddShoppingListDialog::on_AddShoppingProductButton_clicked() {

}

void AddShoppingListDialog::on_AddShoppingListButton_clicked() {

}

void AddShoppingListDialog::update() {
    ui->ShoppingProductListWidget->clear();

    for (auto i : shopList->getProducts()) {
        auto qProduct = new QListWidgetProduct;

        qProduct->setText((*i).getName());
        qProduct->setProduct(i);

        ui->ShoppingProductListWidget->addItem(qProduct);
    }


}

void AddShoppingListDialog::attach() {
    shopList->addObserver(this);
}

void AddShoppingListDialog::detach() {
    shopList->removeObserver(this);
}
