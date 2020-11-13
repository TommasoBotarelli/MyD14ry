#include <QtTest>
#include "../../ShoppingProduct.h"
#include "../../ShoppingList.h"
#include "../../ShoppingListController.h"
// add necessary includes here

class TestShoppingListController : public QObject
{
    Q_OBJECT

public:
    TestShoppingListController();
    ~TestShoppingListController();

private slots:

    void testSetData();

};

TestShoppingListController::TestShoppingListController()
{

}

TestShoppingListController::~TestShoppingListController()
{

}

void TestShoppingListController::testSetData() {
    ShoppingList shoppingList;
    ShoppingProduct shopProd;

    ShoppingListController SLC(&shoppingList,&shopProd);

    SLC.setData("test",true);
    QVERIFY(shopProd.getName()=="test");
    QVERIFY(shopProd.isCatched()==true);

}

QTEST_APPLESS_MAIN(TestShoppingListController)

#include "tst_testshoppinglistcontroller.moc"
