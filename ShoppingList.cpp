//
// Created by tommaso on 23/10/20.
//

#include "ShoppingList.h"

const QString &ShoppingList::getNameList() const {
    return nameList;
}

void ShoppingList::setNameList(const QString &name) {
    ShoppingList::nameList = name;
}

std::list<ShoppingProduct *> ShoppingList::getProducts() {
    std::list<ShoppingProduct *> list;

    for (auto i = products.begin(); i != products.end(); ++i)
        list.push_back(i->get());

    return list;
}

void ShoppingList::addProduct(std::unique_ptr<ShoppingProduct> product) {
    if ( product!= nullptr) {
        products.push_back(std::move(product));
    }
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

