//
// Created by tommaso on 23/10/20.
//

#ifndef MYD14RY_QLISTWIDGETPRODUCT_H
#define MYD14RY_QLISTWIDGETPRODUCT_H

#include <QListWidgetItem>

//TODO inclusione del file di header del tipo dell'oggetto

class QListWidgetProduct : public QListWidgetItem {

public:
    ShoppingProduct *getShoppingProduct();

private:
    ShoppingProduct *shoppingproduct;
};


#endif //MYD14RY_QLISTWIDGETPRODUCT_H
