#include "../controller.h"
#include <QtTest>

// add necessary includes here

class myunittests : public QObject
{
    Q_OBJECT

public:
    myunittests();
    ~myunittests();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

myunittests::myunittests()
{

}

myunittests::~myunittests()
{

}

void myunittests::initTestCase()
{

}

void myunittests::cleanupTestCase()
{

}

void myunittests::test_case1()
{
    auto median1 = calculateMedianValue({1,3,4,5});
    QVERIFY(median1 == 3.5);
}

QTEST_APPLESS_MAIN(myunittests)

#include "tst_myunittests.moc"
