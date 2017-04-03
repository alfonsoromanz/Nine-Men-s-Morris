#-------------------------------------------------
#
# Project created by QtCreator 2013-12-22T00:00:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = morris
TEMPLATE = app


SOURCES += main.cpp \
    controller/maincontroller.cpp \
    model/gamemodel.cpp \
    view/gameview.cpp \
    view/vertexitem.cpp \
    controller/player.cpp \
    controller/movement.cpp \
    model/boardstate.cpp \
    view/pieceitem.cpp \
    controller/gamecontroller.cpp \
    view/controlbutton.cpp

HEADERS  += \
    controller/maincontroller.h \
    controller/gamecontroller.h \
    model/gamemodel.h \
    view/gameview.h \
    view/vertexitem.h \
    controller/player.h \
    controller/movement.h \
    model/boardstate.h \
    view/pieceitem.h \
    view/controlbutton.h

FORMS    += \
    view/mainmenu.ui \
    view/endmenu.ui

RESOURCES += \
    resources/board.qrc

RC_FILE = resources/icon.rc
