#include <QtTest>
#include "../../ListOfShoppingListController.h"
#include "../../QListWidgetProduct.h"
#include "../../ShoppingProduct.h"
#include "../../QListWidgetShoppingList.h"
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

    void testRemove();

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

    LOSLC.setData("testName");
    QVERIFY((*listOfShoppingList.getList().begin())->getNameList()=="testName");
}

void TestListOfShoppingListController::testRemove() {
    ListOfShoppingList listOfShoppingList;
    ShoppingList shoppingList;

    ListOfShoppingListController LOSLC(&shoppingList,&listOfShoppingList);

    listOfShoppingList.addShoppingList(&shoppingList);

    LOSLC.remove();

    QVERIFY(listOfShoppingList.getList().empty());

}
QTEST_MAIN(TestListOfShoppingListController)

#include "tst_testlistofshoppinglistcontroller.moc"
