QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../dorm.cpp \
    ../restaurant.cpp \
    ../room.cpp \
    ../student.cpp \
    adddormdialog.cpp \
    dialogaddstud.cpp \
    dormitorydialog.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../dorm.h \
    ../restaurant.h \
    ../room.h \
    ../student.h \
    adddormdialog.h \
    dialogaddstud.h \
    dormitorydialog.h \
    mainwindow.h

FORMS += \
    adddormdialog.ui \
    dialogaddstud.ui \
    dormitorydialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../.gitignore \
    ../program.exe
