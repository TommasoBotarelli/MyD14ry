//
// Created by tommaso on 23/10/20.
//

#include "../file_h/ShoppingList.h"

const QString &ShoppingList::getNameList() const  {
    return nameList;
}

void ShoppingList::setNameList(const QString &name) {
    nameList = name;
}

void ShoppingList::getProducts(std::list<std::shared_ptr<ShoppingProduct>> &shopList) const {
    for (auto &i : products)
        shopList.push_back(i);
}

void ShoppingList::addProduct(QString product, QString cat, bool setCategory, bool c) {

    std::shared_ptr<ShoppingProduct> p(new ShoppingProduct(product, cat, setCategory, c));

    products.push_back(p);

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

 bool ShoppingList::operator==( const ShoppingList &compareShopList)const  {
     if (this->getNameList() == compareShopList.getNameList())
         return true;
     else
         return false;
 }

void ShoppingList::removeProduct(std::shared_ptr<ShoppingProduct> product) {
    products.remove(product);
    notify();
}

int ShoppingList::getCountProduct() {
    int countProduct = 0;

    for (const auto &i : products) {
        if (!i->isCatched())
            countProduct++;
    }

    return countProduct;
}
