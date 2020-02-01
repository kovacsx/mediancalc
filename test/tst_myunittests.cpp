#include "../controller.h"
#include <QtTest>

// add necessary includes here

class myunittests : public QObject
{
    Q_OBJECT

public:
//    myunittests();
//    ~myunittests();

private slots:
//    void initTestCase();
//    void cleanupTestCase();
    void test_case1();
    void test_case1_data();

};

//myunittests::myunittests()
//{

//}

//myunittests::~myunittests()
//{

//}

void myunittests::test_case1_data()
{
    QTest::addColumn<QVector<QVariant>>("values");
    QTest::addColumn<double>("result");

    QTest::newRow("one elem") << QVector<QVariant>{1} << 1.0;
    QTest::newRow("two elem") << QVector<QVariant>{1,2} << 1.5;
    QTest::newRow("three elem") << QVector<QVariant>{1,2,3} << 2.0;

}
void myunittests::test_case1()
{
    QFETCH(QVector<QVariant>, values);
    QFETCH(double, result);

    auto median1 = calculateMedianValue(values);
    QVERIFY(median1 == result);
}

QTEST_APPLESS_MAIN(myunittests)

#include "tst_myunittests.moc"
