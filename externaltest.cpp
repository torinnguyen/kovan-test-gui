#include <QString>
#include <stdarg.h>
#include <stdint.h>
#include "externaltest.h"
#include "harness.h"

static ExternalTest *current = NULL;

struct tests {
        int (*func)(void);
        const char *name;
	const char *abbr;
};


extern "C" {
    extern int test_servo(void);
    extern int test_io(void);
    extern int test_usb(void);
    extern int test_audio(void);
    extern int test_serial(void);
    extern int test_accel_start(void);
    extern int test_accel_finish(void);
}



static struct tests tests[] = {
        { // 0  
                test_accel_start,
				"Start accelerometer read",
                "test-accel-start",
        },
        { // 2  
                test_serial,
                "Test serial ports",
                "test-serial",
        },
        { // 3  
                test_servo,
                "ADC and servos",
                "test-servo",
        },
        { // 4  
                test_io,
                "Digital I/O",
                "test-io",
        },
        { // 5  
                test_usb,
                "OTG and USB port",
                "test-usb",
        },
        { // 6  
                test_accel_finish,
                "Read accelerometer result",
                "test-accel-finish",
        },
};


ExternalTest::ExternalTest(QString *testName)
{
    unsigned int i;


    testNumber = -1;
    for (i=0; i<sizeof(tests)/sizeof(tests[0]); i++) {
        if (testName == QString::fromAscii(tests[i].abbr)) {
            testNumber = i;
            name = new QString(tests[i].name);
            break;
        }
    }
    if (!name)
        name = new QString("External test");
}


void ExternalTest::runTest() {
    if (testNumber != -1) {
        current = this;
        tests[testNumber].func();
    }
    return;
}


void ExternalTest::harnessBridge(int level, int code, char *fmt, va_list ap) {
	QString *tmp;

	tmp = new QString();
	tmp->vsprintf(fmt, ap);
    emit testStateUpdated(level, code, tmp);
}



void harness_error(uint32_t code, char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    if (current)
        current->harnessBridge(TEST_ERROR, code, fmt, ap);
    va_end(ap);
}

void harness_info(uint32_t code, char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    if (current)
        current->harnessBridge(TEST_INFO, code, fmt, ap);
    va_end(ap);
}

void harness_debug(uint32_t code, char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    if (current)
        current->harnessBridge(TEST_DEBUG, code, fmt, ap);
    va_end(ap);
}
