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

    QFont font;
    font.setWeight(81);

    std::list<std::shared_ptr<ShoppingProduct>> shopP;

    std::list<QString> catList;
    listOfShoppingList->getCategory(catList);


    shopList->getProducts(shopP);
    for (auto &delu : shopP) {
        if (!delu->isCategoryIsSet()) {
            auto itemProduct = new QListWidgetTemplate<ShoppingProduct>;

            itemProduct->setText(delu->getName());

            if (delu->isCatched())
                itemProduct->setCheckState(Qt::Checked);
            else
                itemProduct->setCheckState(Qt::Unchecked);

            itemProduct->set(delu);

            ui->ShoppingProductListWidget->addItem(itemProduct);
        }
    }

    int count;
    int countProduct;

    for (auto &i : catList) {
        countProduct = 0;
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

                if (j->isCatched())
                    itemProduct->setCheckState(Qt::Checked);
                else {
                    itemProduct->setCheckState(Qt::Unchecked);
                    countProduct++;
                }

                itemProduct->set(j);

                ui->ShoppingProductListWidget->addItem(itemProduct);
            }
        }

        if (count != 0) {
            categoryParagraph->setText(i + " ~ " + "(" + QString::number(countProduct) + ")");
        } else {
            delete ui->ShoppingProductListWidget->currentItem();
        }
    }
}

void ShoppingListView::attach() {
    shopList->addObserver(this);
    listOfShoppingList->addObserver(this);
}

void ShoppingListView::detach() {
    shopList->removeObserver(this);
    listOfShoppingList->removeObserver(this);
}

void ShoppingListView::on_deleteProductButton_clicked() {
    if (QListWidgetTemplate<ShoppingProduct> *itemProduct = dynamic_cast <QListWidgetTemplate<ShoppingProduct> *>(ui->ShoppingProductListWidget->currentItem())) {
        controller->removeProduct(itemProduct->get(), shopList);
    }
}

void ShoppingListView::on_deleteCategoryButton_clicked() {
    if (auto catItem = dynamic_cast<QListWidgetItem *> (ui->ShoppingProductListWidget->currentItem())) {
        QString name = catItem->text();
        int endIndex = name.count();
        int startIndex = name.indexOf(QRegExp(" ~ "));
        name.replace(startIndex, endIndex, "");

        controller->removeCategory(name);
    }
}
