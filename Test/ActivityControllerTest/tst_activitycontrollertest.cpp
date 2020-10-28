#include <QtTest>
#include "../../Activity.h"
#include "../../SubActivity.h"
#include "../../ActivityController.h"

// add necessary includes here

class ActivityControllerTest : public QObject {
Q_OBJECT

public:
    ActivityControllerTest();

    ~ActivityControllerTest();

private slots:

    void testSetData();

};

ActivityControllerTest::ActivityControllerTest() {

}

ActivityControllerTest::~ActivityControllerTest() {

}

void ActivityControllerTest::testSetData() {
    Activity activity;
    SubActivity subA;
    ActivityController aC(&activity, &subA);

    aC.setData("Test", true);
    QVERIFY ((*activity.getSubActivities().begin())->getTask() == "Test");
    QVERIFY ((*activity.getSubActivities().begin())->isCompleted());

}

QTEST_APPLESS_MAIN(ActivityControllerTest)

#include "tst_activitycontrollertest.moc"
