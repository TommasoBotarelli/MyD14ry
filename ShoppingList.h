//
// Created by tommaso on 23/10/20.
//

#ifndef MYD14RY_SHOPPINGLIST_H
#define MYD14RY_SHOPPINGLIST_H

#include <QString>
#include "Subject.h"

class ShoppingList : public Subject {
public:
    const QString &getNameList() const;

    void setNameList(const QString &nameList);

private:
    QString nameList;
};


#endif //MYD14RY_SHOPPINGLIST_H
