#include "file_h/finddialog.h"
#include "../file_ui/ui_finddialog.h"

findDialog::findDialog(ActivityList *actList, Calendar *c, ListOfShoppingList *shopList,
                       ActivityListController *c1,
                       CalendarController *c2,
                       ListOfShoppingListController *c3,
                       QWidget *parent) : activityList(actList),
                                          calendar(c),
                                          listOfShoppingList(shopList),
                                          actListController(c1),
                                          calendarController(c2),
                                          shopListController(c3),
                                          QDialog(parent),
                                          ui(new Ui::findDialog) {
    ui->setupUi(this);
    attach();
    update();
}

findDialog::~findDialog() {
    delete ui;
}

void findDialog::on_findLineEdit_textChanged(const QString &arg1) {
    update();
}

void findDialog::on_listWidget_itemDoubleClicked(QListWidgetItem *item) {
    if (QListWidgetTemplate<Activity> *actItem = dynamic_cast<QListWidgetTemplate<Activity> * >(item)) {
        auto dialog = new ActivityView(activityList, actItem->get(), actListController);

        actItem->get()->addObserver(this);

        while (dialog->exec()) {
            if (dialog->close()) {
                delete dialog;
            }
        }
    } else if (QListWidgetTemplate<Event> *eventItem = dynamic_cast<QListWidgetTemplate<Event> * >(item)) {
        auto dialog = new EventView(eventItem->get(), calendarController);

        while (dialog->exec()) {
            if (dialog->close()) {
                delete dialog;
            }
        }
    } else if (QListWidgetTemplate<ShoppingList> *shopListItem = dynamic_cast<QListWidgetTemplate<ShoppingList> * >(item)) {
        auto dialog = new ShoppingListView(shopListItem->get(), shopListController, listOfShoppingList);

        shopListItem->get()->addObserver(this);

        while (dialog->exec()) {
            if (dialog->close()) {
                delete dialog;
            }
        }
    } else if (QListWidgetTemplate<ShoppingProduct> *shopProductItem = dynamic_cast<QListWidgetTemplate<ShoppingProduct> * >(item)) {
        QListWidget list;
        list.clear();
        std::list<std::shared_ptr<ShoppingProduct>> shoppingProductList;
        shopListController->getLists(list);

        for (int index = 0; index != list.count(); index++) {

            shoppingProductList.clear();
            list.setCurrentRow(index);

            if (QListWidgetTemplate<ShoppingList> *shopListItem = dynamic_cast<QListWidgetTemplate<ShoppingList> * >(list.currentItem())) {
                shopListItem->get()->getProducts(shoppingProductList);

                for (auto &i : shoppingProductList) {

                    if (shopProductItem->get()->getName() == i->getName()) {
                        auto dialog = new ShoppingListView(shopListItem->get(), shopListController, listOfShoppingList);

                        shopListItem->get()->addObserver(this);

                        while (dialog->exec()) {
                            if (dialog->close()) {
                                delete dialog;
                            }
                        }
                    }
                }

            }
        }
    }
}

