QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

#gcc -rdynamic -o window main.c `pkg-config --cflags --libs gtk+-3.0`

QMAKE_CXXFLAGS += -rdynamic
QMAKE_CXXFLAGS += -Wall
#QMAKE_CXXFLAGS += `pkg-config --cflags gtk+-3.0`
#QMAKE_LFLAGS += `pkg-config --libs gtk+-3.0`


# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    sources/main.c \
    sources/LinkedStack.c \
    sources/Initialize.c


HEADERS += \
    headers/LinkedStack.h \
    headers/Initialize.h

DISTFILES += \
    sources/window_main.glade




# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Disable Qt core and Qt Graphical user interface (don't use Qt)
QT	    -= core
QT	    += gui

# Name of the target (executable file)
TARGET	    = gtk_test

# This is a console application
CONFIG	    += console
CONFIG	    += app_bundle

# This is an application
TEMPLATE    = app

# Sources files
SOURCES	    +=

# GTK+ library
CONFIG	+= link_pkgconfig
PKGCONFIG += gtk+-3.0

INCLUDEPATH += += `pkg-config --cflags gtk+-3.0`
LIBS += `pkg-config --cflags gtk+-3.0`
LIBS += -L/usr/local/lib -lSDL2
