#include <QtTest>
#include "../../ShoppingProduct.h"
#include "../../ShoppingList.h"

// add necessary includes here

class TestShoppingList : public QObject {
    Q_OBJECT

public:
    TestShoppingList();

    ~TestShoppingList();

private
    slots:
            void testAddGetProduct();
};

TestShoppingList::TestShoppingList() {

}

TestShoppingList::~TestShoppingList() {

}

void TestShoppingList::testAddGetProduct() {
    ShoppingProduct shoppingProduct1;
    shoppingProduct1.setName("Prodotto 1");
    ShoppingList shoppingList;

    shoppingList.addProduct(&shoppingProduct1);
    QVERIFY(shoppingList.getProducts().size() == 1);
    QVERIFY((*shoppingList.getProducts().begin())->getName() == shoppingProduct1.getName());

    ShoppingProduct shoppingProduct2;
    shoppingProduct2.setName("Prodotto 1");

    shoppingList.addProduct(&shoppingProduct2);
    QVERIFY(shoppingList.getProducts().size() == 2);

    auto i = shoppingList.getProducts().begin();
    i = std::next(i, 1);

    QVERIFY((*i)->getName() == shoppingProduct2.getName());
}

QTEST_APPLESS_MAIN(TestShoppingList)

#include "tst_testshoppinglist.moc"
