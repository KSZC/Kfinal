QT       += core gui network core5compat

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QIPMSG
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        qipmsg.cpp \
    user.cpp \
    udpsession.cpp \
    formchat.cpp \
    dialogsetting.cpp \
    fileserver.cpp \
    fileclient.cpp \
    filetransworker.cpp \
    filerecv.cpp

HEADERS += \
        qipmsg.h \
    user.h \
    udpsession.h \
    formchat.h \
    dialogsetting.h \
    fileserver.h \
    fileclient.h \
    filetransworker.h \
    filerecv.h \
    common.h

FORMS += \
        qipmsg.ui \
    formchat.ui \
    dialogsetting.ui

CONFIG += mobility
MOBILITY = 


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc \
    translations.qrc

TRANSLATIONS += translations_zh.ts

RC_ICONS =qipmsg.ico

