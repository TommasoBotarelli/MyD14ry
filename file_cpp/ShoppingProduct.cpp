//
// Created by tommaso on 23/10/20.
//

#include "../file_h/ShoppingProduct.h"

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
    catched = c;
}

const QString &ShoppingProduct::getCategory() const {
    return category;
}

void ShoppingProduct::setCategory(const QString &category) {
    ShoppingProduct::category = category;
}

bool ShoppingProduct::isCategoryIsSet() const {
    return categoryIsSet;
}

void ShoppingProduct::setCategoryIsSet(bool categoryIsSet) {
    ShoppingProduct::categoryIsSet = categoryIsSet;
    category = "";
}
