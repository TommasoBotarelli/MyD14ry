#include "mainwindow.h"

#include "ActivityList.h"
#include "Calendar.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto activityList = new ActivityList;
    auto calendar = new Calendar;

    MainWindow w(activityList, calendar);
    w.show();
    return a.exec();
}
