//
// Created by tommaso on 23/10/20.
//

#include "ShoppingList.h"
#include <memory>

const QString &ShoppingList::getNameList() const {
    return nameList;
}

void ShoppingList::setNameList(const QString &name) {
    nameList = name;
}

void const ShoppingList::getProducts(std::list<ShoppingProduct> &shopList) {
    for (auto i : products)
        shopList.push_back(i);
}

void ShoppingList::addProduct(ShoppingProduct &product) {

    products.push_back(product);
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

bool ShoppingList::operator==(const ShoppingList &compareShopList) {
    /*std::list<ShoppingProduct> list;
    compareShopList.getProducts(list);*/

    if (this->getNameList() == compareShopList.getNameList() /*&&       //FIXME
    this->products.size() == list.size()*/)
        return true;

    else
        return false;
}

