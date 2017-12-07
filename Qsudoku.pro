TEMPLATE = app
UI_DIR += MediumFiles
RCC_DIR += MediumFiles
MOC_DIR += MediumFiles
OBJECTS_DIR += MediumFiles
INCLUDEPATH += . Dialogs MainWidget
DEPENDPATH += .
QT += network widgets

# Input
HEADERS += \
    Dialogs/Aboutdlg.h \
    Dialogs/ConformDlg.h \
    Dialogs/CopyrightDlg.h \
    Dialogs/ExplanatryDlg.h \
    Dialogs/ProcessDlg.h \
    Dialogs/RuleDlg.h \
    Logic/SudokuCalculator.h \
    MainWidget/SudokuWidget.h \
    Logic/PosStack.h \
    Logic/ConstPool.h
FORMS += Dialogs/rule.ui \
    Dialogs/process.ui \
    Dialogs/explanatry.ui \
    Dialogs/copyright.ui \
    Dialogs/aboutdlg.ui \
    Dialogs/conform.ui \
    MainWidget/sudokuWidget.ui
SOURCES += Main.cpp \
    Dialogs/Aboutdlg.cpp \
    Dialogs/ConformDlg.cpp \
    Dialogs/CopyrightDlg.cpp \
    Dialogs/ExplanatryDlg.cpp \
    Dialogs/ProcessDlg.cpp \
    Dialogs/RuleDlg.cpp \
    Logic/SudokuCalculator.cpp \
    MainWidget/ButtonAction.cpp \
    MainWidget/DiverseFunction.cpp \
    MainWidget/PushButton.cpp \
    MainWidget/SudokuWidget.cpp \
    Logic/PosStack.cpp
RESOURCES += Resource/sudoku.qrc
OTHER_FILES += MainWidget/nearlyFinish.table
