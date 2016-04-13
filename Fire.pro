#-------------------------------------------------
#
# Project created by QtCreator 2016-03-26T15:31:55
#
#-------------------------------------------------

QMAKE_CFLAGS -= -O2
QMAKE_CFLAGS -= -O1
QMAKE_CXXFLAGS -= -O2
QMAKE_CXXFLAGS -= -O1
QMAKE_CFLAGS = -O3
QMAKE_CXXFLAGS = -O3

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fire
TEMPLATE = app


SOURCES += main.cpp\
    glwidget.cpp \
    random.cpp

HEADERS  += \
    glwidget.h \
    random.h

CONFIG += mobility
MOBILITY = 

