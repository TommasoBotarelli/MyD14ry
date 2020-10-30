#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QListWidgetItem>
#include <addactivityview.h>
#include <ActivityListController.h>
#include "ActivityList.h"
#include "Activity.h"
#include "Observer.h"
#include "QListWidgetActivity.h"
#include "addsubactivitydialog.h"
#include "activityview.h"

//FIXME una volta introdotti i qlistwidgetitem specifici eliminare questa inclusione

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Observer {
Q_OBJECT

public:
    explicit MainWindow(ActivityList &actList, QWidget *parent = nullptr);

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

private:
    Ui::MainWindow *ui;

    ActivityList activityList;

    ActivityListController *activityListController;


};

#endif // MAINWINDOW_H
