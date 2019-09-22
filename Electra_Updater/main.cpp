#include <QApplication>
#include "testwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TestWindow testW;
    testW.show();

    return app.exec();
}
