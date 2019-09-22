#include "testwindow.h"
#include "electraupdater.h"

TestWindow::TestWindow() : QWidget()
{
    setFixedSize(300,200);
    m_testButon = new QPushButton("check for update", this);
    m_testButon->setCursor(Qt::PointingHandCursor);


    QObject::connect(m_testButon, SIGNAL(clicked()), this, SLOT(UpdateWindow()));
}

void TestWindow::UpdateWindow(){

    /*
    ElectraUpdater ecaUpdater;
    ecaUpdater.show();
    this->close();*/
    auto ecaUpdater = new ElectraUpdater;
    ecaUpdater->show();
    this->close();
}

