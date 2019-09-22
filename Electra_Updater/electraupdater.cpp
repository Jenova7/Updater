#include "electraupdater.h"
#include "ui_electraupdater.h"



// Define the URL of the Update Definitions file
static const QString DEFS_URL = "https://raw.githubusercontent.com/"
                                "Jenova7/Updater/master/"
                                "updates.json";

ElectraUpdater::ElectraUpdater(QWidget *parent) : QWidget(parent)
{
    ui = new Ui::ElectraUpdater;
    ui->setupUi(this);
    setWindowTitle(qApp->applicationName());
}


ElectraUpdater::~ElectraUpdater()
{
    delete ui;
}

void ElectraUpdater::on_m_updateNo_clicked()
{
    //close the updater and continue the normal process:
    this->close();
}

void ElectraUpdater::on_m_updateYes_clicked()
{
    this->close();
    //start the download:
}
