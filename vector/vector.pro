TEMPLATE = app
TARGET = vector_ex
CONFIG -= qt
CONFIG += c++14
CONFIG += console
QT -= gui core

INCLUDEPATH = /usr/include/
LIBS += -static -lboost_unit_test_framework

SOURCES += main.cpp
HEADERS += vector.hpp
