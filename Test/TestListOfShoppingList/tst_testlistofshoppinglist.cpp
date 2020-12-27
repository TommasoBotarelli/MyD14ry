#include <QtTest>
#include "../../ShoppingList.h"
#include "../../ShoppingProduct.h"
#include "../../ListOfShoppingList.h"

// add necessary includes here

class TestListOfShoppingList : public QObject
{
    Q_OBJECT

public:
    TestListOfShoppingList();
    ~TestListOfShoppingList();

private slots:
    void testAddGetShoppingList();
    void testRemoveShoppingList();
};

TestListOfShoppingList::TestListOfShoppingList()
{

}

TestListOfShoppingList::~TestListOfShoppingList()
{

}

void TestListOfShoppingList::testAddGetShoppingList()
{
    ListOfShoppingList listOfShoppingList;
    ShoppingList sh1;
    ShoppingList sh2;
    std::list<ShoppingList> list;

    sh1.setNameList("Test1");
    sh2.setNameList("Test2");

    listOfShoppingList.addShoppingList(sh1);
    listOfShoppingList.addShoppingList(sh2);

    listOfShoppingList.getList(list);

    QVERIFY (list.size() == 2);
    QVERIFY (list.begin()->getNameList() == "Test1");

    auto i = std::next(list.begin(), 1);
    QVERIFY ((i)->getNameList() == "Test2");

}

void TestListOfShoppingList::testRemoveShoppingList()
{
    ListOfShoppingList listOfShoppingList;
    ShoppingList sh1;
    ShoppingList sh2;
    std::list<ShoppingList> list;

    sh1.setNameList("Test1");
    sh2.setNameList("Test2");

    listOfShoppingList.addShoppingList(sh1);
    listOfShoppingList.addShoppingList(sh2);

    listOfShoppingList.removeShoppingList(sh2);
    listOfShoppingList.getList(list);
    QVERIFY(list.size() == 1);

    listOfShoppingList.removeShoppingList(sh1);
    list.clear();
    listOfShoppingList.getList(list);
    QVERIFY(list.empty());

}

QTEST_APPLESS_MAIN(TestListOfShoppingList)

#include "tst_testlistofshoppinglist.moc"
