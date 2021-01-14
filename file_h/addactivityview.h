#ifndef ADDACTIVITYVIEW_H
#define ADDACTIVITYVIEW_H

#include <QDialog>
#include <QListWidget>
#include <QDate>
#include <QString>
#include "Observer.h"
#include "ActivityListController.h"
#include "addsubactivitydialog.h"
#include "memory"
#include "QListWidgetTemplate.h"
#include "addcategory.h"

namespace Ui {
    class AddActivityView;
}

class AddActivityView : public QDialog, public Observer {
Q_OBJECT

public:
    explicit AddActivityView(ActivityList *aList, std::shared_ptr<Activity> a, ActivityListController *actListC,
                             QWidget *parent = nullptr);

    ~AddActivityView() override;

    QDate getDeadlineDate();

    QString getTask();

    QString getNote();

    QString getCategory();

    void update() override;

    void attach() override;

    void detach() override;

    void updateCategory();

private slots:

    void on_AddActivityButton_clicked();

    void on_AddSubActivityButton_clicked();

    void on_addCategoryButton_clicked();

private:
    Ui::AddActivityView *ui;

    ActivityList *actList;

    std::shared_ptr<Activity> activity;

    ActivityListController *controller;
};

#endif // ADDACTIVITYVIEW_H
