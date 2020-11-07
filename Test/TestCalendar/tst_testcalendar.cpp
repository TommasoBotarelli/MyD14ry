#include <QtTest>
#include "../../Event.h"
#include "../../Calendar.h"

// add necessary includes here

class TestCalendar : public QObject
{
    Q_OBJECT

public:
    TestCalendar();
    ~TestCalendar() override;

private slots:
    void testAddGetEvent();
    void testRemoveEvent();

};

TestCalendar::TestCalendar()
{

}

TestCalendar::~TestCalendar()
{

}

void TestCalendar::testAddGetEvent() {
    Calendar calendar;
    Event e1;
    Event e2;

    e1.setTask("Compleanno");
    e2.setTask("Halloween");

    calendar.addEvent(&e1);
    calendar.addEvent(&e2);

    QVERIFY(calendar.getEvent().size()==2);
    QVERIFY((*calendar.getEvent().begin())->getTask()=="Compleanno");
    auto i = std::next(calendar.getEvent().begin(), 1);
    QVERIFY ((*i)->getTask() == "Halloween");

}

void TestCalendar::testRemoveEvent() {
    Calendar calendar;
    Event e1;
    Event e2;

    e1.setTask("Natale");
    e2.setTask("Pasqua");

    calendar.addEvent(& e1);
    calendar.addEvent(& e2);

    calendar.removeEvent(&e1);
    QVERIFY(calendar.getEvent().size()==1);

    calendar.removeEvent(&e2);
    QVERIFY(calendar.getEvent().empty());

}


QTEST_APPLESS_MAIN(TestCalendar)

#include "tst_testcalendar.moc"
