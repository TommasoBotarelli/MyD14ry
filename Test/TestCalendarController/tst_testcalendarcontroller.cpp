#include <QtTest>
#include <QString>
#include <QDate>
#include "file_h/Event.h"
#include "file_h/Calendar.h"
#include "file_h/CalendarController.h"



// add necessary includes here

class TestCalendarController : public QObject {
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
    Event event;
    Calendar calendar;
    CalendarController CC(&calendar);
    std::list<Event> list;

    QTime time(10,30);
    QTime time2(12,00);

    calendar.addEvent(event);

    CC.setData(event,"task",QDate::currentDate(),"note",time,time2,false);
    list.clear();
    calendar.getEvent(list);
    QVERIFY(event.getNote()=="note");
}

void TestCalendarController::testSearchEventOfDay() {
    Event event;
    Calendar calendar;
    CalendarController CC(&calendar);
    QListWidget List;

    event.setDate(QDate::currentDate());
    event.setTask("Test");
    calendar.addEvent(event);

    CC.searchEventOfDay(QDate::currentDate(),List);
    QVERIFY(List.count()==1);
}

void TestCalendarController::testRemove() {
    Event event;
    Event event2;
    Calendar calendar;
    CalendarController CC(&calendar);
    std::list<Event> list;

    calendar.addEvent(event);
    calendar.addEvent(event2);

    CC.remove(event);
    list.clear();
    calendar.getEvent(list);
    QVERIFY(list.size() == 1);


    CC.remove(event2);
    list.clear();
    calendar.getEvent(list);
    QVERIFY(list.empty());
}

QTEST_MAIN(TestCalendarController)

#include "tst_testcalendarcontroller.moc"
