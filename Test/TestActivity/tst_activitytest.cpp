#include <QtTest>
#include <QString>
#include <QDate>
#include "/home/tommaso/Scrivania/MyD14ry/Activity.h"
#include "/home/tommaso/Scrivania/MyD14ry/SubActivity.h"


// add necessary includes here

class ActivityTest : public QObject {
Q_OBJECT

public:
    ActivityTest();

    ~ActivityTest() override;

private slots:

    void testSetterGetter();

};

ActivityTest::ActivityTest() {

}

ActivityTest::~ActivityTest() {

}

void ActivityTest::testSetterGetter() {
    Activity activity;

    activity.setTask("TestTask");
    QVERIFY (activity.getTask() == "TestTask");
    activity.setTask("");
    QVERIFY (activity.getTask() == "Attività");

    activity.setDate(QDate::currentDate());
    QVERIFY (activity.getDate() == QDate::currentDate());
    QDate date1(20, 5, 20);
    activity.setDate(date1);
    QVERIFY (activity.getDate() == date1);

    activity.setDeadlineDate(QDate::currentDate());
    QVERIFY (activity.getDeadlineDate() == QDate::currentDate());
    QDate date2(15, 5, 20);
    activity.setDeadlineDate(date2);
    QVERIFY (activity.getDeadlineDate() == date1);

    activity.setCompleted(true);
    QVERIFY (activity.isCompleted());

    activity.setNote("ciao MARCO come stai? Qua tutto bene!");
    QVERIFY (activity.getNote() == "ciao MARCO come stai? Qua tutto bene!");
    activity.setNote("");
    QVERIFY (activity.getNote() == "");
}


QTEST_APPLESS_MAIN(ActivityTest)

#include "tst_activitytest.moc"
