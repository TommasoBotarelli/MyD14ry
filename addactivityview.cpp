#include "addactivityview.h"
#include "ui_addactivityview.h"


AddActivityView::AddActivityView(Activity *a, ActivityListController *actListC, QWidget *parent) :
        activity(a), controller(actListC), QDialog(parent),
        ui(new Ui::AddActivityView) {
    ui->setupUi(this);
    ui->StartDateEdit->setDate(QDate::currentDate());
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
        controller->setData(getTask(), getDate(), getDeadlineDate(), false, getNote());
        detach();
        (*this).close();
    }

}

void AddActivityView::on_AddSubActivityButton_clicked() {
    auto subA = new SubActivity();

    auto c = new ActivityController(activity, subA);

    auto dialog = new AddSubActivityDialog(c);

    while (dialog->exec()) {

        if (dialog->close()) {

            delete dialog;
            delete c;
        }
    }
}

void AddActivityView::update() {
    ui->SubActivityListWidget->clear();

    for (auto i : activity->getSubActivities()) {
        auto subA = new QListWidgetTemplate<SubActivity>;

        subA->setText((*i).getTask());
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


QDate AddActivityView::getDate() {
    return ui->StartDateEdit->date();
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

