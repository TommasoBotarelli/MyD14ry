#include "addactivityview.h"
#include "ui_addactivityview.h"

//TODO FINIRE METODI GETTER

AddActivityView::AddActivityView(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::AddActivityView) {
    ui->setupUi(this);
    ui->StartDateEdit->setDate(QDate::currentDate());
    ui->DeadlineDateEdit->setDate(QDate::currentDate());
}

AddActivityView::~AddActivityView() {
    delete ui;
}

void AddActivityView::on_AddActivityButton_clicked() {
    //TODO funzione che prende i dati dai relativi widget e richiama il controller per creare attività
}

void AddActivityView::on_AddSubActivityButton_clicked() {
    //TODO finire funzione che apre la finestra di aggiunta di una sotto attività

}

void AddActivityView::update() {
    list.clear();

    for (auto i : activity->getSubActivities()) {
        auto subA = new QListWidgetSubActivity();//FIXME controllare se giusto
        subA->setText((*i).getTask());

        if ((*i).isCompleted())
            subA->setCheckState(Qt::Checked);
        else
            subA->setCheckState(Qt::Unchecked);

        subA->setSubActivity(i);
        list.addItem(subA);
    }
}

void AddActivityView::attach() {
    activity->addObserver(this);
}

void AddActivityView::detach() {
    activity->removeObserver(this);
}

//metodi getter che prelevano informazioni dai widget

QDate AddActivityView::getDate() {
    return QDate();
}

QDate AddActivityView::getDeadlineDate() {
    return QDate();
}

QString AddActivityView::getTask() {
    return QString();
}

QString AddActivityView::getNote() {
    return QString();
}
