#include "file_h/addshoppinglistdialog.h"
#include "../file_ui/ui_addshoppinglistdialog.h"

AddShoppingListDialog::AddShoppingListDialog(std::shared_ptr<ShoppingList> sL, ListOfShoppingListController *c,
                                             ListOfShoppingList *lsl,
                                             QWidget *parent) :
        shopList(std::move(sL)), controller(c), listOfShoppingList(lsl), QDialog(parent),
        ui(new Ui::AddShoppingListDialog) {
    ui->setupUi(this);
    attach();
}

AddShoppingListDialog::~AddShoppingListDialog() {
    detach();

    delete ui;
}

void AddShoppingListDialog::on_AddShoppingProductButton_clicked() {

    auto dialog = new AddShoppingProductDialog(shopList, controller, listOfShoppingList);

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

    QFont font;
    font.setWeight(81);

    std::list<QString> catList;
    listOfShoppingList->getCategory(catList);

    int count;

    shopList->getProducts(shopP);

    for (auto &delu : shopP) {
        if (!delu->isCategoryIsSet()) {
            auto itemProduct = new QListWidgetTemplate<ShoppingProduct>;

            itemProduct->setText(delu->getName());

            itemProduct->set(delu);

            ui->ShoppingProductListWidget->addItem(itemProduct);
        }
    }

    for (auto &i : catList) {
        count = 0;
        auto categoryParagraph = new QListWidgetItem(i);

        categoryParagraph->setFont(font);
        categoryParagraph->setBackground(Qt::yellow);

        ui->ShoppingProductListWidget->addItem(categoryParagraph);
        ui->ShoppingProductListWidget->setCurrentItem(categoryParagraph);

        shopP.clear();
        shopList->getProducts(shopP);

        for (auto &j : shopP) {
            if (j->getCategory() == i) {

                count++;

                auto itemProduct = new QListWidgetTemplate<ShoppingProduct>;

                itemProduct->setText(j->getName());

                itemProduct->set(j);

                ui->ShoppingProductListWidget->addItem(itemProduct);
            }
        }

        if (count != 0) {
            categoryParagraph->setText(i);
        } else {
            delete ui->ShoppingProductListWidget->currentItem();
        }
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
