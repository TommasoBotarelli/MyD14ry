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

    auto dialog = new AddShoppingProductDialog(shopList, controller);

    while (dialog->exec()) {
        if (dialog->close()) {
            delete dialog;
        }
    }
}

void AddShoppingListDialog::on_AddShoppingListButton_clicked() {
    if (getName() == "")
        ui->NameEdit->setText("INSERISCI NOME LISTA!!!");

    if (getName() != "INSERISCI NOME LISTA!!!" && getName() != "") {
        controller->setData(*shopList, getName());
        detach();
        this->close();
    }

}

void AddShoppingListDialog::update() {
    ui->ShoppingProductListWidget->clear();
    std::list<ShoppingProduct> shopP;
    shopList->getProducts(shopP);

    for (auto i : shopP) {
        auto qProduct = new QListWidgetTemplate<ShoppingProduct>;

        qProduct->setText(i.getName());
        qProduct->set(i);

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
