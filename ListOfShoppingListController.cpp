//
// Created by marco on 07/11/20.
//

#include "ListOfShoppingListController.h"

void ListOfShoppingListController::setData(QString name) {
    shoppingList->setNameList(name);

    listOfShoppingList->addShoppingList(shoppingList);
}

void ListOfShoppingListController::remove() {
    listOfShoppingList->removeShoppingList(shoppingList);
    shoppingList = nullptr;
}

void ListOfShoppingListController::getLists(QListWidget &list) {
    for (auto i : (listOfShoppingList->getList())) {
        if (i != nullptr) {

            auto a = new QListWidgetShoppingList();

            a->setShoppingList(i);
            a->setText((*i).getNameList());

            list.addItem(a);
        }
    }
}
