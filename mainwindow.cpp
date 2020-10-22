#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_actionActivity_triggered() {

}

void MainWindow::on_actionEvent_triggered() {

}

void MainWindow::on_actionLista_della_spesa_triggered() {

}

void MainWindow::on_calendarWidget_clicked(const QDate &date) {

}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item) {

}

void MainWindow::on_listWidget_itemChanged(QListWidgetItem *item) {

}

void MainWindow::on_listWidget_2_itemDoubleClicked(QListWidgetItem *item) {

}

void MainWindow::on_listWidget_3_itemDoubleClicked(QListWidgetItem *item) {

}
