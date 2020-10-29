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
#include "addsubactivitydialog.h"

namespace Ui {
    class AddActivityView;
}

class AddActivityView : public QDialog, public Observer {
Q_OBJECT

public:
    explicit AddActivityView(QWidget *parent = nullptr);

    ~AddActivityView() override;

    QDate getDate();

    QDate getDeadlineDate();

    QString getTask();

    QString getNote();

    void update() override;

    void attach() override;

    void detach() override;

    void setActivity(Activity *activity) {
        AddActivityView::activity = activity;
    }

    void setController(ActivityListController *controller) {
        AddActivityView::controller = controller;
    }

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
