#include <QtWidgets/QApplication>
#include <QtCore/QTextCodec>
#include "sudokuWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
    sudokuMain widget;
    widget.show();
    return app.exec();
}
