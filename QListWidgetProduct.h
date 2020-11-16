//
// Created by tommaso on 23/10/20.
//

#ifndef MYD14RY_QLISTWIDGETPRODUCT_H
#define MYD14RY_QLISTWIDGETPRODUCT_H

#include <QListWidgetItem>
#include "ShoppingProduct.h"

class QListWidgetProduct : public QListWidgetItem {

public:
    ShoppingProduct *getShoppingProduct();
    void setShoppingProduct(ShoppingProduct *shoppingProduct);

    void setProduct(ShoppingProduct *sP);

private:
    ShoppingProduct *shoppingProduct;
};


#endif //MYD14RY_QLISTWIDGETPRODUCT_H
