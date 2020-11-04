#ifndef ADDEVENTDIALOG_H
#define ADDEVENTDIALOG_H

#include <QDialog>
#include "CalendarController.h"

namespace Ui {
    class AddEventDialog;
}

class AddEventDialog : public QDialog {
Q_OBJECT

public:
    explicit AddEventDialog(CalendarController *c, Event *e, QWidget *parent = nullptr);

    const QString getTask();

    const QDate getDate();

    const QTime getStartTime();

    const QTime getEndTime();

    const bool getAllDay();

    const QString getNote();

    ~AddEventDialog() override;

private slots:

    void on_AddButton_clicked();

    void on_AllDayCheckBox_stateChanged(int arg1);

private:
    Ui::AddEventDialog *ui;

    CalendarController *controller;

    Event *event;
};

#endif // ADDEVENTDIALOG_H
