QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    categoryform.cpp \
    databasemanager.cpp \
    document.cpp \
    form.cpp \
    itemsform.cpp \
    main.cpp \
    mainwindow.cpp \
    measureunitsform.cpp

HEADERS += \
    categoryform.h \
    databasemanager.h \
    document.h \
    form.h \
    itemsform.h \
    mainwindow.h \
    measureunitsform.h

FORMS += \
    categoryform.ui \
    document.ui \
    itemsform.ui \
    mainwindow.ui \
    measureunitsform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
