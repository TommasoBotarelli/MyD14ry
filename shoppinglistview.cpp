#include "shoppinglistview.h"
#include "ui_shoppinglistview.h"

ShoppingListView::ShoppingListView(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::ShoppingListView) {
    ui->setupUi(this);
}

ShoppingListView::~ShoppingListView() {
    delete ui;
}

void ShoppingListView::on_listWidget_itemChanged(QListWidgetItem *item) {
    //Per aggiornare i prodotti presi
}

void ShoppingListView::on_AddShoppingProductButton_clicked() {

}

void ShoppingListView::on_DeleteButton_clicked() {

}
