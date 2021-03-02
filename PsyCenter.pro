QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DialogEnter/dialogenter.cpp \
    User.cpp \
    formspecialistgeneral.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    DialogEnter/dialogenter.h \
    User.h \
    formspecialistgeneral.h \
    isValid.h \
    mainwindow.h

FORMS += \
    DialogEnter/dialogenter.ui \
    formspecialistgeneral.ui \
    mainwindow.ui

TRANSLATIONS += \
    PsyCenter_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    sql/db.sqlite
