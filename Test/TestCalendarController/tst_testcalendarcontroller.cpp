#include <QtTest>
#include <QString>
#include <QDate>
#include <QTime>
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


};

TestCalendarController::TestCalendarController()
{

}

TestCalendarController::~TestCalendarController()
{

}

void TestCalendarController::testSetData() {
    Event event;
    Calendar calendar;
    CalendarController CC(&calendar,&event);

    CC.setData("Task", QDate::currentDate(), "bla bla bla", QTime::currentTime(), QTime::currentTime(),true);
    QVERIFY((*calendar.getEvent().begin())->getTask()=="Task");


}


QTEST_APPLESS_MAIN(TestCalendarController)

#include "tst_testcalendarcontroller.moc"
