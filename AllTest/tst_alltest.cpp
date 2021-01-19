#include <QtTest>
#include <QCoreApplication>
#include <QString>
#include <QDate>
#include "../../file_h/Activity.h"
#include "../../file_h/SubActivity.h"

// add necessary includes here

class AllTest : public QObject
{
    Q_OBJECT

public:
    AllTest();
    ~AllTest();

private slots:

    void test_Activity();

};

AllTest::AllTest()
{

}

AllTest::~AllTest()
{

}

void AllTest::test_Activity(){
    Activity activity;
    std::shared_ptr<SubActivity> subA;
    std::shared_ptr<SubActivity> subB;
    std::list<std::shared_ptr<SubActivity>> list;

    activity.setTask("TestTask");
    QVERIFY (activity.getTask() == "TestTask");

    activity.setDeadlineDate(QDate::currentDate());
    QVERIFY (activity.getDeadlineDate() == QDate::currentDate());

    activity.setCompleted(true);
    QVERIFY (activity.isCompleted());

    activity.setNote("ciao");
    QVERIFY (activity.getNote() == "ciao");

    subA->setTask("Pulire");
    subA->setCompleted(true);
    subB->setTask("Studiare");
    subB->setCompleted(false);

    activity.addSubActivity(subA);
    activity.addSubActivity(subB);
    activity.getSubActivities(list);

    QVERIFY (list.size() == 2);
    QVERIFY (subA->getTask() == "Pulire");
    QVERIFY (subA->isCompleted());

    auto i = std::next(list.begin(), 1);
    QVERIFY ((*i)->getTask() == "Studiare");
    QVERIFY ((*i)->isCompleted() == false);

    activity.removeSubActivity(subA);
    QVERIFY(list.size()==1);
    activity.removeSubActivity(subB);
    QVERIFY(list.empty());

    activity.setCategory("categoria");
    QVERIFY(activity.getCategory()=="categoria");

}

QTEST_MAIN(AllTest)

#include "tst_alltest.moc"
