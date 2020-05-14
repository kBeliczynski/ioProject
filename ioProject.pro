TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        administrator.cpp \
        bazaKont.cpp \
        bibliotekamaterialow.cpp \
        film.cpp \
        konto.cpp \
        kreatorfilm.cpp \
        kreatorserial.cpp \
        kreatortransmisjilive.cpp \
        loginManager.cpp \
        main.cpp \
        serial.cpp \
        transmisjalive.cpp \
        kontopracownika.cpp \
        wideo.cpp

HEADERS += \
    administrator.h \
    bazaKont.h \
    bibliotekamaterialow.h \
    film.h \
    konto.h \
    kreatorfilm.h \
    kreatormaterialow.h \
    kreatorserial.h \
    kreatortransmisjilive.h \
    loginManager.h \
    material.h \
    serial.h \
    transmisjalive.h \
    kontopracownika.h \
    wideo.h

DISTFILES += \
        bazaKont.txt
