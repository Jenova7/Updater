#include <QApplication>
#include "testwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationVersion ("1.0.0");

    TestWindow testW;
    testW.show();

    return app.exec();
}
