#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(ActivityList *actList, Calendar *cal, ListOfShoppingList *sL, QWidget *parent)
        : activityList(actList),
          calendar(cal),
          shopList(sL),
          QMainWindow(parent), ui(new Ui::MainWindow) {
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
    auto s = new ShoppingList();

    shopListController = new ListOfShoppingListController(s, shopList);

    auto dialog = new AddShoppingListDialog(s, shopListController);

    dialog->exec();
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
                delete activityListController;
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
                delete calendarController;
            }
        }
    }

}

void MainWindow::on_listWidget_3_itemDoubleClicked(QListWidgetItem *item) {
    if (QListWidgetShoppingList *shopListItem = dynamic_cast<QListWidgetShoppingList * >(item)) {

        shopListController = new ListOfShoppingListController(shopListItem->getShoppingList(), shopList);

        auto dialog = new ShoppingListView(shopListItem->getShoppingList(), shopListController);

        while (dialog->exec()) {
            if (dialog->close()) {
                delete dialog;
                delete shopListController;
            }
        }
    }
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

    if (!shopList->getList().empty()) {
        ui->listWidget_3->clear();
        shopListController->getLists(*ui->listWidget_3);
    }

}

void MainWindow::attach() {
    activityList->addObserver(this);
    calendar->addObserver(this);
    shopList->addObserver(this);
}

void MainWindow::detach() {
    activityList->removeObserver(this);
    calendar->removeObserver(this);
    shopList->removeObserver(this);
}

void MainWindow::on_RefreshButton_clicked() {
    update();
}
