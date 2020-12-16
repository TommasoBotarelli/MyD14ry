#ifndef ADDACTIVITYVIEW_H
#define ADDACTIVITYVIEW_H

#include <QDialog>
#include <QListWidget>
#include <QDate>
#include <QString>
#include "Observer.h"
#include "ActivityListController.h"
#include "ActivityController.h"
#include "addsubactivitydialog.h"
#include "memory"
#include "QListWidgetTemplate.h"

namespace Ui {
    class AddActivityView;
}

class AddActivityView : public QDialog, public Observer {
Q_OBJECT

public:
    explicit AddActivityView(Activity *a, ActivityListController *actListC, QWidget *parent = nullptr);

    ~AddActivityView() override;

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

    void on_categoryComboBox_textActivated(const QString &arg1);

    void on_addCategoryButton_clicked();

private:
    Ui::AddActivityView *ui;

    Activity *activity;

    ActivityListController *controller;
};

#endif // ADDACTIVITYVIEW_H
