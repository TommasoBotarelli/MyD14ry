//
// Created by marco on 24/10/20.
//

#ifndef MYD14RY_LISTOFSHOPPINGLIST_H
#define MYD14RY_LISTOFSHOPPINGLIST_H
#include "Subject.h"
#include <list>
#include <memory>
#include "ShoppingList.h"
#include "Observer.h"

class ListOfShoppingList : public Subject {
public:

    void addShoppingList(ShoppingList &shoppingList);

    void removeShoppingList(ShoppingList &shoppingList);

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() const override;

    void getList(std::list<ShoppingList> &shopList);

    ~ListOfShoppingList() override;

private:

    std::list<ShoppingList> ShoppingLists;

    std::list<Observer *> observers;

};


#endif //MYD14RY_LISTOFSHOPPINGLIST_H
