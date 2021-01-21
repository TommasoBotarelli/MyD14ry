#include <QtTest>
#include <QCoreApplication>
#include <QString>
#include <QDate>

//ATTIVITÀ
#include "../file_h/Activity.h"
#include "../file_h/SubActivity.h"
#include "../file_h/ActivityList.h"
#include "../file_h/Category.h"

class AllTest : public QObject {
Q_OBJECT

public:
    AllTest();

    ~AllTest();

    void setActivity(std::shared_ptr<Activity> &act, QString name, QDate deadlineDate,
                     QString category = "VARIE", bool completed = false);

private slots:

    void test_Activity();

    void testActivityList();

};

AllTest::AllTest()
{

}

AllTest::~AllTest()
{

}

void AllTest::test_Activity() {
    Activity activity;

    activity.setTask("TestTask");
    activity.setDeadlineDate(QDate::currentDate());
    activity.setCompleted(true);
    activity.setNote("ciao");
    activity.setHasDeadlineDate(true);

    std::shared_ptr<SubActivity> subA(new SubActivity);
    std::shared_ptr<SubActivity> subB(new SubActivity);

    subA->setTask("Pulire");
    subA->setCompleted(true);

    subB->setTask("Studiare");
    subB->setCompleted(false);

    std::list<std::shared_ptr<SubActivity>> list;

    activity.addSubActivity(subA);
    activity.addSubActivity(subB);
    activity.getSubActivities(list);

    QVERIFY (list.size() == 2);
    QVERIFY (subA->getTask() == "Pulire");
    QVERIFY (subA->isCompleted());

    auto i = std::next(list.begin(), 1);
    QVERIFY ((*i)->getTask() == "Studiare");
    QVERIFY (!(*i)->isCompleted());

    activity.removeSubActivity(subA);
    list.clear();
    activity.getSubActivities(list);
    QVERIFY(list.size() == 1);

    activity.removeSubActivity(subB);
    list.clear();
    activity.getSubActivities(list);
    QVERIFY(list.empty());

    activity.setCategory("categoria");
    QVERIFY(activity.getCategory() == "categoria");

}

void AllTest::testActivityList() {
    std::shared_ptr<Activity> activity1(new Activity);
    std::shared_ptr<Activity> activity2(new Activity);

    Category category1;
    Category category2;


    setActivity(activity1, "Prova1", QDate::currentDate(), "Categoria 1");
    setActivity(activity2, "Prova2", QDate::currentDate(), "Categoria 2");

    ActivityList actList;
    actList.addActivity(activity1);
}

void AllTest::setActivity(std::shared_ptr<Activity> &act, QString name, QDate deadlineDate, QString category,
                          bool completed) {
    act->setTask(name);
    act->setDeadlineDate(deadlineDate);
    act->setCategory(category);
    act->setCompleted(completed);
    act->setHasDeadlineDate(true);
}

QTEST_MAIN(AllTest)

#include "tst_alltest.moc"
