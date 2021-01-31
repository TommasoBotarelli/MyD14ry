#ifndef SHOPPINGLISTVIEW_H
#define SHOPPINGLISTVIEW_H

#include <QDialog>
#include "Observer.h"
#include <QListWidgetItem>
#include "ListOfShoppingListController.h"
#include "ShoppingProduct.h"
#include "addshoppingproductdialog.h"
#include "QListWidgetTemplate.h"

namespace Ui {
    class ShoppingListView;
}

class ShoppingListView : public QDialog, public Observer {
Q_OBJECT

public:
    explicit ShoppingListView(std::shared_ptr<ShoppingList> sL, ListOfShoppingListController *c,
                              ListOfShoppingList *lsl,
                              QWidget *parent = nullptr);

    void update() override;

    void attach() override;

    void detach() override;

    ~ShoppingListView() override;

private slots:

    void on_AddShoppingProductButton_clicked();

    void on_DeleteButton_clicked();

    void on_ShoppingProductListWidget_itemChanged(QListWidgetItem *item);

    void on_deleteProductButton_clicked();

private:
    Ui::ShoppingListView *ui;

    std::list<Observer *> observers;

    ListOfShoppingListController *controller;

    std::shared_ptr<ShoppingList> shopList;

    ListOfShoppingList *listOfShoppingList;
};

#endif // SHOPPINGLISTVIEW_H
