//
// Created by tommaso on 23/10/20.
//

#include "QListWidgetShoppingList.h"

ShoppingList *QListWidgetShoppingList::getShoppingList() {
    return shoppingList;
}

void QListWidgetShoppingList::setShoppingList(ShoppingList *sL) {
    shoppingList = sL;
}
