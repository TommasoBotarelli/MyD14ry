//
// Created by marco on 24/10/20.

#include "ListOfShoppingList.h"

void ListOfShoppingList::addShoppingList(ShoppingList *shoppingList) {
    if (shoppingList != nullptr) {

        auto i = ShoppingLists.begin();

        while (i != ShoppingLists.end()) {

            if (&(**i) == shoppingList) {
                delete shoppingList;
                //activities.remove(*i);
            }

            i = std::next(i, 1);
        }
        notify();
    }
    notify();
}

void ListOfShoppingList::removeShoppingList(ShoppingList *shoppingList) {
    if(shoppingList!= nullptr)
        ShoppingLists.remove(shoppingList);
}

void ListOfShoppingList::addObserver(Observer *o) {
    observers.push_back(o);
}

void ListOfShoppingList::removeObserver(Observer *o) {
    observers.remove(o);
}

void ListOfShoppingList::notify() const {
    for (auto i : observers)
        (*i).update();
}

std::list<ShoppingList *> &ListOfShoppingList::getList() {
    auto list = new std::list<ShoppingList *>;

    for (auto i : ShoppingLists)
        list->push_back(i);

    return *list;
}

