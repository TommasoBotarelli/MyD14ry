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

    int countParagraph = 0;

    for (auto i : catList) {
        actList.clear();
        i.getActivity(actList);

        auto title = new QListWidgetItem;
        title->setText(i.getName());
        title->setFont(font);

        ui->listWidget->addItem(title);

        count = 0;

        for (auto &l : actList) {
            if (isSimilar(l->getTask(), name)) {
                auto actitem = new QListWidgetTemplate<Activity>;
                actitem->set(l);
                actitem->setText(l->getTask());

                if (l->isCompleted())
                    actitem->setCheckState(Qt::Checked);
                else
                    actitem->setCheckState(Qt::Unchecked);

                ui->listWidget->addItem(actitem);

                count++;
                countParagraph++;
            }
        }

        ui->listWidget->setCurrentItem(title);

        if (count == 0)
            delete ui->listWidget->currentItem();
    }

    ui->listWidget->setCurrentItem(paragraph1);

    if (countParagraph == 0)
        delete ui->listWidget->currentItem();

    auto paragraph5 = new QListWidgetItem;
    paragraph5->setText("CATEGORIE DI ATTIVITÀ");
    paragraph5->setFont(font);
    paragraph5->setBackground(Qt::yellow);
    ui->listWidget->addItem(paragraph5);

    catList.clear();
    activityList->getCategory(catList);

    int activityCount;
    count = 0;

    for (auto &i : catList) {
        if (isSimilar(i.getName(), name)) {
            count++;

            actList.clear();
            i.getActivity(actList);
            auto title = new QListWidgetItem;
            title->setText(i.getName());
            title->setFont(font);
            ui->listWidget->addItem(title);

            activityCount = 0;

            for (auto &e : actList) {
                auto actitem2 = new QListWidgetTemplate<Activity>;
                actitem2->set(e);
                actitem2->setText(e->getTask());

                if (e->isCompleted())
                    actitem2->setCheckState(Qt::Checked);
                else
                    actitem2->setCheckState(Qt::Unchecked);

                ui->listWidget->addItem(actitem2);
                ui->listWidget->setCurrentItem(actitem2);
                activityCount++;
            }

            if (activityCount == 0)
                ui->listWidget->addItem("Nessuna attività presente");
        }

    }

    ui->listWidget->setCurrentItem(paragraph5);

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

    int countProduct = 0;

    for (auto &y : shopList) {
        countProduct = 0;

        shopProductList.clear();
        y->getProducts(shopProductList);

        auto shopListitem1 = new QListWidgetTemplate<ShoppingList>;
        shopListitem1->set(y);
        shopListitem1->setText("--> " + y->getNameList() + "     " + "(" + QString::number(y->getCountProduct()) + ")");
        ui->listWidget->addItem(shopListitem1);

        for (auto &q : shopProductList) {

            if (isSimilar(q->getName(), name)) {

                countProduct++;

                auto shopProductitem = new QListWidgetTemplate<ShoppingProduct>;
                shopProductitem->set(q);
                shopProductitem->setText(q->getName());

                if (q->isCatched())
                    shopProductitem->setCheckState(Qt::Checked);
                else if (!q->isCatched())
                    shopProductitem->setCheckState(Qt::Unchecked);

                ui->listWidget->addItem(shopProductitem);
                count++;

            }
        }
        ui->listWidget->setCurrentItem(shopListitem1);

        if (countProduct == 0)
            delete ui->listWidget->currentItem();

    }

    ui->listWidget->setCurrentItem(paragraph4);

    if (count == 0)
        delete ui->listWidget->currentItem();


    auto paragraph6 = new QListWidgetItem;
    paragraph6->setText("CATEGORIE DI PRODOTTI");
    paragraph6->setFont(font);
    paragraph6->setBackground(Qt::yellow);
    ui->listWidget->addItem(paragraph6);

    count = 0;

    std::list<QString> catProductList;
    listOfShoppingList->getCategory(catProductList);

    countProduct = 0;
    int countForList = 0;

    for (auto &t : catProductList) {
        if (isSimilar(t, name)) {
            count++;
            shopList.clear();
            listOfShoppingList->getList(shopList);

            auto title = new QListWidgetItem;
            title->setText(t.toUpper());
            title->setFont(font);
            ui->listWidget->addItem(title);

            for (auto &q : shopList) {
                countForList = 0;

                shopProductList.clear();
                q->getProducts(shopProductList);

                auto shopListitem2 = new QListWidgetTemplate<ShoppingList>;
                shopListitem2->set(q);
                shopListitem2->setText(
                        "--> " + q->getNameList() + "     " + "(" + QString::number(q->getCountProduct()) + ")");
                ui->listWidget->addItem(shopListitem2);

                for (auto &a : shopProductList) {

                    if (a->getCategory() == t) {

                        countForList++;

                        auto shopProductitem2 = new QListWidgetTemplate<ShoppingProduct>;
                        shopProductitem2->set(a);
                        shopProductitem2->setText(a->getName());

                        if (a->isCatched())
                            shopProductitem2->setCheckState(Qt::Checked);
                        else
                            shopProductitem2->setCheckState(Qt::Unchecked);

                        ui->listWidget->addItem(shopProductitem2);

                        countProduct++;
                    }
                }

                ui->listWidget->setCurrentItem(shopListitem2);

                if (countForList == 0)
                    delete ui->listWidget->currentItem();
            }

            if (countProduct == 0)
                ui->listWidget->addItem("Nessun prodotto presente");

        }
    }

    ui->listWidget->setCurrentItem(paragraph6);

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
        else if (actItem->checkState() == Qt::Unchecked)
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

                    update();

                    break;
                }
            }
        }
    }
}

void findDialog::closeEvent(QCloseEvent *event) {
    detach();
    QDialog::closeEvent(event);
}
