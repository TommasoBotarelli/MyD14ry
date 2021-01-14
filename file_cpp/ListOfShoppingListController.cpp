//
// Created by marco on 07/11/20.
//

#include "file_h/ListOfShoppingListController.h"

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
        a->setText(i->getNameList());

        list.addItem(a);
    }
}

void ListOfShoppingListController::setData(std::shared_ptr<ShoppingList> &shopList,
                                           std::shared_ptr<ShoppingProduct> &product, QString name, bool c) {
    product->setName(name);
    product->setCatched(c);

    shopList->addProduct(product);
}
