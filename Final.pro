#-------------------------------------------------
#
# Project created by QtCreator 2013-06-07T09:31:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Final
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    audio_analyser.cpp \
    Plot.cpp

HEADERS  += mainwindow.h \
    rssitype.h \
    rssiup.h \
    audio_analyser.h \
    Plot.h

CONFIG += qwt

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../VXIPNP/WinNT/lib/msc/ -lrssiup
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../VXIPNP/WinNT/lib/msc/ -lrssiup
else:unix: LIBS += -L$$PWD/../../VXIPNP/WinNT/lib/msc/ -lrssiup

INCLUDEPATH += $$PWD/../../VXIPNP/WinNT/lib/msc
DEPENDPATH += $$PWD/../../VXIPNP/WinNT/lib/msc

INCLUDEPATH +=C:/Qt/Qt5.0.2/QWT_install/Mingw/include
DEPENDPATH +=C:/Qt/Qt5.0.2/QWT_install/Mingw/include
