#include "alertwindow.h"
#include "ui_alertwindow.h"

AlertWindow::AlertWindow(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::AlertWindow) {
    ui->setupUi(this);
}

AlertWindow::~AlertWindow() {
    delete ui;
}

void AlertWindow::on_ButtonElimina_clicked() {
    cancel = true;
    this->close();
}

void AlertWindow::on_ButtonSposta_clicked() {
    cancel = false;
    this->close();
}
