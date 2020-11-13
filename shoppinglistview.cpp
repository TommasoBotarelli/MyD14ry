#include "shoppinglistview.h"
#include "ui_shoppinglistview.h"

ShoppingListView::ShoppingListView(ShoppingList *sL, ListOfShoppingListController *c, QWidget *parent) :
        shopList(sL), controller(c), QDialog(parent),
        ui(new Ui::ShoppingListView) {
    ui->setupUi(this);

    setWindowTitle(shopList->getNameList());

    attach();
    update();
}

ShoppingListView::~ShoppingListView() {
    detach();

    delete ui;
}

void ShoppingListView::on_ShoppingProductListWidget_itemChanged(QListWidgetItem *item) {
    if (QListWidgetProduct *itemProduct = dynamic_cast<QListWidgetProduct *>(item)) {

        if (itemProduct->checkState() == 2)
            itemProduct->getShoppingProduct()->setCatched(true);
        else if (itemProduct->checkState() == 0)
            itemProduct->getShoppingProduct()->setCatched(false);

        update();
    }
}

void ShoppingListView::on_AddShoppingProductButton_clicked() {
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

void ShoppingListView::on_DeleteButton_clicked() {
    detach();
    controller->remove();
    this->close();
}

void ShoppingListView::update() {
    ui->ShoppingProductListWidget->clear();

    for (auto i : shopList->getProducts()) {
        auto itemProduct = new QListWidgetProduct();

        itemProduct->setText((*i).getName());

        if (i->isCatched())
            itemProduct->setCheckState(Qt::Checked);
        else
            itemProduct->setCheckState(Qt::Unchecked);

        itemProduct->setProduct(i);

        ui->ShoppingProductListWidget->addItem(itemProduct);
    }
}

void ShoppingListView::attach() {
    shopList->addObserver(this);
}

void ShoppingListView::detach() {
    shopList->removeObserver(this);
}