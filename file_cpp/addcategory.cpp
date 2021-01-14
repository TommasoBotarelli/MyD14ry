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
    if (controller->findCategory(ui->lineEdit->text())) {
        ui->lineEdit->setText("Nome della lista già utilizzato");
    } else {
        auto c = new Category;
        controller->setData(*c, ui->lineEdit->text());
        this->close();
    }
}
