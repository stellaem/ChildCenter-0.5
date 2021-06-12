QMAKE_CXXFLAGS_WARN_ON -= -Wall
QT       += core gui sql quickwidgets quick qml quickcontrols2
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 qml_debug

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DialogEnter/dialogenter.cpp \
    WidgetAdministrator/widgetadministratortimetable.cpp \
    WidgetAdministrator/windowadmin.cpp \
    WidgetDev/windowdev.cpp \
    WidgetSpecialist/widgetclientbase.cpp \
    WidgetSpecialist/widgetprogram.cpp \
    WidgetSpecialist/widgetstatistic.cpp \
    WidgetSpecialist/widgettimetable.cpp \
    WidgetSpecialist/windowspecialist.cpp \
    main.cpp \
    models/modelclassesincabinet.cpp \
    models/tablemodeltask.cpp \
    objects/Note.cpp \
    objects/cabinet.cpp \
    objects/celltimetable.cpp \
    persons/Administrator.cpp \
    persons/Client.cpp \
    persons/Person.cpp \
    settings/appearance.cpp

HEADERS += \
    DialogEnter/dialogenter.h \
    WidgetAdministrator/widgetadministratortimetable.h \
    WidgetAdministrator/windowadmin.h \
    WidgetDev/windowdev.h \
    WidgetSpecialist/widgetclientbase.h \
    WidgetSpecialist/widgetprogram.h \
    WidgetSpecialist/widgetstatistic.h \
    WidgetSpecialist/widgettimetable.h \
    WidgetSpecialist/windowspecialist.h \
    loginIsValid.h \
    models/modelclassesincabinet.h \
    models/tablemodeltask.h \
    objects/Note.h \
    objects/cabinet.h \
    objects/celltimetable.h \
    persons/Administrator.h \
    persons/Client.h \
    persons/Person.h \
    persons/Specialist.h \
    settings/appearance.h \
    settings/appearance.h \
    settings/appearance.h \
    settings/settings.h

FORMS += \
    DialogEnter/dialogenter.ui \
    WidgetAdministrator/widgetadministratortimetable.ui \
    WidgetAdministrator/windowadmin.ui \
    WidgetDev/windowdev.ui \
    WidgetSpecialist/widgetclientbase.ui \
    WidgetSpecialist/widgetprogram.ui \
    WidgetSpecialist/widgetstatistic.ui \
    WidgetSpecialist/widgettimetable.ui \
    WidgetSpecialist/windowspecialist.ui

TRANSLATIONS += \
    PsyCenter_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/resources.qrc

