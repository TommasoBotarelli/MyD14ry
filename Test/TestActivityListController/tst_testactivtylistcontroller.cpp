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

    void TestRemove();

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

void TestActivtyListController::TestRemove(){
    auto activityList = new ActivityList;
    auto activity1 = new Activity;
    auto activity2 = new Activity;

    activityList->addActivity(activity1);
    activityList->addActivity(activity2);

    ActivityListController controller(activityList, activity1);

    controller.remove();
    QVERIFY(activityList->getActivity().size() == 1);

    controller.setActivity(activity2);
    controller.remove();
    QVERIFY(activityList->getActivity().empty());
}
QTEST_MAIN(TestActivtyListController)

#include "tst_testactivtylistcontroller.moc"

