QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DialogEnter/dialogenter.cpp \
    Note.cpp \
    WidgetAdministrator/formadministratorgeneral.cpp \
    WidgetDev/formdevgeneral.cpp \
    WidgetSpecialist/formspecialistgeneral.cpp \
    main.cpp \
    mianwindow.cpp \
    models/querymodelclient.cpp \
    persons/Administrator.cpp \
    persons/Client.cpp \
    persons/Person.cpp \
    persons/Specialist.cpp

HEADERS += \
    DialogEnter/dialogenter.h \
    Note.h \
    WidgetAdministrator/formadministratorgeneral.h \
    WidgetDev/formdevgeneral.h \
    WidgetSpecialist/formspecialistgeneral.h \
    loginIsValid.h \
    mianwindow.h \
    models/querymodelclient.h \
    persons/Administrator.h \
    persons/Client.h \
    persons/Person.h \
    persons/Specialist.h

FORMS += \
    DialogEnter/dialogenter.ui \
    WidgetAdministrator/formadministratorgeneral.ui \
    WidgetDev/formdevgeneral.ui \
    WidgetSpecialist/formspecialistgeneral.ui \
    mianwindow.ui

TRANSLATIONS += \
    PsyCenter_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    sql/db.sqlite
