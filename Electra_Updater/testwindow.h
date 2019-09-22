#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include <QProgressBar>
#include <QMessageBox>


class TestWindow : public QWidget
{
    Q_OBJECT

public:
    TestWindow();

public slots:
    void UpdateWindow();

private:
    QPushButton *m_testButon;
};

#endif // TESTWINDOW_H
