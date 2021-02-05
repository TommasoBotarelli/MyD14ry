//
// Created by marco on 07/11/20.
//

#include "../file_h/ListOfShoppingListController.h"

void ListOfShoppingListController::setData(std::shared_ptr<ShoppingList> &shopList, QString name) {
    shopList->setNameList(name);

    listOfShoppingList->addShoppingList(shopList);
}

void ListOfShoppingListController::remove(std::shared_ptr<ShoppingList> shopList) {
    listOfShoppingList->removeShoppingList(shopList);
}

void ListOfShoppingListController::getLists(QListWidget &list) {
    std::list<std::shared_ptr<ShoppingList>> shopList;
    listOfShoppingList->getList(shopList);

    for (const auto &i : shopList) {
        auto a = new QListWidgetTemplate<ShoppingList>;

        a->set(i);
        a->setText(i->getNameList() + "     " + "(" + QString::number(i->getCountProduct()) + ")");

        list.addItem(a);
    }
}

void ListOfShoppingListController::addProduct(std::shared_ptr<ShoppingList> &shopList, QString name, QString cat,
                                              bool setCategory, bool c) {
    shopList->addProduct(name, cat, setCategory);
}

void
ListOfShoppingListController::removeProduct(std::shared_ptr<ShoppingProduct> sP, std::shared_ptr<ShoppingList> sL) {
    sL->removeProduct(std::move(sP));
}

void ListOfShoppingListController::setCatched(std::shared_ptr<ShoppingList> sL, std::shared_ptr<ShoppingProduct> sP,
                                              bool catched) {
    sP->setCatched(catched);
    sL->notify();
}

void ListOfShoppingListController::addCategory(QString cat) {
    listOfShoppingList->addCategory(cat);
}

void ListOfShoppingListController::removeCategory(QString cat) {
    std::list<std::shared_ptr<ShoppingProduct>> shopP;
    std::list<std::shared_ptr<ShoppingList>> shopList;

    listOfShoppingList->getList(shopList);

    for (auto &i : shopList) {
        shopP.clear();
        i->getProducts(shopP);

        for (auto &j : shopP) {

            if (j->getCategory() == cat) {
                j->setCategoryIsSet(false);
            }

        }

    }

    listOfShoppingList->removeCategory(cat);

}

bool ListOfShoppingListController::findCategory(const QString &name) {
    std::list<QString> catList;
    listOfShoppingList->getCategory(catList);

    bool find = false;

    for (auto &i : catList) {
        if (i == name)
            find = true;
    }

    return find;
}
