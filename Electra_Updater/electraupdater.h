#ifndef ELECTRAUPDATER_H
#define ELECTRAUPDATER_H

#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <QPushButton>
#include <QSimpleUpdater.h>

namespace Ui {
class ElectraUpdater;
}

class QSimpleUpdater;

class ElectraUpdater : public QWidget
{
    Q_OBJECT

public:
    explicit ElectraUpdater(QWidget *parent = nullptr);
    void checkForUpdates();
    void updateChangelog (const QString& url);
    ~ElectraUpdater();

private slots:
    void on_m_updateYes_clicked();
    void on_m_updateNo_clicked();


private:
    Ui::ElectraUpdater *ui;
    QSimpleUpdater *m_updater;
    QPushButton *m_updateYes;
    QPushButton *m_updateNo;
};

#endif // ELECTRAUPDATER_H
