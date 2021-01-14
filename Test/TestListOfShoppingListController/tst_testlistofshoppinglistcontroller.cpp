#include <QtTest>
#include "file_h/ListOfShoppingListController.h"
#include "file_h/ShoppingProduct.h"
#include "file_h/ListOfShoppingList.h"
#include "file_h/ShoppingList.h"

// add necessary includes here

class TestListOfShoppingListController : public QObject {
Q_OBJECT

public:
    TestListOfShoppingListController();

    ~TestListOfShoppingListController();

private slots:
    void testSetData();

    void testSetData2();

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

    ListOfShoppingListController LOSLC(&listOfShoppingList);

    LOSLC.setData(shoppingList,"name");
    QVERIFY(shoppingList.getNameList()=="name");
}

void TestListOfShoppingListController::testSetData2() {
    ListOfShoppingList listOfShoppingList;
    ShoppingList shoppingList;
    ShoppingProduct product;
    std::list<ShoppingProduct> list;

    ListOfShoppingListController LOSLC(&listOfShoppingList);

    LOSLC.setData(shoppingList,product,"name",false);
    QVERIFY(product.getName()=="name");
    QVERIFY(product.isCatched()==false);
}

void TestListOfShoppingListController::testGetList() {
    ListOfShoppingList listOfShoppingList;
    ShoppingList shoppingList;
    ShoppingList shoppingList1;
    ListOfShoppingListController LOSLC(&listOfShoppingList);
    QListWidget list;

    listOfShoppingList.addShoppingList(shoppingList);
    listOfShoppingList.addShoppingList(shoppingList1);

    LOSLC.getLists(list);
    QVERIFY(list.count()==2);

}
void TestListOfShoppingListController::testRemove() {
    ListOfShoppingList listOfShoppingList;
    ShoppingList shoppingList;
    ShoppingList shoppingList1;
    std::list<ShoppingList> list;

    ListOfShoppingListController LOSLC(&listOfShoppingList);

    listOfShoppingList.addShoppingList(shoppingList);

    LOSLC.remove(shoppingList);

    QVERIFY(list.empty());

}

QTEST_MAIN(TestListOfShoppingListController)

#include "tst_testlistofshoppinglistcontroller.moc"
