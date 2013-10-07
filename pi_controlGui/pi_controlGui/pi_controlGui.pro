#-------------------------------------------------
#
# Project created by QtCreator 2013-09-05T21:06:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pi_controlGui
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp\
        stdsoap2.cpp \
        soappiProxy.cpp \
        soapC.cpp

HEADERS  += widget.h\
        pi.nsmap\
        stdsoap2.h \
        soapStub.h \
        soappiProxy.h \
        soapH.h

FORMS    += widget.ui
#LIBS += C:\MinGW\lib\libws2_32.a
