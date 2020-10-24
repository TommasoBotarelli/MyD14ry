#ifndef ADDACTIVITYVIEW_H
#define ADDACTIVITYVIEW_H

#include <QDialog>
#include <QListWidget>
#include <QDate>
#include <QString>
#include "Observer.h"
#include "QListWidgetSubActivity.h"
#include "ActivityListController.h"
#include "ActivityController.h"

namespace Ui {
    class AddActivityView;
}

class AddActivityView : public Observer, public QDialog {
Q_OBJECT

public:
    AddActivityView(Activity *activity, ActivityListController *controller, QWidget *parent = nullptr);

    ~AddActivityView();

    QDate getDate();

    QDate getDeadlineDate();

    QString getTask();

    QString getNote();

    void update() override;

    void attach() override;

    void detach() override;

private slots:

    void on_AddActivityButton_clicked();

    void on_AddSubActivityButton_clicked();

private:
    Ui::AddActivityView *ui;

    QListWidget list;

    Activity *activity;

    ActivityListController *controller;
};

#endif // ADDACTIVITYVIEW_H
