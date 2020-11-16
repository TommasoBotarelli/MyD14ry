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

void ShoppingProduct::setCatched(bool catched) {
    ShoppingProduct::catched = catched;
}

ShoppingProduct::ShoppingProduct(const ShoppingProduct &original) {
    name = original.getName();
    catched = original.isCatched();
}
