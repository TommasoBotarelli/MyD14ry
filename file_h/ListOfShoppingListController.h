//
// Created by marco on 07/11/20.
//

#ifndef MYD14RY_LISTOFSHOPPINGLISTCONTROLLER_H
#define MYD14RY_LISTOFSHOPPINGLISTCONTROLLER_H

#include "ShoppingList.h"
#include "ListOfShoppingList.h"
#include "QListWidgetTemplate.h"
#include <QString>
#include <QListWidget>
#include "ShoppingProduct.h"


class ListOfShoppingListController {

public:
    explicit ListOfShoppingListController(ListOfShoppingList *listOfShopList) : listOfShoppingList(listOfShopList) {}

    void setData(std::shared_ptr<ShoppingList> &shopList, QString name);

    void addProduct(std::shared_ptr<ShoppingList> &shopList, QString name, bool c = false);

    void remove(std::shared_ptr<ShoppingList> shopList);

    void getLists(QListWidget &list);

    void removeProduct(std::shared_ptr<ShoppingProduct> sP, std::shared_ptr<ShoppingList> sL);

    void setCatched(std::shared_ptr<ShoppingList> sL, std::shared_ptr<ShoppingProduct> sP, bool catched);

private:
    ListOfShoppingList *listOfShoppingList;
};


#endif //MYD14RY_LISTOFSHOPPINGLISTCONTROLLER_H
