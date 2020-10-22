#include "eventview.h"
#include "ui_eventview.h"

EventView::EventView(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::EventView) {
    ui->setupUi(this);
}

EventView::~EventView() {
    delete ui;
}

void EventView::on_DeleteButton_clicked() {

}
