#include <QtTest>
#include "../../Activity.h"
#include "../../ActivityList.h"
#include "../../SubActivity.h"
#include "../../Category.h"

// add necessary includes here

class TestActivityList : public QObject {
Q_OBJECT

public:
    TestActivityList();

    ~TestActivityList();

private slots:

    void testAddGetCategory();

    void testAddActivity();

    void testRemoveActivity();

    void testRemoveCategory();

};

TestActivityList::TestActivityList() {

}

TestActivityList::~TestActivityList() {

}

void TestActivityList::testAddGetCategory() {
    ActivityList actlist;
    Category c;
    Category c2;
    std::list<Category> list;

    actlist.addCategory(c);
    c.setName("cat1");
    QVERIFY(c.getName()=="cat1");

    actlist.addCategory(c2);
    c2.setName("cat2");
    QVERIFY(c2.getName()=="cat2");

    actlist.getCategory(list);

    QVERIFY(list.size()==2);
}

void TestActivityList::testAddActivity() {
    ActivityList actList;
    Activity a1;
    Activity a2;
    Category c;
    c.setName("categoria");
    std::list<Category> list;
    std::list<Activity> activitylist;

    a1.setTask("Attività 1");
    a2.setTask("Attività 2");

    actList.addCategory(c);

    actList.addActivity("categoria",a1);
    actList.addActivity("categoria",a2);

    actList.getCategory(list);
    list.begin()->getActivity(activitylist);

    QVERIFY (activitylist.size()==2);
    QVERIFY ((activitylist.begin())->getTask() == "Attività 1");

    auto i = std::next(activitylist.begin(), 1);
    QVERIFY ((*i).getTask() == "Attività 2");
}

void TestActivityList::testRemoveActivity() {
    ActivityList actList;
    Activity a1;
    a1.setTask("1");
    Activity a2;
    a2.setTask("2");
    Category c;
    c.setName("categoria");
    std::list<Category> Clist;
    std::list<Activity> Alist;
    Alist.clear();
    Clist.clear();

    actList.addCategory(c);

    actList.addActivity("categoria", a1);
    actList.addActivity("categoria", a2);

    actList.removeActivity(c, a1);
    actList.getCategory(Clist);
    Clist.begin()->getActivity(Alist);
    QVERIFY(Alist.size() == 1);

    actList.removeActivity(c,a2);
    Clist.clear();
    Alist.clear();
    actList.getCategory(Clist);
    Clist.begin()->getActivity(Alist);

    QVERIFY(Alist.empty());
}

void TestActivityList::testRemoveCategory() {
    ActivityList actlist;
    Category c;
    c.setName("1");
    Category c2;
    c2.setName("2");
    std::list<Category> Clist;

    actlist.addCategory(c);
    actlist.addCategory(c2);

    actlist.getCategory(Clist);
    QVERIFY(Clist.size()==2);

    actlist.removeCategory(c);
    Clist.clear();
    actlist.getCategory(Clist);
    QVERIFY(Clist.size()==1);
}


QTEST_APPLESS_MAIN(TestActivityList)

#include "tst_testactivitylist.moc"