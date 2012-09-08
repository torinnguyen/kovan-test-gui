#-------------------------------------------------
#
# Project created by QtCreator 2012-05-31T15:23:00
#
#-------------------------------------------------

QT       += core gui network

TARGET = kovan-test
TEMPLATE = app


SOURCES += main.cpp\
        kovantestwindow.cpp \
    kovantest.cpp \
    externaltest.cpp \
    kovantestengine.cpp \
    delayedtextprinttest.cpp \
    motortest.cpp \
    switchtest.cpp \
    test-accel.c \
    test-io.c \
    test-serial.c \
    test-servo.c \
    test-usb.c \
    batterytest.cpp \
    hdmitest.cpp \
    fpga.c gpio.c \
    wifitest.cpp


linux-gnueabi-oe-g++ {
    CONFIG += link_pkgconfig
    PKGCONFIG += alsa
    QMAKE_CXXFLAGS += -Wno-psabi
}

HEADERS  += kovantestwindow.h \
    kovantest.h \
    externaltest.h \
    kovantestengine.h \
    delayedtextprinttest.h \
    batterytest.h \
    motortest.h \
    switchtest.h \
    hdmitest.h \
    wifitest.h \
    fpga.h

FORMS    += kovantestwindow.ui

#-----------------------------------------------------------

# Name of output folders
# Changes the name of the target, when is debug mode
CONFIG( debug, debug|release ) {
    TARGET = $${TARGET}_debug
    BUILD_NAME = debug
}
CONFIG( release, debug|release ) {
    BUILD_NAME = release
}

# Temporary folders for the auxiliar files
INCLUDEPATH += $$PWD/tmp/$$BUILD_NAME
OBJECTS_DIR = $$PWD/tmp/$$BUILD_NAME
MOC_DIR = $$PWD/tmp/$$BUILD_NAME
UI_DIR = $$PWD/tmp
RCC_DIR = $$PWD/tmp
DESTDIR = $$PWD/bin
