#ifndef SHOPPINGLISTVIEW_H
#define SHOPPINGLISTVIEW_H

#include <QDialog>

namespace Ui {
    class ShoppingListView;
}

class ShoppingListView : public QDialog {
Q_OBJECT

public:
    explicit ShoppingListView(QWidget *parent = nullptr);

    ~ShoppingListView();

private slots:

    void on_listWidget_itemChanged(QListWidgetItem *item);

    void on_AddShoppingProductButton_clicked();

    void on_DeleteButton_clicked();

private:
    Ui::ShoppingListView *ui;
};

#endif // SHOPPINGLISTVIEW_H
