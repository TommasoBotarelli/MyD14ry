//
// Created by tommaso on 23/10/20.
//

#include "QListWidgetProduct.h"

ShoppingProduct *QListWidgetProduct::getShoppingProduct() {
    return shoppingProduct;
}

void QListWidgetProduct::setShoppingProduct(ShoppingProduct *proD) {
    shoppingProduct = proD;
}

void QListWidgetProduct::setProduct(ShoppingProduct *sP) {
    shoppingProduct = sP;
}
