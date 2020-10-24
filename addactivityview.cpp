#include "addactivityview.h"
#include "ui_addactivityview.h"

AddActivityView::AddActivityView(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::AddActivityView) {
    ui->setupUi(this);
    ui->StartDateEdit->setDate(QDate::currentDate());
}

AddActivityView::~AddActivityView() {
    delete ui;
}

void AddActivityView::on_AddActivityButton_clicked() {
    //TODO funzione che prende i dati dai relativi widget e richiama il controller per creare attività
}

void AddActivityView::on_AddSubActivityButton_clicked() {
    std::unique_ptr<SubActivity> subA;
    ActivityController(activity, subA.get());

    //TODO finire funzione che apre la finestra di aggiunta di una sotto attività

}

void AddActivityView::update() {
    list.clear();

    for (auto i : activity->getSubActivities()) {
        QListWidgetSubActivity subA;
        subA.setText((*i).getTask());

        if ((*i).isCompleted())
            subA.setCheckState(Qt::Checked);
        else
            subA.setCheckState(Qt::Unchecked);

        subA.setSubActivity(*i);
        list.addItem(subA);
    }
}

void AddActivityView::attach() {
    activity->addObserver(this);
}

void AddActivityView::detach() {
    activity->removeObserver(this);
}