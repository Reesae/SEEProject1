#-------------------------------------------------
#
# Project created by QtCreator 2015-10-15T18:04:12
#
#-------------------------------------------------

QT       += core gui
QT += xlsx
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SieciPr1
TEMPLATE = app

CONFIG += c++14
CONFIG += static

SOURCES += main.cpp\
        dialog.cpp \
    element.cpp \
    transformer.cpp \
    line.cpp \
    engine.cpp \
    node.cpp \
    quadripole.cpp

HEADERS  += dialog.h \
    element.h \
    transformer.h \
    line.h \
    engine.h \
    node.h \
    quadripole.h
FORMS    += dialog.ui

