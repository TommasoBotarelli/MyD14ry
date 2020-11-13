//
// Created by marco on 24/10/20.

#include "ListOfShoppingList.h"

void ListOfShoppingList::addShoppingList(ShoppingList *shoppingList) {
    if (shoppingList != nullptr) {
        ShoppingLists.push_back(std::move(shoppingList));
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

std::list<ShoppingList *> ListOfShoppingList::getList() {
    std::list<ShoppingList *> list;

    for (auto i = ShoppingLists.begin(); i != ShoppingLists.end(); ++i)
        list.push_back(*i);

    return list;
}

