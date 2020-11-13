#ifndef ADDSHOPPINGPRODUCTDIALOG_H
#define ADDSHOPPINGPRODUCTDIALOG_H

#include <QDialog>
#include "ShoppingListController.h"

namespace Ui {
    class AddShoppingProductDialog;
}

class AddShoppingProductDialog : public QDialog {
Q_OBJECT

public:
    explicit AddShoppingProductDialog(ShoppingListController *slc, QWidget *parent = nullptr);

    ~AddShoppingProductDialog() override;

    QString getNameProduct();

private slots:

    void on_AddButton_clicked();

private:
    Ui::AddShoppingProductDialog *ui;

    ShoppingListController *shopListController;
};

#endif // ADDSHOPPINGPRODUCTDIALOG_H
