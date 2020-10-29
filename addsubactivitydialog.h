#ifndef ADDSUBACTIVITYDIALOG_H
#define ADDSUBACTIVITYDIALOG_H

#include <QDialog>
#include "ActivityController.h"
#include <QString>
#include <QWidget>

namespace Ui {
    class AddSubActivityDialog;
}

class AddSubActivityDialog : public QDialog {
Q_OBJECT

public:
    explicit AddSubActivityDialog(ActivityController *c, QWidget *parent = nullptr);

    ~AddSubActivityDialog() override;

    QString getTask();

private slots:

    void on_AddButton_clicked();

private:
    Ui::AddSubActivityDialog *ui;

    ActivityController *controller;
};

#endif // ADDSUBACTIVITYDIALOG_H
