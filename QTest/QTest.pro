TEMPLATE = app
QT += testlib
TARGET = QTest
CONFIG += testcase
DEFINES += QT_DEPRECATED_WARNINGS
MOC_DIR = MediumFiles
OBJECTS_DIR = MediumFiles

# Input
HEADERS += TestMain.h \
           ../Logic/PosStack.h
SOURCES += TestMain.cpp \
           PosStackTest.cpp \
           ../Logic/PosStack.cpp
