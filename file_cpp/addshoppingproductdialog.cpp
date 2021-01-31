#include "../file_h/addshoppingproductdialog.h"
#include "../file_ui/ui_addshoppingproductdialog.h"

AddShoppingProductDialog::AddShoppingProductDialog(std::shared_ptr<ShoppingList> sl, ListOfShoppingListController *slc,
                                                   ListOfShoppingList *lsl,
                                                   QWidget *parent)
        :
        shopList(std::move(sl)), controller(slc), listOfShoppingList(lsl), category(""), setCategory(false),
        QDialog(parent),
        ui(new Ui::AddShoppingProductDialog) {
    ui->setupUi(this);
    attach();
    update();
}

AddShoppingProductDialog::~AddShoppingProductDialog() {
    delete ui;
}

void AddShoppingProductDialog::on_AddButton_clicked() {

    QString name = getNameProduct();

    if (getNameProduct().replace(" ", "") != "") {

        if (name != "Inserire nome prodotto") {
            controller->addProduct(shopList, name, category, setCategory);

            this->close();
        }
    } else
        ui->NameEdit->setText("Inserire nome prodotto");
}

QString AddShoppingProductDialog::getNameProduct() {
    return ui->NameEdit->text();
}

void AddShoppingProductDialog::on_AddCategoryButton_clicked() {

}

void AddShoppingProductDialog::on_CategorycomboBox_currentTextChanged(const QString &arg1) {
    category = arg1;
    update();
}

void AddShoppingProductDialog::update() {
    if (setCategory) {
        ui->CategorycomboBox->setEnabled(true);
        ui->AddCategoryButton->setEnabled(true);
        ui->CategorycomboBox->clear();

        std::list<QString> catList;
        listOfShoppingList->getCategory(catList);

        for (auto &i : catList) {
            if (category != "" && category == i)
                ui->CategorycomboBox->addItem(i);
        }

        catList.clear();

        for (auto &l : catList) {
            if (category != l)
                ui->CategorycomboBox->addItem(l);
        }
    } else {
        ui->CategorycomboBox->setEnabled(false);
        ui->AddCategoryButton->setEnabled(false);
    }
}

void AddShoppingProductDialog::attach() {
    listOfShoppingList->addObserver(this);
}

void AddShoppingProductDialog::detach() {
    listOfShoppingList->removeObserver(this);
}

void AddShoppingProductDialog::closeEvent(QCloseEvent *event) {
    detach();
    QDialog::closeEvent(event);
}

void AddShoppingProductDialog::on_CategoryCheckBox_stateChanged(int arg1) {
    if (arg1)
        setCategory = true;
    else
        setCategory = false;

    update();
}
