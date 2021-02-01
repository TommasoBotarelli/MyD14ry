#ifndef ADDSHOPPINGPRODUCTDIALOG_H
#define ADDSHOPPINGPRODUCTDIALOG_H

#include <QDialog>
#include "ListOfShoppingListController.h"
#include "Observer.h"
#include "addproductcategory.h"

namespace Ui {
    class AddShoppingProductDialog;
}

class AddShoppingProductDialog : public QDialog, public Observer {
Q_OBJECT

public:
    AddShoppingProductDialog(std::shared_ptr<ShoppingList> sl, ListOfShoppingListController *slc,
                             ListOfShoppingList *lsl,
                             QWidget *parent = nullptr);

    ~AddShoppingProductDialog() override;

    QString getNameProduct();

    void update() override;

    void attach() override;

    void detach() override;

private slots:

    void on_AddButton_clicked();

    void on_AddCategoryButton_clicked();

    void on_CategoryCheckBox_stateChanged(int arg1);

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::AddShoppingProductDialog *ui;

    std::shared_ptr<ShoppingList> shopList;

    ListOfShoppingListController *controller;

    ListOfShoppingList *listOfShoppingList;

    bool setCategory;
};

#endif // ADDSHOPPINGPRODUCTDIALOG_H
