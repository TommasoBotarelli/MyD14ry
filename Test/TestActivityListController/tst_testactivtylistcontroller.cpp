#include <QtTest>
#include <QString>
#include <QDate>
#include "../../Activity.h"
#include "../../ActivityList.h"
#include "../../ActivityListController.h"

// add necessary includes here

class TestActivtyListController : public QObject
{
Q_OBJECT

public:
    TestActivtyListController();

    ~TestActivtyListController() override;

private slots:

    void TestSetData();

    // void TestRemove(); //TODO rivedere funzione remove

    void TestSearchActivityOfDay();

};

TestActivtyListController::TestActivtyListController()
{

}

TestActivtyListController::~TestActivtyListController()
{

}

void TestActivtyListController::TestSetData() {
    Activity activity;
    ActivityList activityList;
    ActivityListController alC(&activityList, &activity);

    alC.setData("Test",QDate::currentDate(),QDate::currentDate(),true,"TestNOTE");
    QVERIFY((*activityList.getActivity().begin())->getTask()=="Test");

}

void TestActivtyListController::TestSearchActivityOfDay() {
    Activity activity;
    ActivityList activityList;
    ActivityListController alC(&activityList, &activity);
    QListWidget List;

    activity.setDate(QDate::currentDate());
    activity.setTask("Test");
    activityList.addActivity(&activity);

    alC.searchActivityOfDay(QDate::currentDate(),List);
    QVERIFY(List.count()==1);

}
QTEST_MAIN(TestActivtyListController)

#include "tst_testactivtylistcontroller.moc"

