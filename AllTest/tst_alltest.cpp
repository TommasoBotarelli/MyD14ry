#include <QtTest>
#include <QCoreApplication>
#include <QString>
#include <QDate>
#include <QListWidget>
#include <QListWidgetItem>

//ATTIVITÀ
#include "../file_h/Activity.h"
#include "../file_h/SubActivity.h"
#include "../file_h/ActivityList.h"
#include "../file_h/Category.h"
#include "../file_h/ActivityListController.h"

//EVENTI
#include "../file_h/Event.h"
#include "../file_h/Calendar.h"
#include "../file_h/CalendarController.h"

//SHOPPING_LIST
#include "../file_h/ListOfShoppingListController.h"
#include "../file_h/ListOfShoppingList.h"
#include "../file_h/ShoppingList.h"
#include "../file_h/ShoppingProduct.h"

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

    void test_ActivityList();

    void test_ActivityListController();

    void test_Event();

    void test_Calendar();

    void test_CalendarController();

    void test_Category();

    void test_ListOfShoppigList();

    void test_ShoppingList();

    void test_ListOfShoppingListController();

};

AllTest::AllTest()
{

}

AllTest::~AllTest()
{

}

void AllTest::test_Activity() {
    std::shared_ptr<Activity> activity(new Activity());

    setActivity(activity, "prova", QDate(1, 1, 1));

    std::list<std::shared_ptr<SubActivity>> list;

    activity->addSubActivity("Pulire", true);
    activity->addSubActivity("Studiare", false);

    activity->getSubActivities(list);

    QVERIFY(list.begin()->get()->getTask() == "Pulire");

    QVERIFY(list.size() == 2);

    for (auto &i : list) {
        activity->removeSubActivity(i);
    }

    list.clear();
    activity->getSubActivities(list);
    QVERIFY(list.size() == 0);

}

void AllTest::test_ActivityList() {
    std::shared_ptr<Activity> activity1(new Activity());
    std::shared_ptr<Activity> activity2(new Activity());

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
    QVERIFY(count == 2);
}

void AllTest::test_Event() {
    Event event;
    QTime time1(10,30);
    QTime time2(11,05);

    event.setTask("task");
    event.setNote("note");
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
    QVERIFY((*i)->getTask()=="task2");
    QVERIFY((*i)->getNote()=="note2");


    calendar.removeEvent(event);
    list.clear();
    calendar.getEvent(list);
    QVERIFY(list.size()==1);

    calendar.removeEvent(event2);
    list.clear();
    calendar.getEvent(list);
    QVERIFY(list.empty());

}

void AllTest::test_CalendarController() {
    std::shared_ptr<Event> event(new Event);
    std::shared_ptr<Event> event2(new Event);
    Calendar calendar;
    CalendarController CC(&calendar);
    std::list<std::shared_ptr<Event>> list;
    QDate date(2020,05,27);
    QDate date2(2020,07,12);
    QTime time1(10,30);
    QTime time2(11,05);

    calendar.addEvent(event);
    calendar.addEvent(event2);
    CC.setData(event,"task",date,"note",time1,time2,false);
    CC.setData(event2,"task2",date2,"note2",time1,time2,true);
    list.clear();
    calendar.getEvent(list);

    QVERIFY(event->getTask()=="task");
    QVERIFY(event->getDate()==date);
    QVERIFY(event->getNote()=="note");
    QVERIFY(event->getStartTime()==time1);
    QVERIFY(event->getEndTime()==time2);
    QVERIFY(event->isAllDay()==false);

    for(auto &i: list){
        calendar.removeEvent(i);
    }
    list.clear();
    QVERIFY(list.empty());
}

void AllTest::test_Category() {
    Category category("categoria");
    std::shared_ptr<Activity> activity(new Activity);
    std::shared_ptr<Activity> activity2(new Activity);
    std::list<std::shared_ptr<Activity>> list;

    category.setName("categoria");
    QVERIFY(category.getName()=="categoria");

    category.addActivity(activity);
    category.addActivity(activity2);
    category.getActivity(list);

    QVERIFY(list.size() == 2);

    for (auto &i: list) {
        category.removeActivity(i);
    }
    list.clear();

    category.getActivity(list);
    QVERIFY(list.empty());
}


