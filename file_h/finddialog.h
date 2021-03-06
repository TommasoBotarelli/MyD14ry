#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include "Observer.h"
#include "file_h/ActivityList.h"
#include "Calendar.h"
#include "ListOfShoppingList.h"
#include <QListWidgetItem>
#include "QListWidgetTemplate.h"
#include "file_h/ActivityListController.h"
#include "CalendarController.h"
#include "ListOfShoppingListController.h"
#include "file_h/activityview.h"
#include "eventview.h"
#include "shoppinglistview.h"

namespace Ui {
    class findDialog;
}

class findDialog : public QDialog, public Observer {
Q_OBJECT

public:
    findDialog(ActivityList *actList, Calendar *c, ListOfShoppingList *shopList,
               ActivityListController *c1,
               CalendarController *c2,
               ListOfShoppingListController *c3,
               QWidget *parent = nullptr);

    ~findDialog() override;

    void update() override;

    void attach() override;

    void detach() override;

    bool isSimilar(QString a, QString b, qreal percentage = 80, int n = 2,
                   Qt::CaseSensitivity caseSense = Qt::CaseInsensitive);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:

    void on_findLineEdit_textChanged(const QString &arg1);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_itemChanged(QListWidgetItem *item);

private:
    Ui::findDialog *ui;

    ActivityList *activityList;

    Calendar *calendar;

    ListOfShoppingList *listOfShoppingList;

    ActivityListController *actListController;

    CalendarController *calendarController;

    ListOfShoppingListController *shopListController;
};

#endif // FINDDIALOG_H
