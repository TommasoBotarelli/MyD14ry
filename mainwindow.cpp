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
    activityList = new ActivityList();
    activityList->addObserver(this);

    auto a = new Activity();

    auto c = new ActivityListController(a, activityList);

    auto dialog = new AddActivityView();
    dialog->setActivity(a);
    dialog->setController(c);

    dialog->exec();

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

void MainWindow::update() {
    ui->listWidget->clear();

    for (auto i : activityList->getListOfDay(ui->calendarWidget->selectedDate())) {
        auto aL = new QListWidgetActivity();
        aL->setText(i->getTask());

        if (i->isCompleted())
            aL->setCheckState(Qt::Checked);
        else
            aL->setCheckState(Qt::Unchecked);

        aL->setActivity(i);
        ui->listWidget->addItem(aL);
    }
}

void MainWindow::attach() {
    activityList->addObserver(this);  //TODO SERVE ALTRI OBSERVER!!
}

void MainWindow::detach() {

}
