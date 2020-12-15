#include "mainwindow.h"

#include "ActivityList.h"
#include "Calendar.h"
#include "ListOfShoppingList.h"

#include "ActivityListController.h"
#include "CalendarController.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto activityList = new ActivityList;
    auto calendar = new Calendar;
    auto shopList = new ListOfShoppingList;

    auto actController = new ActivityListController(activityList);
    auto eventController = new CalendarController(calendar);
    auto shopListController = new ListOfShoppingListController(shopList);

    MainWindow w(activityList, calendar, shopList, actController, eventController, shopListController);
    w.show();
    return a.exec();
}
