#include <QtTest>
#include <QString>
#include <QDate>
#include "/home/marco/CLionProjects/MyD14ry/Activity.h"
#include "/home/marco/CLionProjects/MyD14ry/ActivityList.h"
#include "/home/marco/CLionProjects/MyD14ry/ActivityListController.h"

// add necessary includes here

class TestActivtyListController : public QObject
{
    Q_OBJECT

public:
    TestActivtyListController();

    ~TestActivtyListController() override;

private slots:

    void TestSetData();

    void Testremove();

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
    ActivityListController alC(&activity, &activityList);

    alC.setData("Test",QDate::currentDate(),QDate::currentDate(),true,"TestNOTE");
    QVERIFY((*activityList.getActivity().begin())->getTask()=="Test");

}

void TestActivtyListController::Testremove() {
    ActivityList activityList;
    Activity activity;
    ActivityListController alC(&activity, &activityList);

    activityList.addActivity(&activity);
    alC.remove();
    QVERIFY(activityList.getActivity().empty());

    //TODO VERIFICARE CHE VENGA CHIAMATO IL DISTRUTTORE
}

void TestActivtyListController::TestSearchActivityOfDay() {
    Activity activity;
    ActivityList activityList;
    ActivityListController alC(&activity,&activityList);
    QListWidget List;

    activity.setDate(QDate::currentDate());
    activity.setTask("Test");

    alC.searchActivityOfDay(QDate::currentDate(),List);

}
QTEST_APPLESS_MAIN(TestActivtyListController)

#include "tst_testactivtylistcontroller.moc"
