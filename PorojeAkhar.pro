#-------------------------------------------------
#
# Project created by QtCreator 2016-06-18T04:37:43
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PorojeAkhar
TEMPLATE = app


SOURCES += \
    game.cpp \
    main.cpp \
    player.cpp \
    map.cpp \
    enemy.cpp

HEADERS  += \
    game.h \
    player.h \
    map.h \
    enemy.h

FORMS    +=

RESOURCES += \
    res.qrc
CONFIG += resources_big
