//
// Created by marco on 07/11/20.
//

#ifndef MYD14RY_LISTOFSHOPPINGLISTCONTROLLER_H
#define MYD14RY_LISTOFSHOPPINGLISTCONTROLLER_H

#include "ShoppingList.h"
#include "ListOfShoppingList.h"
#include <QString>
#include <QListWidget>
#include "QListWidgetShoppingList.h"

class ListOfShoppingListController {

public:
    ListOfShoppingListController(ShoppingList *s, ListOfShoppingList *listOfShopList) : shoppingList(s),listOfShoppingList(listOfShopList) {}

    void setData(QString name);

    void remove();

    void getLists(QListWidget &list);

private:
    ListOfShoppingList *listOfShoppingList;

    ShoppingList *shoppingList;
};


#endif //MYD14RY_LISTOFSHOPPINGLISTCONTROLLER_H
