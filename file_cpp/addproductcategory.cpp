#include "../file_h/addproductcategory.h"
#include "../file_ui/ui_addproductcategory.h"

addProductCategory::addProductCategory(ListOfShoppingListController *c, QWidget *parent) :
        controller(c), QDialog(parent),
        ui(new Ui::addProductCategory) {
    ui->setupUi(this);
    setWindowTitle("Aggiungi categoria di prodotti");
}

addProductCategory::~addProductCategory() {
    delete ui;
}

void addProductCategory::on_AddButton_clicked() {
    QString name = ui->lineEdit->text();

    if (ui->lineEdit->text().replace(" ", "") != "") {

        if (controller->findCategory(name)) {
            ui->lineEdit->setText("Nome già utilizzato");
        } else if (ui->lineEdit->text() != "Nome già utilizzato"
                   && ui->lineEdit->text() != "Inserisci nome categoria") {
            controller->addCategory(name);
            this->close();
        }
    } else
        ui->lineEdit->setText("Inserisci nome categoria");
}
