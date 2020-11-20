#include <QtTest>
#include <QString>
#include <QDate>
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
    Event event;
    Calendar calendar;
    CalendarController CC(&calendar,&event);

    QTime time(10,30);
    QTime time2(12,00);

    CC.setData("Task",QDate::currentDate(),"nota",time,time2,false);
    QVERIFY((*calendar.getEvent().begin())->getTask()==("Task("+ time.toString()+" - "+time2.toString()+")"));
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

void TestCalendarController::testRemove() {
    //TODO RIVEDERE E IMPLEMENTARE REMOVE
}

QTEST_MAIN(TestCalendarController)

#include "tst_testcalendarcontroller.moc"
