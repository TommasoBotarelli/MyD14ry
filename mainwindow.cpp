#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(ActivityList *actList, Calendar *cal, QWidget *parent)
        : activityList(actList),
          calendar(cal), QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    attach();
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_actionActivity_triggered() {

    auto a = new Activity();

    activityListController = new ActivityListController(activityList, a);

    auto dialog = new AddActivityView(a, activityListController);

    dialog->exec();

}

void MainWindow::on_actionEvent_triggered() {
    auto e = new Event();

    calendarController = new CalendarController(calendar, e);

    auto dialog = new AddEventDialog(calendarController, e);
    dialog->exec();
}

void MainWindow::on_actionLista_della_spesa_triggered() {

}

void MainWindow::on_calendarWidget_clicked(const QDate &date) {
    update();
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item) {
    if (QListWidgetActivity *actItem = dynamic_cast<QListWidgetActivity *>(item)) {

        activityListController = new ActivityListController(activityList, actItem->getActivity());

        auto dialog = new ActivityView(actItem->getActivity(), activityListController);

        while (dialog->exec()) {
            if (dialog->close()) {
                delete dialog;
                delete activityListController;      //FIXME controllare se tutto ok e cambiare a tutti i metodi che usano il new
            }
        }

    }
}

void MainWindow::on_listWidget_itemChanged(QListWidgetItem *item) {
    if (QListWidgetActivity *actItem = dynamic_cast<QListWidgetActivity *>(item)) {

        if (actItem->checkState() == 2)
            actItem->getActivity()->setCompleted(true);
        else if (actItem->checkState() == 0)
            actItem->getActivity()->setCompleted(false);

        update();
    }
}

void MainWindow::on_listWidget_2_itemDoubleClicked(QListWidgetItem *item) {
    if (QListWidgetEvent *eventItem = dynamic_cast<QListWidgetEvent * >(item)) {

        calendarController = new CalendarController(calendar, eventItem->getEvent());

        auto dialog = new EventView(eventItem->getEvent(), calendarController);

        while (dialog->exec()) {
            if (dialog->close()) {
                delete dialog;
                delete calendarController;      //FIXME controllare se tutto ok e cambiare a tutti i metodi che usano il new
            }
        }
    }

}

void MainWindow::on_listWidget_3_itemDoubleClicked(QListWidgetItem *item) {

}

void MainWindow::update() {
    if (!activityList->getActivity().empty()) {
        ui->listWidget->clear();
        activityListController->searchActivityOfDay(ui->calendarWidget->selectedDate(), *ui->listWidget);
    }

    if (!calendar->getEvent().empty()) {
        ui->listWidget_2->clear();
        calendarController->searchEventOfDay(ui->calendarWidget->selectedDate(), *ui->listWidget_2);
    }
}

void MainWindow::attach() {
    activityList->addObserver(this);  //TODO SERVE ALTRI OBSERVER!!
    calendar->addObserver(this);
}

void MainWindow::detach() {
    activityList->removeObserver(this);
    calendar->removeObserver(this);
}

void MainWindow::on_RefreshButton_clicked() {
    update();
}
