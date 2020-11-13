//
// Created by marco on 07/11/20.
//

#include "ShoppingListController.h"

void ShoppingListController::setData(QString nameProduct, bool c) {
    shoppingProduct->setName(nameProduct);
    shoppingProduct->setCatched(c);

    shoppingList->addProduct(shoppingProduct);
}
