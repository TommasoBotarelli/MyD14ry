#ifndef SHOPPINGLISTVIEW_H
#define SHOPPINGLISTVIEW_H

#include <QDialog>
#include "Observer.h"
#include <QListWidgetItem>
#include "ListOfShoppingListController.h"
#include "QListWidgetProduct.h"
#include "ShoppingListController.h"
#include "ShoppingProduct.h"
#include "addshoppingproductdialog.h"

namespace Ui {
    class ShoppingListView;
}

class ShoppingListView : public QDialog, public Observer {
Q_OBJECT

public:
    explicit ShoppingListView(ShoppingList *sL, ListOfShoppingListController *c, QWidget *parent = nullptr);

    void update() override;

    void attach() override;

    void detach() override;

    ~ShoppingListView() override;

private slots:

    void on_AddShoppingProductButton_clicked();

    void on_DeleteButton_clicked();

    void on_ShoppingProductListWidget_itemChanged(QListWidgetItem *item);

private:
    Ui::ShoppingListView *ui;

    std::list<Observer *> observers;

    ListOfShoppingListController *controller;

    ShoppingList *shopList;
};

#endif // SHOPPINGLISTVIEW_H
