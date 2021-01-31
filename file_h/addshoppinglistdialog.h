#ifndef ADDSHOPPINGLISTDIALOG_H
#define ADDSHOPPINGLISTDIALOG_H

#include <QDialog>
#include "Observer.h"
#include "ShoppingList.h"
#include "ListOfShoppingListController.h"
#include "addshoppingproductdialog.h"

namespace Ui {
    class AddShoppingListDialog;
}

class AddShoppingListDialog : public QDialog, public Observer {
Q_OBJECT

public:
    explicit AddShoppingListDialog(std::shared_ptr<ShoppingList> sL, ListOfShoppingListController *c,
                                   ListOfShoppingList *lsl,
                                   QWidget *parent = nullptr);

    ~AddShoppingListDialog() override;

    void update() override;

    void attach() override;

    void detach() override;

    QString getName();

private slots:

    void on_AddShoppingProductButton_clicked();

    void on_AddShoppingListButton_clicked();

private:
    Ui::AddShoppingListDialog *ui;

    std::shared_ptr<ShoppingList> shopList;

    ListOfShoppingListController *controller;

    ListOfShoppingList *listOfShoppingList;
};

#endif // ADDSHOPPINGLISTDIALOG_H
