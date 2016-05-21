#-------------------------------------------------
#
# Project created by QtCreator 2016-03-26T15:31:55
#
#-------------------------------------------------

QMAKE_CFLAGS -= -O2
QMAKE_CFLAGS -= -O1
QMAKE_CXXFLAGS -= -O2
QMAKE_CXXFLAGS -= -O1
QMAKE_CFLAGS = -Ofast
QMAKE_CXXFLAGS = -Ofast
QMAKE_CXXFLAGS += -std=c++11

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fire
TEMPLATE = app


SOURCES += main.cpp\
    glwidget.cpp \
    thread.cpp

HEADERS  += \
    glwidget.h \
    random.h \
    thread.h

CONFIG += mobility
MOBILITY = 

