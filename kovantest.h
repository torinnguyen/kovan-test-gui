#ifndef KOVANTEST_H
#define KOVANTEST_H

#include <QString>
#include <QObject>

class KovanTestEngine;

#define TEST_ERROR 1
#define TEST_INFO 0
#define TEST_DEBUG 2

class KovanTest : public QObject
{
    Q_OBJECT

private:
    int testNumber;
    QString *lastString;
    int lastResult;
    KovanTestEngine *engine;

protected:
    QString *name;

public:
    KovanTest();
    virtual void runTest() = 0;

    /* Called by the engine after a test has finished running */
    QString *getStatusString();
    int getStatusValue();

    /* Used for issuing callbacks */
    void setEngine(KovanTestEngine *engie);

    /* Tells this test what its position is */
    void setTestNumber(int number);
    QString *testName();

signals:
    void testStateUpdated(int level, int value, QString *message);
};

#endif // KOVANTEST_H
