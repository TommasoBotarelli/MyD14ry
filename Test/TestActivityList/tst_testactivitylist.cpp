#include <QtTest>
#include "../../Activity.h"
#include "../../ActivityList.h"
#include "../../SubActivity.h"

// add necessary includes here

class TestActivityList : public QObject {
Q_OBJECT

public:
    TestActivityList();

    ~TestActivityList();

private slots:

    void testAddGetActivity();

    void testRemoveActivity();

};

TestActivityList::TestActivityList() {

}

TestActivityList::~TestActivityList() {

}

void TestActivityList::testAddGetActivity() {
    ActivityList actList;
    Activity a1;
    Activity a2;

    a1.setTask("Attività 1");
    a2.setTask("Attività 2");

    actList.addActivity(a1);
    actList.addActivity(a2);

    QVERIFY (actList.getActivity().size() == 2);
    QVERIFY ((*actList.getActivity().begin())->getTask() == "Attività 1");

    auto i = std::next(actList.getActivity().begin(), 1);
    QVERIFY ((*i)->getTask() == "Attività 2");
}

void TestActivityList::testRemoveActivity() {
    ActivityList actList;
    auto a1 = new Activity();
    auto a2 = new Activity();

    a1->setTask("Attività 1");
    a2->setTask("Attività 2");

    actList.addActivity(a1);
    actList.addActivity(a2);

    actList.removeActivity(a2);
    QVERIFY(actList.getActivity().size() == 1);

    actList.removeActivity(a1);
    QVERIFY(actList.getActivity().empty());

}

QTEST_APPLESS_MAIN(TestActivityList)

#include "tst_testactivitylist.moc"