void findDialog::update() {
    ui->listWidget->clear();
    int count = 0;

    QString name = ui->findLineEdit->text();
    std::list<Category> catList;
    std::list<std::shared_ptr<Activity>> actList;
    activityList->getCategory(catList);
    QFont font;
    font.setWeight(81);

    auto paragraph1 = new QListWidgetItem;
    paragraph1->setText("ATTIVITÀ");
    paragraph1->setFont(font);
    paragraph1->setBackground(Qt::yellow);
    ui->listWidget->addItem(paragraph1);


    for (auto i : catList) {
        actList.clear();
        i.getActivity(actList);

        auto title = new QListWidgetItem;
        title->setText(i.getName());
        title->setFont(font);

        ui->listWidget->addItem(title);
        ui->listWidget->setCurrentItem(title);

        for (const auto &l : actList) {
            if (isSimilar(l->getTask(), name)) {
                auto actitem = new QListWidgetTemplate<Activity>;
                actitem->set(l);
                actitem->setText(l->getTask());

                if (l->isCompleted())
                    actitem->setCheckState(Qt::Checked);
                else
                    actitem->setCheckState(Qt::Unchecked);

                ui->listWidget->addItem(actitem);
                ui->listWidget->setCurrentItem(actitem);
                count++;
            }
        }

        if (ui->listWidget->currentItem() != nullptr && ui->listWidget->currentItem()->text() == title->text()) {
            ui->listWidget->removeItemWidget(ui->listWidget->currentItem());
            delete ui->listWidget->currentItem();
        }
    }

    ui->listWidget->setCurrentItem(paragraph1);

    if (count == 0)
        delete ui->listWidget->currentItem();

    count = 0;

    auto paragraph2 = new QListWidgetItem;
    paragraph2->setText("EVENTI");
    paragraph2->setFont(font);
    paragraph2->setBackground(Qt::yellow);
    ui->listWidget->addItem(paragraph2);

    std::list<std::shared_ptr<Event>> eventList;
    calendar->getEvent(eventList);

    for (auto &j : eventList) {
        if (isSimilar(j->getTask(), name)) {
            auto eventitem = new QListWidgetTemplate<Event>;
            eventitem->set(j);

            if (j->isAllDay())
                eventitem->setText(j->getTask() + "  (Tutto il giorno)");
            else
                eventitem->setText(j->getTask() + "  (" + j->getStartTime().toString("hh:mm") + " - " +
                                   j->getEndTime().toString("hh:mm") + ")");

            ui->listWidget->addItem(eventitem);
            count++;
        }
    }

    ui->listWidget->setCurrentItem(paragraph2);

    if (count == 0)
        delete ui->listWidget->currentItem();

    count = 0;


    auto paragraph3 = new QListWidgetItem;
    paragraph3->setText("LISTE");
    paragraph3->setFont(font);
    paragraph3->setBackground(Qt::yellow);
    ui->listWidget->addItem(paragraph3);

    std::list<std::shared_ptr<ShoppingList>> shopList;
    listOfShoppingList->getList(shopList);

    for (auto &k : shopList) {
        if (isSimilar(k->getNameList(), name)) {
            auto shopListitem = new QListWidgetTemplate<ShoppingList>;
            shopListitem->set(k);
            shopListitem->setText(k->getNameList() + "     " + "(" + QString::number(k->getCountProduct()) + ")");
            ui->listWidget->addItem(shopListitem);
            count++;
        }
    }

    ui->listWidget->setCurrentItem(paragraph3);

    if (count == 0)
        delete ui->listWidget->currentItem();

    count = 0;

    auto paragraph4 = new QListWidgetItem;
    paragraph4->setText("PRODOTTI");
    paragraph4->setFont(font);
    paragraph4->setBackground(Qt::yellow);
    ui->listWidget->addItem(paragraph4);

    shopList.clear();
    listOfShoppingList->getList(shopList);
    std::list<std::shared_ptr<ShoppingProduct>> shopProductList;

    for (auto &y : shopList) {
        shopProductList.clear();
        y->getProducts(shopProductList);

        for (auto &q : shopProductList) {

            if (isSimilar(q->getName(), name)) {

                auto shopProductitem = new QListWidgetTemplate<ShoppingProduct>;
                shopProductitem->set(q);
                shopProductitem->setText(q->getName());

                if (q->isCatched())
                    shopProductitem->setCheckState(Qt::Checked);
                else
                    shopProductitem->setCheckState(Qt::Unchecked);

                ui->listWidget->addItem(shopProductitem);
                count++;

            }
        }
    }

    ui->listWidget->setCurrentItem(paragraph4);

    if (count == 0)
        delete ui->listWidget->currentItem();
}

void findDialog::attach() {
    activityList->addObserver(this);
    calendar->addObserver(this);
    listOfShoppingList->addObserver(this);
}

void findDialog::detach() {
    activityList->removeObserver(this);
    calendar->removeObserver(this);
    listOfShoppingList->removeObserver(this);
}

bool findDialog::isSimilar(QString a, QString b, qreal percentage, int n, Qt::CaseSensitivity caseSense) {

    if (a.isEmpty() || b.isEmpty())
        return false;

    qreal hits = 0;
    a = QString(" ").repeated(n - 1) + a + QString(" ").repeated(n - 1);
    b = QString(" ").repeated(n - 1) + b + QString(" ").repeated(n - 1);
    QString part;

    for (int i = 0; i < a.count() - (n - 1); i++) {
        part = a.mid(i, n);
        if (b.contains(part, caseSense)) hits++;
    }

    if (a.length() < b.length())
        return (percentage < (100 * hits / (a.length() - (n - 1))));
    else
        return (percentage < (100 * hits / (b.length() - (n - 1))));
}

void findDialog::on_listWidget_itemChanged(QListWidgetItem *item) {
    if (QListWidgetTemplate<Activity> *actItem = dynamic_cast<QListWidgetTemplate<Activity> * >(item)) {
        if (actItem->checkState() == Qt::Checked)
            actItem->get()->setCompleted(true);
        if (actItem->checkState() == Qt::Unchecked)
            actItem->get()->setCompleted(false);
    } else if (QListWidgetTemplate<ShoppingProduct> *shopProductItem = dynamic_cast<QListWidgetTemplate<ShoppingProduct> * >(item)) {
        std::list<std::shared_ptr<ShoppingList>> shopList;
        std::list<std::shared_ptr<ShoppingProduct>> productList;
        listOfShoppingList->getList(shopList);

        for (auto &i : shopList) {
            productList.clear();
            i->getProducts(productList);

            for (auto &j : productList) {
                if (j == shopProductItem->get()) {

                    if (shopProductItem->checkState() == Qt::Checked)
                        shopListController->setCatched(i, shopProductItem->get(), true);

                    else if (shopProductItem->checkState() == Qt::Unchecked)
                        shopListController->setCatched(i, shopProductItem->get(), false);
                }
            }
        }
    }
}

void findDialog::closeEvent(QCloseEvent *event) {
    detach();
    QDialog::closeEvent(event);
}
