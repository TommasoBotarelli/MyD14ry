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
   // void testSetData();
    void testSearchEventOfDay();
    //void testRemove();

};

TestCalendarController::TestCalendarController()
{

}

TestCalendarController::~TestCalendarController()
{

}



void TestCalendarController::testSearchEventOfDay() {
    Event event;
    Calendar calendar;
    CalendarController CC(&calendar, &event);
    QListWidget List;

    event.setDate(QDate::currentDate());
    event.setTask("Test");
    calendar.addEvent(&event);

    CC.searchEventOfDay(QDate::currentDate(),List);
    QVERIFY(List.count()==1);
}

QTEST_MAIN(TestCalendarController)

#include "tst_testcalendarcontroller.moc"
