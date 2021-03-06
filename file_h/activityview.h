#ifndef ACTIVITYVIEW_H
#define ACTIVITYVIEW_H

#include <QDialog>
#include <QListWidgetItem>
#include "SubActivity.h"
#include "addsubactivitydialog.h"
#include "Observer.h"
#include "file_h/ActivityListController.h"
#include "QListWidgetTemplate.h"
#include "addcategory.h"

namespace Ui {
    class ActivityView;
}

class ActivityView : public QDialog, public Observer {
Q_OBJECT

public:
    explicit ActivityView(ActivityList *actList, std::shared_ptr<Activity> a, ActivityListController *,
                          QWidget *parent = nullptr);

    ~ActivityView() override;

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:

    void on_SubActivityListWidget_itemChanged(QListWidgetItem *item);

    void on_AddSubactivityButton_clicked();

    void on_DeleteButton_clicked();

    void on_CompletedCheckBox_stateChanged(int arg1);

    void on_addCategoryButton_clicked();

    void on_DeleteSubActivity_clicked();

public:
    void update() override;

    void attach() override;

    void detach() override;

    void updateCategory();

private:
    Ui::ActivityView *ui;

    std::list<Observer *> observers;

    ActivityListController *controller;

    std::shared_ptr<Activity> activity;

    ActivityList *activityList;

    QString category;
};

#endif // ACTIVITYVIEW_H
