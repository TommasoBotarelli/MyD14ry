//
// Created by tommaso on 23/10/20.
//

#include "ShoppingProduct.h"

const QString &ShoppingProduct::getName() const {
    return name;
}

void ShoppingProduct::setName(const QString &n) {
    ShoppingProduct::name = n;
}

bool ShoppingProduct::isCatched() const {
    return catched;
}

void ShoppingProduct::setCatched(bool c) {
    ShoppingProduct::catched = c;
}
