#include "../file_h/shoppinglistview.h"
#include "../file_ui/ui_shoppinglistview.h"

ShoppingListView::ShoppingListView(std::shared_ptr<ShoppingList> sL, ListOfShoppingListController *c,
                                   ListOfShoppingList *lsl, QWidget *parent) :
        shopList(sL), controller(c), listOfShoppingList(lsl), QDialog(parent),
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
            controller->setCatched(shopList, itemProduct->get(), true);
        else if (itemProduct->checkState() == 0)
            controller->setCatched(shopList, itemProduct->get(), false);
    }
}

void ShoppingListView::on_AddShoppingProductButton_clicked() {
    auto dialog = new AddShoppingProductDialog(shopList, controller, listOfShoppingList);

    while (dialog->exec()) {
        if (dialog->close()) {
            delete dialog;
        }
    }
}

void ShoppingListView::on_DeleteButton_clicked() {
    detach();
    controller->remove(shopList);
    this->close();
}

void ShoppingListView::update() {
    ui->ShoppingProductListWidget->clear();
    std::list<std::shared_ptr<ShoppingProduct>> shopP;
    shopList->getProducts(shopP);

    for (auto &i : shopP) {
        auto itemProduct = new QListWidgetTemplate<ShoppingProduct>;

        itemProduct->setText(i->getName());

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

void ShoppingListView::on_deleteProductButton_clicked() {
    if (QListWidgetTemplate<ShoppingProduct> *itemProduct = dynamic_cast <QListWidgetTemplate<ShoppingProduct> *>(ui->ShoppingProductListWidget->currentItem())) {
        controller->removeProduct(itemProduct->get(), shopList);
    }
}
