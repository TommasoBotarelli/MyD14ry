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

    void Testremove();

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

QTEST_APPLESS_MAIN(TestActivtyListController)

#include "tst_testactivtylistcontroller.moc"
