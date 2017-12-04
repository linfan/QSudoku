QT += testlib
TEMPLATE = app
TARGET = Test
INCLUDEPATH += .
CONFIG += testcase
RCC_DIR += MediumFiles
MOC_DIR += MediumFiles
OBJECTS_DIR += MediumFiles
DEFINES += QT_DEPRECATED_WARNINGS

# Input
HEADERS += \
           ../Logic/PosStack.h
SOURCES += TestMain.cpp \
           ../Logic/PosStack.cpp
