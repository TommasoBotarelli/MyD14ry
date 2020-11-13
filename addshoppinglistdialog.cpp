#include "addshoppinglistdialog.h"
#include "ui_addshoppinglistdialog.h"

AddShoppingListDialog::AddShoppingListDialog(ShoppingList *sL, ListOfShoppingListController *c, QWidget *parent) :
        shopList(sL), controller(c), QDialog(parent),
        ui(new Ui::AddShoppingListDialog) {
    ui->setupUi(this);
    attach();
}

AddShoppingListDialog::~AddShoppingListDialog() {
    detach();

    delete ui;
}

void AddShoppingListDialog::on_AddShoppingProductButton_clicked() {
    auto product = new ShoppingProduct();

    auto c = new ShoppingListController(shopList, product);

    auto dialog = new AddShoppingProductDialog(c);

    while (dialog->exec()) {
        if (dialog->close()) {
            delete dialog;
            delete c;
        }
    }
}

void AddShoppingListDialog::on_AddShoppingListButton_clicked() {
    if (getName() == "")
        ui->NameEdit->setText("INSERISCI NOME LISTA!!!");

    if (getName() != "INSERISCI NOME LISTA!!!" && getName() != "") {
        controller->setData(getName());
        detach();
        this->close();
    }

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

QString AddShoppingListDialog::getName() {
    return ui->NameEdit->text();
}
