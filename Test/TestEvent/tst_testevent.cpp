#include <QtTest>
#include <QDate>
#include <QString>
#include <QTime>
#include "../../Event.h"

// add necessary includes here

class TestEvent : public QObject
{
    Q_OBJECT

public:
    TestEvent();
    ~TestEvent() override;

private slots:
    void testSetterGetter();

};

TestEvent::TestEvent()
{

}

TestEvent::~TestEvent()
{

}

void TestEvent::testSetterGetter()
{
Event event;

event.setTask("Compleanno Marco");
QVERIFY(event.getTask()=="Compleanno Marco");
event.setTask("");
QVERIFY(event.getTask()=="Evento");

event.setDate(QDate::currentDate());
QVERIFY(event.getDate()==QDate::currentDate());
QDate Date(20,5,13);
event.setDate(Date);
QVERIFY(event.getDate()==Date);

event.setAllDay(true);
QVERIFY(event.isAllDay()==true);

QTime Time1(10,30);
event.setStartTime(Time1);
QVERIFY(event.getStartTime()==Time1);

QTime Time2(11,05);
event.setEndTime(Time2);
QVERIFY(event.getEndTime()==Time2);

QTime Time3(9,0);
event.setEndTime(Time3);
QVERIFY(event.getEndTime()==event.getStartTime().addSecs(3600));


event.setNote("Comprare la torta e le candeline");
QVERIFY(event.getNote()=="Comprare la torta e le candeline");

}

QTEST_APPLESS_MAIN(TestEvent)

#include "tst_testevent.moc"
