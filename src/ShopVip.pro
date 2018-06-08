#-------------------------------------------------
#
# Project created by QtCreator 2018-06-06T10:24:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ShopVip
TEMPLATE = app


SOURCES += main.cpp\
    basewindow.cpp \
    loginwindow.cpp \
    mainwindow.cpp \
    controls/qpopbutton.cpp \
    controls/mtoolbtn.cpp \
    controls/menubutton.cpp \
    core/windowmanagar.cpp \
    core/systemtray.cpp

HEADERS  += basewindow.h \
    loginwindow.h \
    mainwindow.h \
    controls/qpopbutton.h \
    controls/mtoolbtn.h \
    controls/menubutton.h \
    data/taskData.h \
    core/windowmanagar.h \
    core/systemtray.h

FORMS    += basewindow.ui \
    loginwindow.ui

RESOURCES += \
    images.qrc \
    qss.qrc \
    lang.qrc

OTHER_FILES += \
    qss/linkdood.qss
