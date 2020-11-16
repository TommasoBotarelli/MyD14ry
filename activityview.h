#ifndef ACTIVITYVIEW_H
#define ACTIVITYVIEW_H

#include <QDialog>
#include <QListWidgetItem>
#include "SubActivity.h"
#include "ActivityController.h"
#include "addsubactivitydialog.h"
#include "Observer.h"
#include "QListWidgetSubActivity.h"
#include "ActivityListController.h"

namespace Ui {
    class ActivityView;
}

class ActivityView : public QDialog, public Observer {
Q_OBJECT

public:
    explicit ActivityView(Activity *a, ActivityListController *, QWidget *parent = nullptr);

    ~ActivityView() override;

private slots:

    void on_SubActivityListWidget_itemChanged(QListWidgetItem *item);

    void on_AddSubactivityButton_clicked();

    void on_DeleteButton_clicked();

    void on_CompletedCheckBox_stateChanged(int arg1);

public:
    void update() override;

    void attach() override;

    void detach() override;

private:
    Ui::ActivityView *ui;

    std::list<Observer *> observers;

    ActivityListController *controller;

    Activity *activity;
};

#endif // ACTIVITYVIEW_H
