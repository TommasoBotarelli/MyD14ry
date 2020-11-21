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
    if (QListWidgetTemplate<ShoppingProduct> *itemProduct = dynamic_cast <QListWidgetTemplate<ShoppingProduct> *>(item)) {

        if (itemProduct->checkState() == 2)
            itemProduct->get()->setCatched(true);
        else if (itemProduct->checkState() == 0)
            itemProduct->get()->setCatched(false);

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
        auto itemProduct = new QListWidgetTemplate<ShoppingProduct>;

        itemProduct->setText((*i).getName());

        if (i->isCatched())
            itemProduct->setCheckState(Qt::Checked);
        else
            itemProduct->setCheckState(Qt::Unchecked);

        itemProduct->set(i);

        ui->ShoppingProductListWidget->addItem(itemProduct);
    }
}

void ShoppingListView::attach() {
    shopList->addObserver(this);
}

void ShoppingListView::detach() {
    shopList->removeObserver(this);
}