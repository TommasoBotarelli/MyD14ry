#include <QtTest>
#include <QCoreApplication>
#include <QString>
#include <QDate>

//ATTIVITÀ
#include "../file_h/Activity.h"
#include "../file_h/SubActivity.h"
#include "../file_h/ActivityList.h"
#include "../file_h/Category.h"

//EVENTI
#include "../file_h/Event.h"
#include "../file_h/Calendar.h"

class AllTest : public QObject {
Q_OBJECT

public:
    AllTest();

    ~AllTest();

    void setActivity(std::shared_ptr<Activity> &act, const QString &name, const QDate &deadlineDate,
                     const QString &category = "VARIE", bool completed = false);

    void setEvent(std::shared_ptr<Event> &event,QString task,QDate currentdate,const QTime startTime,const QTime endTime,QString note,bool completed);

private slots:

    void test_Activity();

    void testActivityList();

    void test_Event();

    void test_Calendar();

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

    std::shared_ptr<SubActivity> subA(new SubActivity("Pulire", true));
    std::shared_ptr<SubActivity> subB(new SubActivity("Studiare", false));

    std::list<std::shared_ptr<SubActivity>> list;

    activity.addSubActivity(subA);
    activity.addSubActivity(subB);
    activity.getSubActivities(list);

    QVERIFY(list.size() == 2);
    QVERIFY(subA->getTask() == "Pulire");
    QVERIFY(subA->isCompleted());

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

    ActivityList actList;

    actList.addCategory("Categoria 1");
    actList.addCategory("Categoria 2");

    setActivity(activity1, "Prova1", QDate::currentDate(), "Categoria 1");
    setActivity(activity2, "Prova2", QDate::currentDate(), "Categoria 2");

    actList.addActivity("Categoria 1", activity1);
    actList.addActivity("Categoria 2", activity2);

    std::list<Category> catList;
    std::list<std::shared_ptr<Activity>> list;
    actList.getCategory(catList);

    int count = 0;

    for (auto &i : catList) {
        list.clear();
        i.getActivity(list);

        QVERIFY(list.size() == 1);
        count++;
    }
}

void AllTest::test_Event() {
    Event event;
    QTime time1(10,30);
    QTime time2(11,05);

    event.setTask("task");
    event.setDate(QDate::currentDate());
    event.setStartTime(time1);
    event.setEndTime(time2);
    event.setAllDay(true);

    QVERIFY(event.getTask()=="task");
    QVERIFY(event.getNote()=="note");
    QVERIFY(event.getDate()==QDate::currentDate());
    QVERIFY(event.getStartTime()==time1);
    QVERIFY(event.getEndTime()==time2);
    QVERIFY(event.isAllDay());

}

void AllTest::test_Calendar() {
    Calendar calendar;
    std::shared_ptr<Event> event(new Event);
    std::shared_ptr<Event> event2(new Event);
    std::list<std::shared_ptr<Event>> list;
    QTime time1(10,30);
    QTime time2(11,05);

    setEvent(event,"task",QDate::currentDate(),time1,time2,"note",true);
    setEvent(event2,"task2",QDate::currentDate(),time1,time2,"note2",true);

    calendar.addEvent(event);
    calendar.addEvent(event2);

    calendar.getEvent(list);

    QVERIFY(list.size()==2);
    QVERIFY((*list.begin())->getTask()=="task");
    QVERIFY((*list.begin())->getNote()=="note");
    auto i=std::next(list.begin(),1);
    QVERIFY((*list.begin())->getTask()=="task2");
    QVERIFY((*list.begin())->getNote()=="note2");


    calendar.removeEvent(event);
    calendar.getEvent(list);
    QVERIFY(list.size()==1);

    calendar.removeEvent(event2);
    calendar.getEvent(list);
    QVERIFY(list.empty());

}

void AllTest::setActivity(std::shared_ptr<Activity> &act, const QString &name, const QDate &deadlineDate,
                          const QString &category,
                          bool completed) {
    act->setTask(name);
    act->setDeadlineDate(deadlineDate);
    act->setCategory(category);
    act->setCompleted(completed);
    act->setHasDeadlineDate(true);
}

void AllTest::setEvent(std::shared_ptr<Event> &event,QString task,QDate currentdate,const QTime startTime,const QTime endTime,QString note,bool completed) {
    event->setTask(task);
    event->setDate(currentdate);
    event->setStartTime(startTime);
    event->setEndTime(endTime);
    event->setNote(note);
    event->setAllDay(completed);
}



QTEST_MAIN(AllTest)

#include "tst_alltest.moc"
