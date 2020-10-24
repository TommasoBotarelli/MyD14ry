//
// Created by tommaso on 23/10/20.
//

#ifndef MYD14RY_SHOPPINGLIST_H
#define MYD14RY_SHOPPINGLIST_H

#include <QString>
#include<list>
#include "Subject.h"
#include "ShoppingProduct.h"


class ShoppingList : public Subject {
public:
    std::list<Observer*> observers;

    void notify() const override;

    void removeObserver(Observer *o) override;

    void addObserver(Observer *o) override;

    const QString &getNameList() const;

    void setNameList(const QString &nameList);

    void addProduct(std::unique_ptr<ShoppingProduct> product);

    std::list<ShoppingProduct*> getProducts();

private:
    QString nameList;
    std::list<std::unique_ptr<ShoppingProduct>> products;

};


#endif //MYD14RY_SHOPPINGLIST_H
