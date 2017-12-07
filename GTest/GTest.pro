TEMPLATE = app
TARGET = GTest
LIBS += -Llib -lgtest -lgmock
INCLUDEPATH += ./include
DEFINES += QT_DEPRECATED_WARNINGS
MOC_DIR = MediumFiles
OBJECTS_DIR = MediumFiles

# Input

HEADERS += ../Logic/PosStack.h
SOURCES += src/PopStackTest.cpp \
           ../Logic/PosStack.cpp
