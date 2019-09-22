#include "electraupdater.h"
#include "ui_electraupdater.h"



// Define the URL of the Update Definitions file
static const QString DEFS_URL = "https://raw.githubusercontent.com/"
                                "Jenova7/Updater/master/"
                                "updates.json";

ElectraUpdater::ElectraUpdater(QWidget *parent) : QWidget(parent)
{
    m_updateUi = new Ui::ElectraUpdater;
    m_updateUi->setupUi(this);

    setWindowTitle("Electra updater");
    setWindowIcon(QIcon(QCoreApplication::applicationDirPath() + "/update.png"));
    /* React to button clicks */
    connect(m_updateUi->m_updateYes, SIGNAL(clicked()), this, SLOT(close()));//TODO
    connect(m_updateUi->m_updateNo, SIGNAL(clicked()), this, SLOT(close()));
}


ElectraUpdater::~ElectraUpdater()
{
    delete m_updateUi;
}

void ElectraUpdater::checkForUpdates(){

}

void ElectraUpdater::updateChangelog (const QString& url){

}
