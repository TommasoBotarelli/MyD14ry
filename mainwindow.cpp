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

    while (dialog->exec()) {
        if (dialog->close()) {
            delete dialog;
            delete activityListController;
        }
    }

}

void MainWindow::on_actionEvent_triggered() {
    auto e = new Event();

    calendarController = new CalendarController(calendar, e);

    auto dialog = new AddEventDialog(calendarController, e);

    while (dialog->exec()) {
        if (dialog->close()) {
            delete dialog;
            delete calendarController;
        }
    }
}

void MainWindow::on_actionLista_della_spesa_triggered() {
    auto s = new ShoppingList();

    shopListController = new ListOfShoppingListController(s, shopList);

    auto dialog = new AddShoppingListDialog(s, shopListController);

    while (dialog->exec()) {
        if (dialog->close()) {
            delete dialog;
            delete shopListController;
        }
    }
}

void MainWindow::on_calendarWidget_clicked(const QDate &date) {
    update();
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item) {
    if (QListWidgetTemplate<Activity> *actItem = dynamic_cast<QListWidgetTemplate<Activity> *>(item)) {

        activityListController = new ActivityListController(activityList, actItem->get());

        auto dialog = new ActivityView(actItem->get(), activityListController);

        while (dialog->exec()) {
            if (dialog->close()) {
                delete dialog;
                delete activityListController;
            }
        }

    }
}

void MainWindow::on_listWidget_itemChanged(QListWidgetItem *item) {
    if (QListWidgetTemplate<Activity> *actItem = dynamic_cast<QListWidgetTemplate<Activity> *>(item)) {

        if (actItem->checkState() == 2)
            actItem->get()->setCompleted(true);
        else if (actItem->checkState() == 0)
            actItem->get()->setCompleted(false);

        update();
    }
}

void MainWindow::on_listWidget_2_itemDoubleClicked(QListWidgetItem *item) {
    if (QListWidgetTemplate<Event> *eventItem = dynamic_cast<QListWidgetTemplate<Event> * >(item)) {

        calendarController = new CalendarController(calendar, eventItem->get());

        auto dialog = new EventView(eventItem->get(), calendarController);

        while (dialog->exec()) {
            if (dialog->close()) {
                delete dialog;
                delete calendarController;
            }
        }
    }

}

void MainWindow::on_listWidget_3_itemDoubleClicked(QListWidgetItem *item) {
    if (QListWidgetTemplate<ShoppingList> *shopListItem = dynamic_cast<QListWidgetTemplate<ShoppingList> * >(item)) {

        shopListController = new ListOfShoppingListController(shopListItem->get(), shopList);

        auto dialog = new ShoppingListView(shopListItem->get(), shopListController);

        while (dialog->exec()) {
            if (dialog->close()) {
                delete dialog;
                delete shopListController;
            }
        }
    }
}

void MainWindow::update() {
    ui->listWidget->clear();
    if (!activityList->getActivity().empty()) {
        activityListController->searchActivityOfDay(ui->calendarWidget->selectedDate(), *ui->listWidget);
    }

    ui->listWidget_2->clear();
    if (!calendar->getEvent().empty()) {
        calendarController->searchEventOfDay(ui->calendarWidget->selectedDate(), *ui->listWidget_2);
    }

    ui->listWidget_3->clear();
    if (!shopList->getList().empty()) {
        shopListController->getLists(*ui->listWidget_3);
    }

    QDate day(ui->calendarWidget->yearShown(), ui->calendarWidget->monthShown(), 1);
    QTextCharFormat format;
    QTextCharFormat defaultFormat;
    format.setBackground(Qt::green);
    int d = day.day();

    while (d != day.daysInMonth()) {

        if (!activityList->getListOfDay(day).empty() || !calendar->getListOfDay(day).empty())
            ui->calendarWidget->setDateTextFormat(day, format);
        else
            ui->calendarWidget->setDateTextFormat(day, defaultFormat);

        day.setDate(ui->calendarWidget->yearShown(), ui->calendarWidget->monthShown(), d++);
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

void MainWindow::on_calendarWidget_currentPageChanged(int year, int month) {
    update();
}
