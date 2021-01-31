//
// Created by marco on 24/10/20.
//

#ifndef MYD14RY_LISTOFSHOPPINGLIST_H
#define MYD14RY_LISTOFSHOPPINGLIST_H
#include "Subject.h"
#include <list>
#include <memory>
#include "ShoppingList.h"
#include "Observer.h"

class ListOfShoppingList : public Subject {
public:

    void addShoppingList(std::shared_ptr<ShoppingList> shoppingList);

    void removeShoppingList(std::shared_ptr<ShoppingList> &shoppingList);

    void addObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notify() const override;

    void getList(std::list<std::shared_ptr<ShoppingList>> &shopList);

    void addCategory(QString &cat);

    void getCategory(std::list<QString> &catList);

    void removeCategory(QString &cat);

    ~ListOfShoppingList() override;

private:

    std::list<std::shared_ptr<ShoppingList>> ShoppingLists;

    std::list<Observer *> observers;

    std::list<QString> categories;

};


#endif //MYD14RY_LISTOFSHOPPINGLIST_H
