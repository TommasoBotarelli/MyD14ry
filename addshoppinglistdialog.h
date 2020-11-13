#ifndef ADDSHOPPINGLISTDIALOG_H
#define ADDSHOPPINGLISTDIALOG_H

#include <QDialog>
#include "Observer.h"
#include "ShoppingList.h"
#include "ListOfShoppingListController.h"
#include "QListWidgetProduct.h"

namespace Ui {
    class AddShoppingListDialog;
}

class AddShoppingListDialog : public QDialog, public Observer {
Q_OBJECT

public:
    explicit AddShoppingListDialog(ShoppingList *sL, ListOfShoppingListController *c, QWidget *parent = nullptr);

    ~AddShoppingListDialog();

    void update() override;

    void attach() override;

    void detach() override;

private slots:

    void on_AddShoppingProductButton_clicked();

    void on_AddShoppingListButton_clicked();

private:
    Ui::AddShoppingListDialog *ui;

    ShoppingList *shopList;

    ListOfShoppingListController *controller;
};

#endif // ADDSHOPPINGLISTDIALOG_H