void AllTest::test_ListOfShoppingListController() {
    ListOfShoppingList listOfShoppingList;
    ListOfShoppingListController listOfShoppingListController(&listOfShoppingList);

    std::shared_ptr<ShoppingList> shoplist1(new ShoppingList);
    std::shared_ptr<ShoppingList> shoplist2(new ShoppingList);

    listOfShoppingListController.addCategory("Categoria 1");

    std::list<std::shared_ptr<ShoppingList>> list;
    std::list<std::shared_ptr<ShoppingProduct>> tempListProduct;

    std::list<QString> catList;

    listOfShoppingListController.setData(shoplist1, "name list");
    listOfShoppingListController.setData(shoplist2, "name list 2");

    listOfShoppingList.getList(list);

    QVERIFY(list.size() == 2);

    listOfShoppingListController.addProduct(shoplist1, "name prod 1", "Categoria 1", true);
    tempListProduct.clear();
    shoplist1->getProducts(tempListProduct);
    QVERIFY(tempListProduct.size() == 1);

    /*listOfShoppingListController.removeProduct(*tempListProduct.begin(), shoplist1);
    tempListProduct.clear();
    shoplist1->getProducts(tempListProduct);
    QVERIFY(tempListProduct.empty());*/

    listOfShoppingListController.addProduct(shoplist2, "name prod 2", "Categoria 1", true);
    tempListProduct.clear();
    shoplist2->getProducts(tempListProduct);
    QVERIFY(tempListProduct.size() == 1);

    listOfShoppingList.getCategory(catList);
    QVERIFY(catList.size() == 1);

    listOfShoppingListController.removeCategory("Categoria 1");
    catList.clear();
    listOfShoppingList.getCategory(catList);
    QVERIFY(catList.empty());

    tempListProduct.clear();
    shoplist1->getProducts(tempListProduct);
    QVERIFY(tempListProduct.size() == 1);
    QVERIFY((*tempListProduct.begin())->isCategoryIsSet() == false);

    tempListProduct.clear();
    shoplist2->getProducts(tempListProduct);
    QVERIFY(tempListProduct.size() == 1);
    QVERIFY((*tempListProduct.begin())->isCategoryIsSet() == false);

    tempListProduct.clear();
    shoplist1->getProducts(tempListProduct);
    listOfShoppingListController.removeProduct(*tempListProduct.begin(), shoplist1);
    tempListProduct.clear();
    shoplist1->getProducts(tempListProduct);
    QVERIFY(tempListProduct.empty());

    tempListProduct.clear();
    shoplist2->getProducts(tempListProduct);
    listOfShoppingListController.setCatched(shoplist2, *(tempListProduct.begin()), true);
    QVERIFY((*tempListProduct.begin())->isCatched());

    listOfShoppingListController.removeProduct(*(tempListProduct.begin()), shoplist2);
    tempListProduct.clear();
    shoplist2->getProducts(tempListProduct);
    QVERIFY(tempListProduct.empty());

    QVERIFY(list.size() == 2);
    listOfShoppingListController.remove(shoplist1);
    list.clear();
    listOfShoppingList.getList(list);
    QVERIFY(list.size() == 1);
    listOfShoppingList.removeShoppingList(shoplist2);
    list.clear();
    listOfShoppingList.getList(list);
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

void AllTest::test_ActivityListController() {
    auto actList = new ActivityList;
    ActivityListController actListController(actList);

    std::list<Category> catList;

    std::shared_ptr<Activity> activity1(new Activity());
    std::shared_ptr<Activity> activity2(new Activity());

    setActivity(activity1, "TEST 1 ", QDate(2000, 02, 02));
    setActivity(activity2, "TEST 2", QDate(2000, 02, 02));

    actListController.addCategory("Categoria 1");
    actListController.addCategory("Categoria 2");

    actList->getCategory(catList);
    QVERIFY(catList.size() == 2);

    actListController.removeAndMoveActivity("Categoria 1");
    catList.clear();
    actList->getCategory(catList);
    QVERIFY(catList.size() == 1);

    actListController.removeAndMoveActivity("Categoria 2");
    catList.clear();
    actList->getCategory(catList);
    QVERIFY(catList.size() == 0);

    actListController.addCategory("Categoria 3");
    actListController.addCategory("Categoria 4");

    std::shared_ptr<Activity> activity3(new Activity());
    actListController.setData("Categoria 3", activity3, "TEST", QDate(2000, 02, 02), true, "note");

    actListController.modifyCategory("Categoria 3", "Categoria 4", activity3);
    QVERIFY(activity3->getCategory() == "Categoria 4");

    actListController.removeAndMoveActivity("Categoria 3");
    catList.clear();
    actList->getCategory(catList);

    QVERIFY(catList.size() == 1);
}

void AllTest::test_ListOfShoppigList() {
    std::shared_ptr<ShoppingList> shopList1(new ShoppingList);
    std::shared_ptr<ShoppingList> shopList2(new ShoppingList);

    ListOfShoppingList listShopList;

    std::list<std::shared_ptr<ShoppingList>> tempList;

    listShopList.addShoppingList(shopList1);
    listShopList.addShoppingList(shopList2);

    listShopList.getList(tempList);

    QVERIFY(tempList.size() == 2);

    listShopList.removeShoppingList(shopList2);

    tempList.clear();
    listShopList.getList(tempList);

    QVERIFY(tempList.size() == 1);

    listShopList.removeShoppingList(shopList1);

    tempList.clear();
    listShopList.getList(tempList);

    QVERIFY(tempList.empty());
}

void AllTest::test_ShoppingList() {
    std::shared_ptr<ShoppingList> shopList(new ShoppingList());
    std::list<std::shared_ptr<ShoppingProduct>> tempListProduct;

    shopList->setNameList("Lista 1");
    QVERIFY(shopList->getNameList() == "Lista 1");

    shopList->addProduct("product1", "", false);
    shopList->addProduct("product2", "", false);
    shopList->addProduct("product3", "", false, true);

    shopList->getProducts(tempListProduct);

    QVERIFY(tempListProduct.size() == 3);

    QVERIFY(shopList->getCountProduct() == 2);


    for (auto &i : tempListProduct) {
        shopList->removeProduct(i);
    }

    tempListProduct.clear();
    shopList->getProducts(tempListProduct);
    QVERIFY(tempListProduct.size() == 0);
    QVERIFY(shopList->getCountProduct() == 0);
}

QTEST_MAIN(AllTest)

#include "tst_alltest.moc"
