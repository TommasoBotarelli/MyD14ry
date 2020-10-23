//
// Created by tommaso on 23/10/20.
//

#include "ShoppingList.h"

const QString &ShoppingList::getNameList() const {
    return nameList;
}

void ShoppingList::setNameList(const QString &nameList) {
    ShoppingList::nameList = nameList;
}
