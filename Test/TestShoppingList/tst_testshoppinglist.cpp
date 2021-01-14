#include <QtTest>
#include "file_h/ShoppingProduct.h"
#include "file_h/ShoppingList.h"

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
    ShoppingProduct shoppingProduct2;
    ShoppingList shoppingList;
    std::list<ShoppingProduct> list;
    shoppingProduct1.setName("Prodotto 1");
    shoppingProduct2.setName("Prodotto 2");

    shoppingList.addProduct(shoppingProduct1);
    shoppingList.addProduct(shoppingProduct2);
    shoppingList.getProducts(list);
    QVERIFY(list.size() == 2);
    QVERIFY(list.begin()->getName() == "Prodotto 1");


    auto i = std::next(list.begin(), 1);

    QVERIFY((i)->getName() == "Prodotto 2");
}

QTEST_APPLESS_MAIN(TestShoppingList)

#include "tst_testshoppinglist.moc"
