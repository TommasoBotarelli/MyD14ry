//
// Created by marco on 07/11/20.
//

#include "ShoppingListController.h"

void ShoppingListController::setData(QString nameProduct, bool catched) {
    shoppingProduct->setName(nameProduct);
    shoppingProduct->setCatched(catched);

    shoppingList->addProduct(shoppingProduct);
}
