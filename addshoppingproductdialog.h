#ifndef ADDSHOPPINGPRODUCTDIALOG_H
#define ADDSHOPPINGPRODUCTDIALOG_H

#include <QDialog>

namespace Ui {
    class AddShoppingProductDialog;
}

class AddShoppingProductDialog : public QDialog {
Q_OBJECT

public:
    explicit AddShoppingProductDialog(QWidget *parent = nullptr);

    ~AddShoppingProductDialog();

private slots:

    void on_AddButton_clicked();

private:
    Ui::AddShoppingProductDialog *ui;
};

#endif // ADDSHOPPINGPRODUCTDIALOG_H
