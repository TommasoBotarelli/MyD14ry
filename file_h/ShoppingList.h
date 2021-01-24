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

    void addProduct(QString product, bool c);

    void removeProduct(std::shared_ptr<ShoppingProduct> product);

    void getProducts(std::list<std::shared_ptr<ShoppingProduct>> &shopList) const;

    bool operator==(const ShoppingList &compareShopList) const;

    ~ShoppingList() override;

    int getCountProduct();

private:

    QString nameList;

    std::list<Observer *> observers;

    std::list<std::shared_ptr<ShoppingProduct>> products;

};


#endif //MYD14RY_SHOPPINGLIST_H
