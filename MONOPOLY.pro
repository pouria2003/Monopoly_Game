QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    board.cpp \
    deed.cpp \
    deedcontainer.cpp \
    dice.cpp \
    getplayersnumber.cpp \
    main.cpp \
    mainwindow.cpp \
    monopoly.cpp \
    nonpropertyspace.cpp \
    player.cpp \
    playerinfo.cpp \
    playersname.cpp \
    propertyspace.cpp \
    station.cpp \
    street.cpp \
    utility.cpp

HEADERS += \
    board.h \
    boardspace.h \
    deed.h \
    deedcontainer.h \
    dice.h \
    getplayersnumber.h \
    mainwindow.h \
    monopoly.h \
    nonpropertyspace.h \
    player.h \
    playerinfo.h \
    playersname.h \
    propertyspace.h \
    station.h \
    street.h \
    utility.h

FORMS += \
    monopoly.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
