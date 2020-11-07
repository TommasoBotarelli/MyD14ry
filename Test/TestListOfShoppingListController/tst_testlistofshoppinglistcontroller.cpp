#include <QtTest>
#include "../../ListOfShoppingListController.h"
#include "../../ListOfShoppingList.h"
#include "../../ShoppingList.h"

// add necessary includes here

class TestListOfShoppingListController : public QObject
{
    Q_OBJECT

public:
    TestListOfShoppingListController();
    ~TestListOfShoppingListController();

private slots:
    void testSetData();

    //void testRemove();

};

TestListOfShoppingListController::TestListOfShoppingListController()
{

}

TestListOfShoppingListController::~TestListOfShoppingListController()
{

}

void TestListOfShoppingListController::testSetData() {
    ListOfShoppingList listOfShoppingList;
    ShoppingList shoppingList;

    ListOfShoppingListController LOSLC(&shoppingList,&listOfShoppingList);

    LOSLC.setData("testName","testProduct");
    QVERIFY((*listOfShoppingList.getList().begin())->getNameList()=="testName");
}

//void TestListOfShoppingListController::testRemove() {}
QTEST_APPLESS_MAIN(TestListOfShoppingListController)

#include "tst_testlistofshoppinglistcontroller.moc"
