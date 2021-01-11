#-------------------------------------------------
#
# Project created by QtCreator 2016-12-22T10:50:43
#
#-------------------------------------------------

QT       += core gui multimedia
QT       += network
QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtWuziqi
TEMPLATE = app
SOURCES += main.cpp\
    dialog.cpp \
        mainwindow.cpp \
    GameModel.cpp \
    menulist.cpp

HEADERS  += mainwindow.h \
    GameModel.h \
    dialog.h \
    menulist.h

RESOURCES += \
    resource.qrc

FORMS += \
    dialog.ui \
    mainwindow.ui \
    menulist.ui
