QT += gui
QT += core
QT += network
QT += widgets

SOURCES += \
    QSimpleUpdater/src/Downloader.cpp \
    QSimpleUpdater/src/QSimpleUpdater.cpp \
    QSimpleUpdater/src/Updater.cpp \
    electraupdater.cpp \
    main.cpp \
    testwindow.cpp

DISTFILES += \
    QSimpleUpdater/QSimpleUpdater.pri \
    QSimpleUpdater/etc/resources/update.png \
    update.png

RESOURCES += \
    QSimpleUpdater/etc/resources/qsimpleupdater.qrc

FORMS += \
    QSimpleUpdater/src/Downloader.ui \
    electraupdater.ui

HEADERS += \
    QSimpleUpdater/include/QSimpleUpdater.h \
    QSimpleUpdater/src/Downloader.h \
    QSimpleUpdater/src/Updater.h \
    electraupdater.h \
    testwindow.h

include(QSimpleUpdater/QSimpleUpdater.pri)
