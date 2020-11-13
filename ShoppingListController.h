//
// Created by marco on 07/11/20.
//

#ifndef MYD14RY_SHOPPINGLISTCONTROLLER_H
#define MYD14RY_SHOPPINGLISTCONTROLLER_H

#include <QString>
#include "ShoppingList.h"
#include "ShoppingProduct.h"


class ShoppingListController {

public:
    ShoppingListController(ShoppingList *s,ShoppingProduct *shopProd): shoppingList(s),shoppingProduct(shopProd){}

    void setData(QString nameProduct, bool c = false);

private:
    ShoppingList *shoppingList;

    ShoppingProduct *shoppingProduct;

};


#endif //MYD14RY_SHOPPINGLISTCONTROLLER_H
