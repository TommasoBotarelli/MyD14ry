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
    AddShoppingProductDialog(std::shared_ptr<ShoppingList> sl, ListOfShoppingListController *slc,
                             QWidget *parent = nullptr);

    ~AddShoppingProductDialog() override;

    QString getNameProduct();

private slots:

    void on_AddButton_clicked();

    void on_AddCategoryButton_clicked();

    void on_CategorycomboBox_currentTextChanged(const QString &arg1);

private:
    Ui::AddShoppingProductDialog *ui;

    std::shared_ptr<ShoppingList> shopList;

    ListOfShoppingListController *controller;
};

#endif // ADDSHOPPINGPRODUCTDIALOG_H
