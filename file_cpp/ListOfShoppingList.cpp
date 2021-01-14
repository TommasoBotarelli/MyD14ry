//
// Created by marco on 24/10/20.

#include "file_h/ListOfShoppingList.h"

void ListOfShoppingList::addShoppingList(std::shared_ptr<ShoppingList> shoppingList) {
    ShoppingLists.push_back(shoppingList);
    notify();
}

void ListOfShoppingList::removeShoppingList(std::shared_ptr<ShoppingList> &shoppingList) {

    for (auto &i : ShoppingLists) {
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

void ListOfShoppingList::getList(std::list<std::shared_ptr<ShoppingList>> &shopList) {
    for (auto &i : ShoppingLists)
        shopList.push_back(i);
}

ListOfShoppingList::~ListOfShoppingList() {
    ShoppingLists.clear();

    for (auto i : observers)
        i->detach();
}

