//
// Created by marco on 07/11/20.
//

#ifndef MYD14RY_LISTOFSHOPPINGLISTCONTROLLER_H
#define MYD14RY_LISTOFSHOPPINGLISTCONTROLLER_H

#include "ShoppingList.h"
#include "ListOfShoppingList.h"
#include <QString>
#include <QListWidget>
#include "QListWidgetTemplate.h"


class ListOfShoppingListController {

public:
    explicit ListOfShoppingListController(ListOfShoppingList *listOfShopList) : listOfShoppingList(listOfShopList) {}

    void setData(std::shared_ptr<ShoppingList> &shopList, QString name);

    void setData(std::shared_ptr<ShoppingList> &shopList, std::shared_ptr<ShoppingProduct> &product, QString name,
                 bool c = false);

    void remove(std::shared_ptr<ShoppingList> shopList);

    void getLists(QListWidget &list);

private:
    ListOfShoppingList *listOfShoppingList;
};


#endif //MYD14RY_LISTOFSHOPPINGLISTCONTROLLER_H
