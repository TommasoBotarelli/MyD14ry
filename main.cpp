#include "file_h/mainwindow.h"

#include "file_h/ActivityList.h"
#include "file_h/Calendar.h"
#include "file_h/ListOfShoppingList.h"

#include "file_h/ActivityListController.h"
#include "file_h/CalendarController.h"
#include "file_h/ListOfShoppingListController.h"

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
