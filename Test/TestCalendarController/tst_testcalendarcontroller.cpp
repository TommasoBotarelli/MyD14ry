#include <QtTest>
#include "../../Event.h"
#include "../../Calendar.h"
#include "../../CalendarController.h"

// add necessary includes here

class TestCalendarController : public QObject
{
    Q_OBJECT

public:
    TestCalendarController();
    ~TestCalendarController() override;

private slots:
    void testSetData();
    void testSearchEventOfDay();
    void testRemove();

};

TestCalendarController::TestCalendarController()
{

}

TestCalendarController::~TestCalendarController()
{

}

void TestCalendarController::testSetData() {

}


QTEST_APPLESS_MAIN(TestCalendarController)

#include "tst_testcalendarcontroller.moc"
