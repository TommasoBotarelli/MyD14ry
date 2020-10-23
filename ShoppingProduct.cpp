//
// Created by tommaso on 23/10/20.
//

#include "ShoppingProduct.h"

const QString &ShoppingProduct::getName() const {
    return name;
}

void ShoppingProduct::setName(const QString &name) {
    ShoppingProduct::name = name;
}

bool ShoppingProduct::isCatched() const {
    return catched;
}

void ShoppingProduct::setCatched(bool catched) {
    ShoppingProduct::catched = catched;
}
