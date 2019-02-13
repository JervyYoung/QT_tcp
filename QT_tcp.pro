#-------------------------------------------------
#
# Project created by QtCreator 2019-02-13T21:04:44
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_tcp
TEMPLATE = app


SOURCES += main.cpp\
        serverwidget.cpp \
    clientwidge.cpp

HEADERS  += serverwidget.h \
    clientwidge.h

FORMS    += serverwidget.ui \
    clientwidge.ui

CONFIG   +=C++11
