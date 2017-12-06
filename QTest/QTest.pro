TEMPLATE = app
QT += core testlib
QT -= gui
TARGET = QTest
CONFIG += console testcase
CONFIG -= app_bundle
RCC_DIR += MediumFiles
MOC_DIR += MediumFiles
OBJECTS_DIR += MediumFiles
DEFINES += QT_DEPRECATED_WARNINGS
INCLUDEPATH += .

# Input
HEADERS += TestMain.h \
           ../Logic/PosStack.h
SOURCES += TestMain.cpp \
           PosStackTest.cpp \
           ../Logic/PosStack.cpp
