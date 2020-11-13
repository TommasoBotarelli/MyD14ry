//
// Created by tommaso on 23/10/20.
//

#include "QListWidgetProduct.h"

ShoppingProduct *QListWidgetProduct::getShoppingProduct() {
    return shoppingproduct;
}

void QListWidgetProduct::setProduct(ShoppingProduct *sP) {
    shoppingproduct = sP;
}
