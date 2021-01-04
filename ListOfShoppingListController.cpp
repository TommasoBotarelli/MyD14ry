//
// Created by marco on 07/11/20.
//

#include "ListOfShoppingListController.h"

void ListOfShoppingListController::setData(ShoppingList &shopList, QString name) {
    shopList.setNameList(name);

    listOfShoppingList->addShoppingList(shopList);
}

void ListOfShoppingListController::remove(ShoppingList &shopList) {
    listOfShoppingList->removeShoppingList(shopList);
}

void ListOfShoppingListController::getLists(QListWidget &list) {
    std::list<ShoppingList> shopList;
    listOfShoppingList->getList(shopList);

    for (const auto &i : shopList) {
        auto a = new QListWidgetTemplate<ShoppingList>;

        a->set(i);
        a->setText(i.getNameList());

        list.addItem(a);
    }
}

void ListOfShoppingListController::setData(ShoppingList &shopList, ShoppingProduct &product, QString name, bool c) {
    product.setName(name);
    product.setCatched(c);

    shopList.addProduct(product);
}
