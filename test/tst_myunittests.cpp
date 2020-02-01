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
    void test_case_median_positive();
    void test_case_median_positive_data();

    void test_case_median_negative();

};

//myunittests::myunittests()
//{

//}

//myunittests::~myunittests()
//{

//}

void myunittests::test_case_median_positive_data()
{
    QTest::addColumn<QVector<QVariant>>("values");
    QTest::addColumn<double>("result");

    QTest::newRow("zero elem") << QVector<QVariant>{} << 0.0;
    QTest::newRow("one elem") << QVector<QVariant>{1} << 1.0;
    QTest::newRow("two elem") << QVector<QVariant>{1,2} << 1.5;
    QTest::newRow("three elem") << QVector<QVariant>{1,2,3} << 2.0;

}
void myunittests::test_case_median_positive()
{
    QFETCH(QVector<QVariant>, values);
    QFETCH(double, result);

    auto median1 = calculateMedianValue(values);
    QVERIFY2(median1 == result, qPrintable(QString("calculated median: %1, expected: %2").arg(median1).arg(result)));
}

void myunittests::test_case_median_negative()
{
//    QEXPECT_FAIL("", "three negative", Continue);
//    QVERIFY(0.0 == calculateMedianValue({1,2,3}));
}

QTEST_APPLESS_MAIN(myunittests)

#include "tst_myunittests.moc"
