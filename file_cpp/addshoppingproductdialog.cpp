#include "../file_h/addshoppingproductdialog.h"
#include "../file_ui/ui_addshoppingproductdialog.h"

AddShoppingProductDialog::AddShoppingProductDialog(std::shared_ptr<ShoppingList> sl, ListOfShoppingListController *slc,
                                                   ListOfShoppingList *lsl,
                                                   QWidget *parent)
        :
        shopList(std::move(sl)), controller(slc), listOfShoppingList(lsl), setCategory(false),
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

        if (setCategory) {
            if (name != "Inserire nome prodotto" && ui->CategorycomboBox->currentText() != "") {
                controller->addProduct(shopList, name, ui->CategorycomboBox->currentText(), setCategory);
                this->close();
            }
        } else {
            if (name != "Inserire nome prodotto") {
                controller->addProduct(shopList, name, "", setCategory);
                this->close();
            }
        }
    } else
        ui->NameEdit->setText("Inserire nome prodotto");
}

QString AddShoppingProductDialog::getNameProduct() {
    return ui->NameEdit->text();
}

void AddShoppingProductDialog::on_AddCategoryButton_clicked() {
    auto dialog = new addProductCategory(controller);

    while (dialog->exec()) {
        if (dialog->close()) {
            delete dialog;
        }
    }

    update();
}

void AddShoppingProductDialog::update() {
    if (setCategory) {
        ui->CategorycomboBox->setEnabled(true);
        ui->AddCategoryButton->setEnabled(true);

        ui->CategorycomboBox->clear();

        std::list<QString> catList;
        listOfShoppingList->getCategory(catList);

        for (auto &l : catList)
            ui->CategorycomboBox->addItem(l);

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
