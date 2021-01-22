#include "file_h/addsubactivitydialog.h"
#include "../file_ui/ui_addsubactivitydialog.h"

AddSubActivityDialog::AddSubActivityDialog(std::shared_ptr<Activity> act, ActivityListController *c, QWidget *parent) :
        activity(act), controller(c), QDialog(parent),
        ui(new Ui::AddSubActivityDialog) {
    ui->setupUi(this);
}

AddSubActivityDialog::~AddSubActivityDialog() {
    delete ui;
}

void AddSubActivityDialog::on_AddButton_clicked() {
    QString name = getTask();

    if (getTask().replace(" ", "") != "") {

        if (name != "Inserire nome sotto attività") {
            controller->addSubActivity(activity, name, false);
            this->close();
        }
    } else
        ui->NameEdit->setText("Inserire nome sotto attività");
}

QString AddSubActivityDialog::getTask() {
    return ui->NameEdit->text();
}
