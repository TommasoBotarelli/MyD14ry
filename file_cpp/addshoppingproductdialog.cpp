#include "../file_h/addshoppingproductdialog.h"
#include "../file_ui/ui_addshoppingproductdialog.h"

AddShoppingProductDialog::AddShoppingProductDialog(std::shared_ptr<ShoppingList> sl, ListOfShoppingListController *slc,
                                                   QWidget *parent)
        :
        shopList(std::move(sl)), controller(slc), QDialog(parent),
        ui(new Ui::AddShoppingProductDialog) {
    ui->setupUi(this);
}

AddShoppingProductDialog::~AddShoppingProductDialog() {
    delete ui;
}

void AddShoppingProductDialog::on_AddButton_clicked() {
    if (getNameProduct() == "")
        ui->NameEdit->setText("INSERISCI PRODOTTO!!!");

    if (getNameProduct() != "" && getNameProduct() != "INSERISCI PRODOTTO!!!") {
        std::shared_ptr<ShoppingProduct> p(new ShoppingProduct);
        controller->setData(shopList, p, getNameProduct());

        this->close();
    }
}

QString AddShoppingProductDialog::getNameProduct() {
    return ui->NameEdit->text();
}

void AddShoppingProductDialog::on_AddCategoryButton_clicked() {

}

void AddShoppingProductDialog::on_CategorycomboBox_currentTextChanged(const QString &arg1) {

}