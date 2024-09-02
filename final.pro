QT       += core gui
QT += multimedia
CONFIG += resources_big
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    background.cpp \
    bounus.cpp \
    bullet.cpp \
    enemy.cpp \
    entity.cpp \
    gameover.cpp \
    main.cpp \
    mainwindow.cpp \
    normalenemy.cpp \
    numbershow.cpp \
    player.cpp \
    sheidenemy.cpp \
    speedenemy.cpp \
    superenemy.cpp

HEADERS += \
    background.h \
    bounus.h \
    bullet.h \
    enemy.h \
    entity.h \
    gameover.h \
    mainwindow.h \
    normalenemy.h \
    numbershow.h \
    player.h \
    sheidenemy.h \
    speedenemy.h \
    superenemy.h

FORMS += \
    gameover.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    waiting.txt
