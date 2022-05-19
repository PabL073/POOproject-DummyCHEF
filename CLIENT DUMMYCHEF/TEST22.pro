QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addreteta.cpp \
    failedresetpassword.cpp \
    fieldscompleted.cpp \
    firstscreen.cpp \
    login.cpp \
    main.cpp \
    mainpage.cpp \
    photo.cpp \
    protocoale.cpp \
    register.cpp \
    resetpassword.cpp \
    showreteta.cpp \
    tcpclient.cpp

HEADERS += \
    addreteta.h \
    failedresetpassword.h \
    fieldscompleted.h \
    firstscreen.h \
    login.h \
    mainpage.h \
    photo.h \
    protocoale.h \
    register.h \
    resetpassword.h \
    showreteta.h \
    tcpclient.h

FORMS += \
    addreteta.ui \
    failedresetpassword.ui \
    fieldscompleted.ui \
    firstscreen.ui \
    login.ui \
    mainpage.ui \
    register.ui \
    resetpassword.ui \
    showreteta.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    img/showRR.png

RESOURCES += \
    Resources.qrc
