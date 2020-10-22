#include "addactivityview.h"
#include "ui_addactivityview.h"

AddActivityView::AddActivityView(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::AddActivityView) {
    ui->setupUi(this);
}

AddActivityView::~AddActivityView() {
    delete ui;
}

void AddActivityView::on_AddActivityButton_clicked() {

}

void AddActivityView::on_AddSubActivityButton_clicked() {

}
