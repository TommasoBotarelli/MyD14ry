#include <QtTest>
#include "/home/tommaso/Scrivania/MyD14ry/Activity.h"
#include "/home/tommaso/Scrivania/MyD14ry/Activity.cpp"

// add necessary includes here

class TestActivityList : public QObject {
    Q_OBJECT

public:
    TestActivityList();

    ~TestActivityList();

private
    slots:
            void

    test_case1();

};

TestActivityList::TestActivityList() {

}

TestActivityList::~TestActivityList() {

}

void TestActivityList::test_case1() {

}

QTEST_APPLESS_MAIN(TestActivityList)

#include "tst_testactivitylist.moc"
