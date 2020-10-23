//
// Created by tommaso on 23/10/20.
//

#ifndef MYD14RY_QLISTWIDGETSHOPPINGLIST_H
#define MYD14RY_QLISTWIDGETSHOPPINGLIST_H

#inlcude <QListWidgetItem>

//TODO inclusione del file di header del tipo dell'oggetto

class QListWidgetShoppingList : public QListWidgetItem {

public:
    ShoppingList *getShoppingList();

private:
    ShoppingList *shoppingList;
};


#endif //MYD14RY_QLISTWIDGETSHOPPINGLIST_H
