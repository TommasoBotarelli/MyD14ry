#include "../file_h/addactivityview.h"
#include "../file_ui/ui_addactivityview.h"


AddActivityView::AddActivityView(ActivityList *aList, std::shared_ptr<Activity> a, ActivityListController *actListC,
                                 QWidget *parent) :
        actList(aList), controller(actListC), QDialog(parent),
        activity(a), ui(new Ui::AddActivityView) {
    ui->setupUi(this);
    ui->DeadlineDateEdit->setDate(QDate::currentDate());
    updateCategory();
    on_DeadlineCheckBox_stateChanged(0);
    attach();
}

AddActivityView::~AddActivityView() {
    detach();

    delete ui;
}

void AddActivityView::on_AddActivityButton_clicked() {

    QString name = getTask();

    if (getTask().replace(" ", "") != "") {
        if (name != "Inserire nome attività") {
            controller->setData(getCategory(), activity, name, getDeadlineDate(), false, getNote());
            detach();
            (*this).close();
        }
    } else
        ui->NameEdit->setText("Inserire nome attività");

}

void AddActivityView::on_AddSubActivityButton_clicked() {

    auto dialog = new AddSubActivityDialog(activity, controller); //FIXME

    while (dialog->exec()) {

        if (dialog->close()) {

            delete dialog;
        }
    }
}

void AddActivityView::update() {
    ui->SubActivityListWidget->clear();
    std::list<std::shared_ptr<SubActivity>> listSubA;
    activity->getSubActivities(listSubA);

    for (auto i : listSubA) {
        auto subA = new QListWidgetTemplate<SubActivity>;

        subA->setText(i->getTask());
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
    actList->removeObserver(this);
}

QDate AddActivityView::getDeadlineDate() {
    QDate date(0, 1, 1);

    if (activity->isHasDeadlineDate()) {
        return ui->DeadlineDateEdit->date();
    } else {
        return date;
    }
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

void AddActivityView::on_DeadlineCheckBox_stateChanged(int arg1) {
    if (arg1 == 0) {
        ui->DeadlineDateEdit->setEnabled(false);

        activity->setHasDeadlineDate(false);
    }

    if (arg1 == 2) {
        ui->DeadlineDateEdit->setEnabled(true);

        activity->setHasDeadlineDate(true);
    }

}
