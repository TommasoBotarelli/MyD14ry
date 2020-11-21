#include <QtTest>
#include "../../ListOfShoppingListController.h"
#include "../../ShoppingProduct.h"
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

    void testGetList();
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

void TestListOfShoppingListController::testGetList() {
    ListOfShoppingList listOfShoppingList;
    ShoppingList shoppingList;
    ShoppingList shoppingList1;
    ListOfShoppingListController LOSLC(&shoppingList,&listOfShoppingList);
    QListWidget list;

    listOfShoppingList.addShoppingList(&shoppingList);
    listOfShoppingList.addShoppingList(&shoppingList1);

    LOSLC.getLists(list);
    QVERIFY(list.count()==2);

}
void TestListOfShoppingListController::testRemove() {
    auto listOfShoppingList = new ListOfShoppingList;
    auto shoppingList = new ShoppingList;

    ListOfShoppingListController LOSLC(shoppingList, listOfShoppingList);

    listOfShoppingList->addShoppingList(shoppingList);

    LOSLC.remove();

    QVERIFY(listOfShoppingList->getList().empty());

}

QTEST_MAIN(TestListOfShoppingListController)

#include "tst_testlistofshoppinglistcontroller.moc"
