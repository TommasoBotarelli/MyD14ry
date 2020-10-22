#include "activityview.h"
#include "ui_activityview.h"

ActivityView::ActivityView(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::ActivityView) {
    ui->setupUi(this);
}

ActivityView::~ActivityView() {
    delete ui;
}

void ActivityView::on_SubActivityListWidget_itemChanged(QListWidgetItem *item) {

}

void ActivityView::on_AddSubactivityButton_clicked() {

}

void ActivityView::on_DeleteButton_clicked() {

}
