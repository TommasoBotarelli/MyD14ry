#ifndef ADDSUBACTIVITYDIALOG_H
#define ADDSUBACTIVITYDIALOG_H

#include <QDialog>
#include "file_h/ActivityListController.h"
#include "SubActivity.h"
#include <QString>
#include <QWidget>

namespace Ui {
    class AddSubActivityDialog;
}

class AddSubActivityDialog : public QDialog {
Q_OBJECT

public:
    explicit AddSubActivityDialog(std::shared_ptr<Activity> activity, ActivityListController *c,
                                  QWidget *parent = nullptr);

    ~AddSubActivityDialog() override;

    QString getTask();

private slots:

    void on_AddButton_clicked();

private:
    Ui::AddSubActivityDialog *ui;

    std::shared_ptr<Activity> activity;

    ActivityListController *controller;
};

#endif // ADDSUBACTIVITYDIALOG_H
