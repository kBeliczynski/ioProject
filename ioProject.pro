TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bibliotekamaterialow.cpp \
        film.cpp \
        kreatorfilm.cpp \
        kreatorserial.cpp \
        kreatortransmisjilive.cpp \
        main.cpp \
        serial.cpp \
        transmisjalive.cpp \
        wideo.cpp

HEADERS += \
    bibliotekamaterialow.h \
    film.h \
    kreatorfilm.h \
    kreatormaterialow.h \
    kreatorserial.h \
    kreatortransmisjilive.h \
    material.h \
    serial.h \
    transmisjalive.h \
    wideo.h
