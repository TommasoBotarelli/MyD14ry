#ifndef ADDSHOPPINGPRODUCTDIALOG_H
#define ADDSHOPPINGPRODUCTDIALOG_H

#include <QDialog>
#include "ListOfShoppingListController.h"

namespace Ui {
    class AddShoppingProductDialog;
}

class AddShoppingProductDialog : public QDialog {
Q_OBJECT

public:
    explicit AddShoppingProductDialog(ShoppingList *sl, ListOfShoppingListController *slc, QWidget *parent = nullptr);

    ~AddShoppingProductDialog() override;

    QString getNameProduct();

private slots:

    void on_AddButton_clicked();

private:
    Ui::AddShoppingProductDialog *ui;

    ShoppingList *shopList;

    ListOfShoppingListController *controller;
};

#endif // ADDSHOPPINGPRODUCTDIALOG_H
