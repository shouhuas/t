#-------------------------------------------------
#
# Project created by QtCreator 2014-08-14T18:44:11
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
lessThan(QT_MAJOR_VERSION, 5): CONFIG += static
QMAKE_CXXFLAGS = -fpermissive

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets
    DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0
}


TARGET = GridTrade
TEMPLATE = app

FORMS += \
    src/mainwindow.ui

HEADERS += \
    src/mainwindow.h \
    src/qbizmanager.h \
    src/qhttpmanager.h 

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/qbizmanager.cpp \
    src/qhttpmanager.cpp 


RESOURCES += \
    src/GridTrade.qrc




