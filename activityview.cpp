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
    if (QListWidgetSubActivity *subAitem = dynamic_cast<QListWidgetSubActivity *>(item)) {

        if (subAitem->checkState() == 2)
            subAitem->getSubActivity()->setCompleted(true);
        else if (subAitem->checkState() == 0)
            subAitem->getSubActivity()->setCompleted(false);

        update();
    }
}

void ActivityView::on_AddSubactivityButton_clicked() {
    auto subA = new SubActivity();

    auto actController = new ActivityController(activity, subA);

    auto dialog = new AddSubActivityDialog(actController);
    dialog->exec();
}

void ActivityView::on_DeleteButton_clicked() {
    controller->remove();

    this->close();
}


void ActivityView::update() {

    if (activity->isCompleted())
        ui->CompletedCheckBox->setCheckState(Qt::Checked);

    ui->SubActivityListWidget->clear();

    for (auto i : activity->getSubActivities()) {
        auto subA = new QListWidgetSubActivity();

        subA->setText((*i).getTask());

        if (i->isCompleted())
            subA->setCheckState(Qt::Checked);
        else
            subA->setCheckState(Qt::Unchecked);

        subA->setSubActivity(i);

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


