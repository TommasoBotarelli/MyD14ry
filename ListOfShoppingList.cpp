//
// Created by marco on 24/10/20.

#include "ListOfShoppingList.h"

void ListOfShoppingList::addShoppingList(ShoppingList &shoppingList) {
    ShoppingLists.push_back(shoppingList);
    notify();
}

void ListOfShoppingList::removeShoppingList(const ShoppingList &shoppingList) {

    for (auto i : ShoppingLists) {
        if (i == shoppingList) {
            ShoppingLists.remove(shoppingList);
            break;
        }
    }
    notify();
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

void ListOfShoppingList::getList(std::list<ShoppingList> &shopList) {
    for (auto i : ShoppingLists)
        shopList.push_back(i);
}

ListOfShoppingList::~ListOfShoppingList() {
    ShoppingLists.clear();

    for (auto i : observers)
        i->detach();
}

