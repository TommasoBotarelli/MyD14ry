#include "file_h/addshoppinglistdialog.h"
#include "../file_ui/ui_addshoppinglistdialog.h"

AddShoppingListDialog::AddShoppingListDialog(std::shared_ptr<ShoppingList> sL, ListOfShoppingListController *c,
                                             QWidget *parent) :
        shopList(std::move(sL)), controller(c), QDialog(parent),
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

    QString name = getName();

    if (getName().replace(" ", "") != "") {

        if (name != "Inserire nome lista") {
            controller->setData(shopList, name);
            detach();
            this->close();
        }
    } else
        ui->NameEdit->setText("Inserire nome lista");


}

void AddShoppingListDialog::update() {
    ui->ShoppingProductListWidget->clear();
    std::list<std::shared_ptr<ShoppingProduct>> shopP;
    shopList->getProducts(shopP);

    for (auto &i : shopP) {
        auto qProduct = new QListWidgetTemplate<ShoppingProduct>;

        qProduct->setText(i->getName());
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
