//
// Created by tommaso on 23/10/20.
//

#ifndef MYD14RY_SHOPPINGLIST_H
#define MYD14RY_SHOPPINGLIST_H

#include <QString>
#include <memory>
#include<list>
#include "Subject.h"
#include "Observer.h"
#include "ShoppingProduct.h"


class ShoppingList : public Subject {
public:

    ShoppingList() = default;

    void notify() const override;

    void removeObserver(Observer *o) override;

    void addObserver(Observer *o) override;

    const QString &getNameList() const;

    void setNameList(const QString &nameList);

    void addProduct(ShoppingProduct *product);

    std::list<ShoppingProduct *> getProducts();

    ~ShoppingList() override;

private:
    QString nameList;
    std::list<std::shared_ptr<ShoppingProduct>> products;
    std::list<Observer *> observers;

};


#endif //MYD14RY_SHOPPINGLIST_H
