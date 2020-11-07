#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QListWidgetItem>
#include "Observer.h"

//ATTIVITÀ
#include "Activity.h"
#include "ActivityList.h"
#include "addactivityview.h"
#include "ActivityListController.h"
#include "QListWidgetActivity.h"
#include "addsubactivitydialog.h"
#include "activityview.h"

//EVENTO
#include "Event.h"
#include "CalendarController.h"
#include "Calendar.h"
#include "QListWidgetEvent.h"
#include "addeventdialog.h"
#include "eventview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Observer {
Q_OBJECT

public:
    explicit MainWindow(ActivityList *actList, Calendar *cal, QWidget *parent = nullptr);

    ~MainWindow() override;

    void update() override;

    void attach() override;

    void detach() override;
private slots:

    void on_actionActivity_triggered();

    void on_actionEvent_triggered();

    void on_actionLista_della_spesa_triggered();

    void on_calendarWidget_clicked(const QDate &date);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_itemChanged(QListWidgetItem *item);

    void on_listWidget_2_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_3_itemDoubleClicked(QListWidgetItem *item);

    void on_RefreshButton_clicked();

private:
    Ui::MainWindow *ui;

    ActivityList *activityList;

    Calendar *calendar;

    ActivityListController *activityListController;

    CalendarController *calendarController;

};

#endif // MAINWINDOW_H
