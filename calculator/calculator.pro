######################################################################
# Automatically generated by qmake (3.0) Thu Oct 1 10:11:15 2015
######################################################################

TEMPLATE = app
TARGET = calculator
CONFIG -= qt
CONFIG += c++14
CONFIG += console
QT -= gui core

INCLUDEPATH = /usr/include/
LIBS += -static -lboost_unit_test_framework

# Input
SOURCES += main.cpp

HEADERS += calculator.cpp