#include "../file_h/alertwindow.h"
#include "../file_ui/ui_alertwindow.h"

AlertWindow::AlertWindow(ActivityListController *c, QString cat, QWidget *parent) :
        controller(c), category(cat), QDialog(parent),
        ui(new Ui::AlertWindow) {
    ui->setupUi(this);
}

AlertWindow::~AlertWindow() {
    delete ui;
}

void AlertWindow::on_ButtonElimina_clicked() {
    controller->removeCategoryAndActivity(category);
    this->close();
}

void AlertWindow::on_ButtonSposta_clicked() {
    controller->removeAndMoveActivity(category);
    this->close();
}
