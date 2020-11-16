//
// Created by tommaso on 23/10/20.
//

#include "ShoppingList.h"
#include <memory>

const QString &ShoppingList::getNameList() const {
    return nameList;
}

void ShoppingList::setNameList(const QString &name) {
    ShoppingList::nameList = name;
}

std::list<ShoppingProduct *> &ShoppingList::getProducts() {
    auto list = new std::list<ShoppingProduct *>;

    for (auto i = products.begin(); i != products.end(); ++i)
        list->push_back(i->get());

    return *list;
}

void ShoppingList::addProduct(ShoppingProduct *product) {
    if ( product!= nullptr) {
        products.push_back(std::make_shared<ShoppingProduct>(*product));
    }
    notify();
}

void ShoppingList::addObserver(Observer *o) {
    observers.push_back(o);
}

void ShoppingList::removeObserver(Observer *o) {
    observers.remove(o);
}

void ShoppingList::notify() const {
    for (auto i : observers)
        (*i).update();
}

ShoppingList::~ShoppingList() {
    if (!products.empty())
        products.erase(products.begin(), products.end());
}

