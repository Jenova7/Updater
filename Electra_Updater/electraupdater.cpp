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

    /* QSimpleUpdater is single-instance */
    m_updater = QSimpleUpdater::getInstance();

    /* Check for updates when the "Check For Updates" is ran*/
    connect (m_updater, SIGNAL (checkingFinished  (QString)), this, SLOT (updateChangelog(QString)));
    connect (m_updater, SIGNAL (appcastDownloaded (QString, QByteArray)), this, SLOT (displayAppcast(QString, QByteArray)));

    checkForUpdates();

    /* React to button clicks */
    //connect(m_updateUi->m_updateYes, SIGNAL(clicked()), this, SLOT(close()));//TODO
    connect(m_updateUi->m_updateNo, SIGNAL(clicked()), this, SLOT(close()));
}


ElectraUpdater::~ElectraUpdater()
{
    delete m_updateUi;
}

// Window::checkForUpdates
void ElectraUpdater::checkForUpdates()
{
    QString version = "2.0.0";

    /* Apply the settings */
    m_updater->setModuleVersion (DEFS_URL, version);
    m_updater->setNotifyOnFinish (DEFS_URL, true);
    m_updater->setNotifyOnUpdate (DEFS_URL, true);
    //m_updater->setUseCustomAppcast (DEFS_URL, true);
    m_updater->setDownloaderEnabled (DEFS_URL, true);
    m_updater->setMandatoryUpdate (DEFS_URL, true);

    /* Check for updates */
    m_updater->checkForUpdates (DEFS_URL);
    m_updateUi->m_updateText->setText(m_updater->getChangelog(DEFS_URL));
        if(m_updateUi->m_updateText->toPlainText().isEmpty())
        {
            m_updateUi->m_updateText->setText("<p>No changelog found...</p>");
        }
}

// Window::updateChangelog
void ElectraUpdater::updateChangelog (const QString& url){
    if (url == DEFS_URL)
            m_updateUi->m_updateText->setText (m_updater->getChangelog (url));
}

void ElectraUpdater::displayAppcast (const QString& url, const QByteArray& reply)
{
    if (url == DEFS_URL) {
        QString text = "This is the downloaded appcast: <p><pre>" +
                       QString::fromUtf8 (reply) +
                       "</pre></p><p> If you need to store more information on the "
                       "appcast (or use another format), just use the "
                       "<b>QSimpleUpdater::setCustomAppcast()</b> function. "
                       "It allows your application to interpret the appcast "
                       "using your code and not QSU's code.</p>";

        m_updateUi->m_updateText->setText (text);
    }
}
