#include "testwindow.h"
#include "electraupdater.h"

TestWindow::TestWindow() : QWidget()
{
    setFixedSize(600,480);
    setWindowTitle("test");
    m_testButon = new QPushButton("check for update", this);
    m_testButon->setCursor(Qt::PointingHandCursor);


    QObject::connect(m_testButon, SIGNAL(clicked()), this, SLOT(UpdateWindow()));
}

void TestWindow::UpdateWindow(){

    ElectraUpdater *ecaUpdater = new ElectraUpdater;
    ecaUpdater->show();
    this->close();
}

