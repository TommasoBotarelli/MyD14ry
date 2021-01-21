#include "file_h/addcategory.h"
#include "../file_ui/ui_addcategory.h"

AddCategory::AddCategory(ActivityListController *c, QWidget *parent) :
        controller(c), QDialog(parent),
        ui(new Ui::AddCategory) {
    ui->setupUi(this);
    setWindowTitle("Aggiungi categoria");
}

AddCategory::~AddCategory() {
    delete ui;
}

void AddCategory::on_addCategoryButton_clicked() {
    QString name = ui->lineEdit->text();

    if (ui->lineEdit->text().replace(" ", "") != "") {

        if (controller->findCategory(name)) {
            ui->lineEdit->setText("Nome della lista già utilizzato");
        } else if (ui->lineEdit->text() != "Nome della lista già utilizzato"
                   && ui->lineEdit->text() != "Inserisci nome categoria") {
            controller->addCategory(ui->lineEdit->text());
            this->close();
        }
    } else
        ui->lineEdit->setText("Inserisci nome categoria");

}
