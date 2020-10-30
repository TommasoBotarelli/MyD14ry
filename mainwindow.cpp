#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(ActivityList &actList, QWidget *parent)
        : activityList(actList), QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    attach();
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_actionActivity_triggered() {

    auto a = new Activity();

    activityListController = new ActivityListController(&activityList, a);

    auto dialog = new AddActivityView(a);
    dialog->setController(activityListController);

    dialog->exec();

}

void MainWindow::on_actionEvent_triggered() {

}

void MainWindow::on_actionLista_della_spesa_triggered() {

}

void MainWindow::on_calendarWidget_clicked(const QDate &date) {
    update();
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item) {
    if (QListWidgetActivity *actItem = dynamic_cast<QListWidgetActivity *>(item)) {

        activityListController = new ActivityListController(&activityList, actItem->getActivity());

        auto dialog = new ActivityView(actItem->getActivity(), activityListController);
        dialog->exec();

    }
}

void MainWindow::on_listWidget_itemChanged(QListWidgetItem *item) {
    if (QListWidgetActivity *actItem = dynamic_cast<QListWidgetActivity *>(item)) {

        if (actItem->checkState() == Qt::Checked)
            actItem->getActivity()->setCompleted(true);

        update();
    }
}

void MainWindow::on_listWidget_2_itemDoubleClicked(QListWidgetItem *item) {

}

void MainWindow::on_listWidget_3_itemDoubleClicked(QListWidgetItem *item) {

}

void MainWindow::update() {
    ui->listWidget->clear();

    activityListController->searchActivityOfDay(ui->calendarWidget->selectedDate(), *ui->listWidget);

}

void MainWindow::attach() {
    activityList.addObserver(this);  //TODO SERVE ALTRI OBSERVER!!
}

void MainWindow::detach() {

}
