#include "activityview.h"
#include "ui_activityview.h"


ActivityView::ActivityView(Activity *a, ActivityListController *c, QWidget *parent) :
        activity(a), controller(c), QDialog(parent),
        ui(new Ui::ActivityView) {
    ui->setupUi(this);

    setWindowTitle(activity->getTask());

    ui->DateEdit->setDate(activity->getDate());
    ui->DeadlineDateEdit->setDate(activity->getDeadlineDate());
    ui->NoteEdit->setText(activity->getNote());

    if (activity->isCompleted())
        ui->CompletedCheckBox->setCheckState(Qt::Checked);

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
    auto subA = new SubActivity();

    auto actController = new ActivityController(activity, subA);

    auto dialog = new AddSubActivityDialog(actController);

    while (dialog->exec()) {

        if (dialog->close()) {

            delete dialog;
            delete actController;
        }
    }

}

void ActivityView::on_DeleteButton_clicked() {
    detach();
    controller->remove();
    this->close();
}


void ActivityView::update() {

    if (activity->isCompleted())
        ui->CompletedCheckBox->setCheckState(Qt::Checked);
    else
        ui->CompletedCheckBox->setCheckState(Qt::Unchecked);

    ui->SubActivityListWidget->clear();

    for (auto i : activity->getSubActivities()) {
        auto subA = new QListWidgetTemplate<SubActivity>;

        subA->setText((*i).getTask());

        if (i->isCompleted())
            subA->setCheckState(Qt::Checked);
        else
            subA->setCheckState(Qt::Unchecked);

        subA->set(i);

        ui->SubActivityListWidget->addItem(subA);
    }
}

void ActivityView::attach() {
    activity->addObserver(this);
}

void ActivityView::detach() {
    activity->removeObserver(this);
}

void ActivityView::on_CompletedCheckBox_stateChanged(int arg1) {
    if (arg1 == 0)
        activity->setCompleted(false);

    if (arg1 == 2)
        activity->setCompleted(true);
}


