#include "addactivityview.h"
#include "ui_addactivityview.h"


AddActivityView::AddActivityView(ActivityList *aList, ActivityListController *actListC, QWidget *parent) :
        actList(aList), controller(actListC), QDialog(parent),
        ui(new Ui::AddActivityView), activity(new Activity) {
    ui->setupUi(this);
    ui->DeadlineDateEdit->setDate(QDate::currentDate());
    updateCategory();
    attach();
}

AddActivityView::~AddActivityView() {
    detach();

    delete ui;
}

void AddActivityView::on_AddActivityButton_clicked() {

    if (getTask() == "")
        ui->NameEdit->setText("INSERISCI ATTIVITÀ!!!");

    if (getTask() != "INSERISCI ATTIVITÀ!!!" && getTask() != "") {
        controller->setData(getCategory(), *activity, getTask(), getDeadlineDate(), false, getNote());
        detach();
        (*this).close();
    }

}

void AddActivityView::on_AddSubActivityButton_clicked() {

    auto dialog = new AddSubActivityDialog(activity, controller);

    while (dialog->exec()) {

        if (dialog->close()) {

            delete dialog;
        }
    }
}

void AddActivityView::update() {
    ui->SubActivityListWidget->clear();
    std::list<SubActivity> listSubA;
    activity->getSubActivities(listSubA);

    for (auto i : listSubA) {
        auto subA = new QListWidgetTemplate<SubActivity>;

        subA->setText(i.getTask());
        subA->set(i);

        ui->SubActivityListWidget->addItem(subA);
    }

    updateCategory();
}

void AddActivityView::attach() {
    activity->addObserver(this);
    actList->addObserver(this);
}

void AddActivityView::detach() {
    activity->removeObserver(this);
    actList->addObserver(this);
}

QDate AddActivityView::getDeadlineDate() {
    return ui->DeadlineDateEdit->date();
}

QString AddActivityView::getTask() {
    return ui->NameEdit->displayText();
}

QString AddActivityView::getNote() {
    return ui->NoteEdit->toPlainText();
}

void AddActivityView::on_addCategoryButton_clicked() {
    auto dialog = new AddCategory(controller);

    while (dialog->exec())
        if (dialog->close()) {
            delete dialog;
        }
}

QString AddActivityView::getCategory() {
    return ui->categoryComboBox->currentText();
}

void AddActivityView::updateCategory() {
    ui->categoryComboBox->clear();
    std::list<Category> catList;
    actList->getCategory(catList);

    for (auto i : catList)
        ui->categoryComboBox->addItem(i.getName());

}
