#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(ActivityList *actList, Calendar *cal, ListOfShoppingList *sL,
                       ActivityListController *actListC,
                       CalendarController *calC,
                       ListOfShoppingListController *shopLC,
                       QWidget *parent)
        : activityList(actList),
          calendar(cal),
          shopList(sL),
          activityListController(actListC),
          calendarController(calC),
          shopListController(shopLC),
          QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    attach();

    auto c = new Category;
    c->setName("VARIE");
    activityList->addCategory(*c);

    update();
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_actionActivity_triggered() {

    std::shared_ptr<Activity> a(new Activity);

    auto dialog = new AddActivityView(activityList, a, activityListController);

    while (dialog->exec()) {
        if (dialog->close()) {
            delete dialog;
        }
    }

}

void MainWindow::on_actionEvent_triggered() {
    std::shared_ptr<Event> e(new Event);

    auto dialog = new AddEventDialog(calendarController, e);

    while (dialog->exec()) {
        if (dialog->close()) {
            delete dialog;
        }
    }
}

void MainWindow::on_actionLista_della_spesa_triggered() {
    std::shared_ptr<ShoppingList> s(new ShoppingList);

    auto dialog = new AddShoppingListDialog(s, shopListController);

    while (dialog->exec()) {
        if (dialog->close()) {
            delete dialog;
        }
    }
}

void MainWindow::on_calendarWidget_clicked(const QDate &date) {
    update();
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item) {
    if (QListWidgetTemplate<Activity> *actItem = dynamic_cast<QListWidgetTemplate<Activity> *>(item)) {

        auto dialog = new ActivityView(activityList, actItem->get(), activityListController);

        while (dialog->exec()) {
            if (dialog->close()) {
                delete dialog;
            }
        }

    }
}

void MainWindow::on_listWidget_itemChanged(QListWidgetItem *item) {
    if (QListWidgetTemplate<Activity> *actItem = dynamic_cast<QListWidgetTemplate<Activity> *>(item)) {

        if (actItem->checkState() == Qt::Checked)
            actItem->get()->setCompleted(true);
        if (actItem->checkState() == Qt::Unchecked)
            actItem->get()->setCompleted(false);

        update();
    }
}

void MainWindow::on_listWidget_2_itemDoubleClicked(QListWidgetItem *item) {
    if (QListWidgetTemplate<Event> *eventItem = dynamic_cast<QListWidgetTemplate<Event> * >(item)) {

        auto dialog = new EventView(eventItem->get(), calendarController);

        while (dialog->exec()) {
            if (dialog->close()) {
                delete dialog;
            }
        }
    }

}

void MainWindow::on_listWidget_3_itemDoubleClicked(QListWidgetItem *item) {
    if (QListWidgetTemplate<ShoppingList> *shopListItem = dynamic_cast<QListWidgetTemplate<ShoppingList> * >(item)) {

        auto dialog = new ShoppingListView(shopListItem->get(), shopListController);  //FIXME

        while (dialog->exec()) {
            if (dialog->close()) {
                delete dialog;
            }
        }
    }
}

void MainWindow::update() {
    ui->listWidget->clear();

    std::list<std::shared_ptr<Activity>> actList;
    std::list<Category> catList;

    activityList->getCategory(catList);

    QFont font;
    font.setWeight(81);

    QFont strikethroughFont;
    strikethroughFont.setStrikeOut(true);

    for (auto i : catList) {
        auto title = new QListWidgetItem;
        title->setText(i.getName());
        title->setFont(font);
        title->setBackground(Qt::yellow);
        title->setFlags(title->flags());
        ui->listWidget->addItem(title);

        actList.clear();
        i.getActivity(actList);

        for (const auto &l : actList) {
            auto act = new QListWidgetTemplate<Activity>;

            act->set(l);

            act->setText(l->getTask());

            if (l->isCompleted()) {
                act->setFont(strikethroughFont);
            }

            ui->listWidget->addItem(act);
        }

    }

    ui->listWidget_2->clear();
    std::list<std::shared_ptr<Event>> eList;
    calendar->getListOfDay(ui->calendarWidget->selectedDate(), eList);
    if (!eList.empty()) {
        calendarController->searchEventOfDay(ui->calendarWidget->selectedDate(), *ui->listWidget_2);
    }

    ui->listWidget_3->clear();
    std::list<std::shared_ptr<ShoppingList>> sList;
    shopList->getList(sList);
    if (!sList.empty()) {
        shopListController->getLists(*ui->listWidget_3);
    }

    QDate day(ui->calendarWidget->yearShown(), ui->calendarWidget->monthShown(), 1);
    QTextCharFormat format;
    QTextCharFormat defaultFormat;
    format.setBackground(Qt::green);
    int d = day.day();

    while (d != day.daysInMonth()) {

        eList.clear();
        calendar->getListOfDay(day, eList);

        if (!eList.empty())
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

void MainWindow::on_calendarWidget_currentPageChanged(int year, int month) {
    update();
}

void MainWindow::on_findButton_clicked() {
    auto dialog = new findDialog(activityList, calendar, shopList, activityListController, calendarController,
                                 shopListController);

    while (dialog->exec()) {
        if (dialog->close())
            delete dialog;
    }

}
