#include <QtTest>
#include <QString>
#include <QDate>
#include "/home/tommaso/Scrivania/MyD14ry/Activity.h"
#include "/home/tommaso/Scrivania/MyD14ry/ActivityList.h"
// add necessary includes here

class TestActivtyListController : public QObject {
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

void TestActivtyListController::setData() {
    Activity activityA;
    Activity activityB;
    ActivityList activityList;

    activityA.setTask("Cinema");
    activityA.setDate(QDate::currentDate());
    activityA.setCompleted(true);

    activityB.setTask("Meeting");
    activityB.setDate(QDate::currentDate());
    activityB.setCompleted(false);

    activityList.addActivity(&activityA);
    activityList.addActivity(&activityB);
    QVERIFY ((activityList.getActivity().size())==2);
    QVERIFY ((*activityList.getActivity().begin())->getTask()=="Cinema");
    QVERIFY ((*activityList.getActivity().begin())->isCompleted());

    auto i=std::next(activityList.getActivity().begin(),1);
    QVERIFY ((*i)->getTask()=="Meeting");
    QVERIFY ((*i)->isCompleted()==false);

}

void TestActivtyListController::remove() {
    Activity activityA;
    Activity activityB;
    ActivityList activityList;

    activityA.setTask("Spesa");
    activityB.setTask("Allenamento");
    activityA.setDate(QDate::currentDate());
    activityList.addActivity(&activityA);
    activityList.addActivity(&activityB);

    activityList.removeActivity(&activityA);
    QVERIFY ((activityList.getActivity().size())==1);
    QVERIFY((&activityA)== nullptr);

    activityList.removeActivity(&activityB);
    QVERIFY ((activityList.getActivity().size())==0);
}

QTEST_APPLESS_MAIN(TestActivtyListController)

#include "tst_testactivtylistcontroller.moc"
