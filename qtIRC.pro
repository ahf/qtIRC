#-------------------------------------------------
#
# Project created by QtCreator 2011-07-27T10:39:16
#
#-------------------------------------------------

QT       += core gui network

TARGET = qtIRC
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    message.cpp \
    hostmask.cpp \
    client.cpp \
    messagehandler.cpp \
    nicknameinusemessagehandler.cpp \
    pingmessagehandler.cpp \
    privmsgmessagehandler.cpp \
    endofmotdmessagehandler.cpp

HEADERS  += mainwindow.h \
    message.h \
    hostmask.h \
    client.h \
    messagehandler.h \
    nicknameinusemessagehandler.h \
    pingmessagehandler.h \
    privmsgmessagehandler.h \
    endofmotdmessagehandler.h

FORMS    += mainwindow.ui
