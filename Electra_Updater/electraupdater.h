#ifndef ELECTRAUPDATER_H
#define ELECTRAUPDATER_H

#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include <QSimpleUpdater.h>
#include <QIcon>
#include <QProgressBar>
#include <QTextEdit>

namespace Ui {
class ElectraUpdater;
}

class QSimpleUpdater;

class ElectraUpdater : public QWidget
{
    Q_OBJECT

public:
    explicit ElectraUpdater(QWidget *parent = nullptr);
    ~ElectraUpdater();

private slots:
    void checkForUpdates();
    void updateChangelog (const QString& url);
    void displayAppcast (const QString& url, const QByteArray& reply);

private:
    Ui::ElectraUpdater *m_updateUi;
    QSimpleUpdater *m_updater;
    QPushButton *m_updateYes;
    QPushButton *m_updateNo;
    QProgressBar *m_updateBar;
    QTextEdit *m_updateText;
};

#endif // ELECTRAUPDATER_H
