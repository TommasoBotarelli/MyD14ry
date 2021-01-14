#include <QtTest>
#include "file_h/Event.h"
#include "file_h/Calendar.h"

// add necessary includes here

class TestCalendar : public QObject {
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
    std::list<Event> list;

    e1.setTask("Compleanno");
    e2.setTask("Halloween");

    calendar.addEvent(e1);
    calendar.addEvent(e2);

    calendar.getEvent(list);

    QVERIFY(list.size()==2);
    QVERIFY(list.begin()->getTask()=="Compleanno");
    auto i = std::next(list.begin(), 1);
    QVERIFY ((*i).getTask() == "Halloween");

}

void TestCalendar::testRemoveEvent() {
    Calendar calendar;
    Event e1;
    Event e2;
    std::list<Event> list;

    e1.setTask("Natale");
    e2.setTask("Pasqua");

    calendar.addEvent(e1);
    calendar.addEvent(e2);

    calendar.removeEvent(e1);

    calendar.getEvent(list);
    QVERIFY(list.size()==1);

    calendar.removeEvent(e2);
    list.clear();
    calendar.getEvent(list);
    QVERIFY(list.empty());

}


QTEST_APPLESS_MAIN(TestCalendar)

#include "tst_testcalendar.moc"
