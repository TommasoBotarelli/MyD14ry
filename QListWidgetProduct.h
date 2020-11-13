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

    void setProduct(ShoppingProduct *sP);

private:
    ShoppingProduct *shoppingproduct;
};


#endif //MYD14RY_QLISTWIDGETPRODUCT_H
