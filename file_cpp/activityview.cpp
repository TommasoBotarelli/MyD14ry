#include "../file_h/activityview.h"
#include "../file_ui/ui_activityview.h"


ActivityView::ActivityView(ActivityList *actList, std::shared_ptr<Activity> a, ActivityListController *c,
                           QWidget *parent) :
        activityList(actList), activity(a), controller(c), QDialog(parent),
        ui(new Ui::ActivityView) {
    ui->setupUi(this);

    setWindowTitle(activity->getTask());

    ui->DeadlineDateEdit->setDate(activity->getDeadlineDate());
    ui->NoteEdit->setText(activity->getNote());

    if (activity->isCompleted())
        ui->CompletedCheckBox->setCheckState(Qt::Checked);
    if (!activity->isCompleted())
        ui->CompletedCheckBox->setCheckState(Qt::Unchecked);

    this->category = a->getCategory();

    attach();
    update();
}

ActivityView::~ActivityView() {
    detach();

    delete ui;
}

void ActivityView::on_SubActivityListWidget_itemChanged(QListWidgetItem *item) {
    if (QListWidgetTemplate<SubActivity> *subAitem = dynamic_cast<QListWidgetTemplate<SubActivity> *>(item)) {

        if (subAitem->checkState() == 2)
            subAitem->get()->setCompleted(true);
        else if (subAitem->checkState() == 0)
            subAitem->get()->setCompleted(false);

        update();
    }
}

void ActivityView::on_AddSubactivityButton_clicked() {

    auto dialog = new AddSubActivityDialog(activity, controller);         //FIXME

    while (dialog->exec()) {

        if (dialog->close()) {

            delete dialog;
        }
    }

}

void ActivityView::on_DeleteButton_clicked() {
    this->close();
    controller->remove(activity);
}


void ActivityView::update() {

    if (activity->isCompleted())
        ui->CompletedCheckBox->setCheckState(Qt::Checked);
    else
        ui->CompletedCheckBox->setCheckState(Qt::Unchecked);

    ui->SubActivityListWidget->clear();
    std::list<std::shared_ptr<SubActivity>> subAList;
    activity->getSubActivities(subAList);

    for (auto i : subAList) {
        auto subA = new QListWidgetTemplate<SubActivity>;

        subA->setText(i->getTask());

        if (i->isCompleted())
            subA->setCheckState(Qt::Checked);
        else
            subA->setCheckState(Qt::Unchecked);

        subA->set(i);

        ui->SubActivityListWidget->addItem(subA);
    }

    updateCategory();
}

void ActivityView::attach() {
    activity->addObserver(this);
    activityList->addObserver(this);
}

void ActivityView::detach() {
    activity->removeObserver(this);
    activityList->removeObserver(this);
}

void ActivityView::on_CompletedCheckBox_stateChanged(int arg1) {
    if (arg1 == 0)
        activity->setCompleted(false);

    if (arg1 == 2)
        activity->setCompleted(true);
}

void ActivityView::on_addCategoryButton_clicked() {
    auto dialog = new AddCategory(controller);

    while (dialog->exec())
        if (dialog->close()) {
            delete dialog;
        }
}

void ActivityView::updateCategory() {

    //ui->categoryComboBox->clear();                //FIXME

    std::list<Category> catList;
    activityList->getCategory(catList);

    for (Category& i : catList) {
        if (i.getName() == activity->getCategory()){
            ui->categoryComboBox->addItem(i.getName());
            break;
        }
    }

    catList.clear();
    activityList->getCategory(catList);

    for (Category& l : catList) {
        if (l.getName() != activity->getCategory())
            ui->categoryComboBox->addItem(l.getName());
    }
}

void ActivityView::on_categoryComboBox_currentTextChanged(const QString &arg1) {
    this->category = arg1;
    controller->modifyCategory(activity->getCategory(), category, activity);
}

void ActivityView::on_categoryComboBox_currentIndexChanged(int index) {
    //FIXME
}

void ActivityView::closeEvent(QCloseEvent *event) {
    this->detach();
    QDialog::closeEvent(event);
}
