#include "mainwindow.h"

#include "ActivityList.h"
#include "Calendar.h"
#include "ListOfShoppingList.h"

#include "ActivityListController.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto activityList = new ActivityList;
    auto calendar = new Calendar;
    auto shopList = new ListOfShoppingList;

    auto actController = new ActivityListController(activityList);

    MainWindow w(activityList, calendar, shopList, actController);
    w.show();
    return a.exec();
}
