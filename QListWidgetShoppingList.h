//
// Created by tommaso on 23/10/20.
//

#ifndef MYD14RY_QLISTWIDGETSHOPPINGLIST_H
#define MYD14RY_QLISTWIDGETSHOPPINGLIST_H

#include <QListWidgetItem>
#include "ShoppingList.h"

class QListWidgetShoppingList : public QListWidgetItem {

public:
    ShoppingList *getShoppingList();

    void setShoppingList(ShoppingList *sL);

private:
    ShoppingList *shoppingList;
};


#endif //MYD14RY_QLISTWIDGETSHOPPINGLIST_H
