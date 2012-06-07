#-------------------------------------------------
#
# Project created by QtCreator 2012-05-30T12:17:30
#
#-------------------------------------------------

QT       += core gui

TARGET = PyIde
TEMPLATE = app


SOURCES += main.cpp\
        pyidemainwindow.cpp \
    aboutdialog.cpp \
    feedbackdialog.cpp \
    preferencesdialog.cpp

HEADERS  += pyidemainwindow.h \
    aboutdialog.h \
    feedbackdialog.h \
    preferencesdialog.h

FORMS    += pyidemainwindow.ui \
    aboutdialog.ui \
    feedbackdialog.ui \
    preferencesdialog.ui

RESOURCES += \
    pyResourceFile.qrc
