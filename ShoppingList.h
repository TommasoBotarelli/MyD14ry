//
// Created by tommaso on 23/10/20.
//

#ifndef MYD14RY_SHOPPINGLIST_H
#define MYD14RY_SHOPPINGLIST_H

#include <QString>
#include <memory>
#include <list>
#include <utility>
#include "Subject.h"
#include "ShoppingProduct.h"


class ShoppingList : public Subject {
public:
    ShoppingList() = default;

    void notify() const override;

    void removeObserver(Observer *o) override;

    void addObserver(Observer *o) override;

    const QString &getNameList() const;

    void setNameList(const QString &nameList);

    void addProduct(ShoppingProduct &product);

    void const getProducts(std::list<ShoppingProduct> &shopList);

    bool operator==(const ShoppingList &compareShopList);

    ~ShoppingList() override;

private:

    QString nameList;
    std::list<Observer *> observers;
    std::list<ShoppingProduct> products;

};


#endif //MYD14RY_SHOPPINGLIST_H
