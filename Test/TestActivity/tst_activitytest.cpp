#include <QtTest>
#include <QString>
#include <QDate>
#include "../../Activity.h"
#include "../../SubActivity.h"


// add necessary includes here

class ActivityTest : public QObject {
Q_OBJECT

public:
    ActivityTest();

    ~ActivityTest() override;

private slots:

    void testSetterGetter();

    void testAddGetSubactivity();

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

    activity.setDeadlineDate(QDate::currentDate());
    QVERIFY (activity.getDeadlineDate() == QDate::currentDate());
    QDate date2(15, 5, 20);
    activity.setDeadlineDate(date2);
    QVERIFY (activity.getDeadlineDate() == date2);

    activity.setCompleted(true);
    QVERIFY (activity.isCompleted());

    activity.setNote("ciao MARCO come stai? Qua tutto bene!");
    QVERIFY (activity.getNote() == "ciao MARCO come stai? Qua tutto bene!");
    activity.setNote("");
    QVERIFY (activity.getNote() == "");
}

void ActivityTest::testAddGetSubactivity() {
    Activity activity;
    SubActivity subA;
    subA.setTask("Pagare bollette");
    subA.setCompleted(true);
    SubActivity subB;
    subB.setTask("Studiare inglese");
    subB.setCompleted(false);
    std::list<SubActivity> list;

    activity.addSubActivity(subA);
    activity.addSubActivity(subB);
    activity.getSubActivities(list);

    QVERIFY (list.size() == 2);
    QVERIFY (list.begin()->getTask() == "Pagare bollette");
    QVERIFY (list.begin()->isCompleted());

    auto i = std::next(list.begin(), 1);
    QVERIFY ((*i).getTask() == "Studiare inglese");
    QVERIFY ((*i).isCompleted() == false);
}



QTEST_APPLESS_MAIN(ActivityTest)

#include "tst_activitytest.moc"
