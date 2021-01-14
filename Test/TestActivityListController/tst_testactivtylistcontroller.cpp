#include <QtTest>
#include <QString>
#include <QDate>
#include "file_h/Activity.h"
#include "file_h/ActivityList.h"
#include "file_h/ActivityListController.h"
#include "file_h/Category.h"

// add necessary includes here

class TestActivtyListController : public QObject {
Q_OBJECT

public:
    TestActivtyListController();

    ~TestActivtyListController() override;

private slots:

    void TestSetDataAct();

    void TestSetDataSub();

    void TestSetDataCat();

    void TestSearchCategory();

    void TestFindCategory();

    void TestRemoveActivity();

    void TestRemoveCategory();

};

TestActivtyListController::TestActivtyListController()
{

}

TestActivtyListController::~TestActivtyListController()
{

}

void TestActivtyListController::TestSetDataAct() {
    Activity activity;
    ActivityList activityList;
    ActivityListController alC(&activityList);
    Category c;
    std::list<Category> Clist;
    std::list<Activity> Alist;

    c.setName("categoria");
    activityList.addCategory(c);
    activityList.addActivity("categoria",activity);

    alC.setData("categoria",activity,"task",QDate::currentDate(),true,"note");

    activityList.getCategory(Clist);
    Clist.begin()->getActivity(Alist);
    QVERIFY(Alist.begin()->getTask()=="task");
    QVERIFY(Alist.begin()->getDeadlineDate()==QDate::currentDate());
    QVERIFY(Alist.begin()->isCompleted()==true);
    QVERIFY(Alist.begin()->getNote()=="note");
}

void TestActivtyListController::TestSetDataSub() {
    Activity activity;
    ActivityList activityList;
    ActivityListController alC(&activityList);
    SubActivity subActivity;

    activity.addSubActivity(subActivity);
    alC.setData(subActivity,activity,"prova",true);

    QVERIFY(subActivity.isCompleted()==true);
    QVERIFY(subActivity.getTask()=="prova");
}

void TestActivtyListController::TestSetDataCat() {
    ActivityList activityList;
    ActivityListController alC(&activityList);
    Category c;

    alC.setData(c,"cat1");
    QVERIFY(c.getName()=="cat1");
}

void TestActivtyListController::TestSearchCategory() {
    Activity activity;
    Activity activity2;
    ActivityList activityList;
    ActivityListController alC(&activityList);
    Category c;
    Category c2;
    std::list<Category> Clist;
    std::list<Activity> Alist;

    c.setName("cat1");
    c.setName("cat2");

    activityList.addCategory(c);
    activityList.addActivity("cat1",activity);
    activityList.addCategory(c2);
    activityList.addActivity("cat2",activity2);

    alC.searchCategory(c2,"cat2");
    activityList.getCategory(Clist);
    Clist.begin()->getActivity(Alist);
    QVERIFY(Clist.begin()->getName()=="cat2");
}

void TestActivtyListController::TestFindCategory() {
    Activity activity;
    Activity activity2;
    ActivityList activityList;
    ActivityListController alC(&activityList);
    bool find=false;
    Category c;
    Category c2;
    std::list<Activity> Alist;
    std::list<Category> Clist;

    c.setName("cat1");
    c2.setName("cat2");
    activityList.addCategory(c);
    activityList.addCategory(c2);

    find=alC.findCategory("cat2");
    QVERIFY(find==true);
}

void TestActivtyListController::TestRemoveActivity(){
    Activity activity;
    Activity activity2;
    ActivityList activityList;
    ActivityListController alC(&activityList);
    Category c;
    std::list<Activity> Alist;
    std::list<Category> Clist;

    c.setName("categoria");
    activityList.addCategory(c);
    activityList.addActivity("categoria",activity);
    activityList.addActivity("categoria",activity2);

    alC.remove(activity2);
    activityList.getCategory(Clist);
    Clist.begin()->getActivity(Alist);
    QVERIFY(Alist.size()==1);

    Clist.clear();
    Alist.clear();

    alC.remove(activity);
    activityList.getCategory(Clist);
    Clist.begin()->getActivity(Alist);
    QVERIFY(Alist.empty());
}

void TestActivtyListController::TestRemoveCategory() {
    Activity activity;
    Activity activity2;
    ActivityList activityList;
    ActivityListController alC(&activityList);
    Category c;
    Category c2;
    std::list<Category> Clist;

    c.setName("categoria");
    c2.setName("categoria2");
    activityList.addCategory(c);
    activityList.addCategory(c2);

    alC.remove(c2);
    activityList.getCategory(Clist);
    QVERIFY(Clist.size()==1);

    Clist.clear();

    alC.remove(c);
    activityList.getCategory(Clist);
    QVERIFY(Clist.empty());
}
QTEST_MAIN(TestActivtyListController)

#include "tst_testactivtylistcontroller.moc"

