#include "mainwindow.h"
#include "ActivityList.h"
#include "ActivityListController.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    ActivityList activityList;

    MainWindow w(activityList);
    w.show();
    return a.exec();
}
