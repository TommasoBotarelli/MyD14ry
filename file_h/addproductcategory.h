#ifndef ADDPRODUCTCATEGORY_H
#define ADDPRODUCTCATEGORY_H

#include <QDialog>
#include "ListOfShoppingListController.h"

namespace Ui {
    class addProductCategory;
}

class addProductCategory : public QDialog {
Q_OBJECT

public:
    explicit addProductCategory(ListOfShoppingListController *c, QWidget *parent = nullptr);

    ~addProductCategory();

private slots:

    void on_AddButton_clicked();

private:
    Ui::addProductCategory *ui;

    ListOfShoppingListController *controller;
};

#endif // ADDPRODUCTCATEGORY_H
