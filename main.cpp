#include "mainwindow.h"

#include "ActivityList.h"
#include "Calendar.h"
#include "ListOfShoppingList.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto activityList = new ActivityList;
    auto calendar = new Calendar;
    auto shopList = new ListOfShoppingList;

    MainWindow w(activityList, calendar, shopList);
    w.show();
    return a.exec();
}
