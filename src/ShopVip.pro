#-------------------------------------------------
#
# Project created by QtCreator 2018-06-06T10:24:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VipMgr
TEMPLATE = app

RC_FILE = ShopVip.rc

SOURCES += main.cpp\
    basewindow.cpp \
    loginwindow.cpp \
    mainwindow.cpp \
    controls/qpopbutton.cpp \
    controls/mtoolbtn.cpp \
    controls/menubutton.cpp \
    core/windowmanagar.cpp \
    core/systemtray.cpp \
    ui/addmemberarea.cpp \
    ui/defaultinfoarea.cpp

HEADERS  += basewindow.h \
    loginwindow.h \
    mainwindow.h \
    controls/qpopbutton.h \
    controls/mtoolbtn.h \
    controls/menubutton.h \
    data/taskData.h \
    core/windowmanagar.h \
    core/systemtray.h \
    ui/addmemberarea.h \
    ui/defaultinfoarea.h

FORMS    += basewindow.ui \
    loginwindow.ui \
    ui/addmemberarea.ui \
    ui/defaultinfoarea.ui

RESOURCES += \
    images.qrc \
    qss.qrc \
    lang.qrc

OTHER_FILES += \
    qss/linkdood.qss \
    ShopVip.rc
