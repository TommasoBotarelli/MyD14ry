#include "addactivityview.h"
#include "ui_addactivityview.h"


AddActivityView::AddActivityView(Activity *a, ActivityListController *actListC, QWidget *parent) :
        activity(a), controller(actListC), QDialog(parent),
        ui(new Ui::AddActivityView) {
    ui->setupUi(this);
    ui->DeadlineDateEdit->setDate(QDate::currentDate());
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
        controller->setData(*activity, getTask(), getDeadlineDate(), false, getNote());
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
}

void AddActivityView::attach() {
    activity->addObserver(this);
}

void AddActivityView::detach() {
    activity->removeObserver(this);
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


void AddActivityView::on_categoryComboBox_textActivated(const QString &arg1) {

}

void AddActivityView::on_addCategoryButton_clicked() {

}
