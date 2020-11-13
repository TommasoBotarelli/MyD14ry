//
// Created by marco on 07/11/20.
//

#include "ListOfShoppingListController.h"

void ListOfShoppingListController::setData(QString name, QString product) {
    shoppingList->setNameList(name);
    shoppingList->getProducts();

    listOfShoppingList->addShoppingList(shoppingList);
}

void ListOfShoppingListController::remove() {
    listOfShoppingList->removeShoppingList(shoppingList);
}