#ifndef ADDSHOPPINGLISTDIALOG_H
#define ADDSHOPPINGLISTDIALOG_H

#include <QDialog>

namespace Ui {
    class AddShoppingListDialog;
}

class AddShoppingListDialog : public QDialog {
Q_OBJECT

public:
    explicit AddShoppingListDialog(QWidget *parent = nullptr);

    ~AddShoppingListDialog();

private slots:

    void on_AddShoppingProductButton_clicked();

    void on_AddShoppingListButton_clicked();

private:
    Ui::AddShoppingListDialog *ui;
};

#endif // ADDSHOPPINGLISTDIALOG_H
