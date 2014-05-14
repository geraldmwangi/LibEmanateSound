#-------------------------------------------------
#
# Project created by QtCreator 2014-01-08T21:12:06
#
#-------------------------------------------------

QT       -= core gui

TARGET = LibEmanateSound
TEMPLATE = lib

DEFINES += LIBEMANATESOUND_LIBRARY
CXXFLAGS += -std=c++0x
SOURCES += libemanatesound.cpp \
    soundgenerator.cpp \
    parameteredobject.cpp \
    wavetable.cpp \
    sinustable.cpp \
    parameter.cpp \
    emanation.cpp \
    listener.cpp \
    soundengine.cpp \
    LibEmanateSound_c.cpp \
    parametermodulator.cpp \
    sinusmodulator.cpp \
    squaretable.cpp \
    sawtable.cpp \
    typefactory.cpp \
    EmanateTools.cpp \
    emexception.cpp

HEADERS += libemanatesound.h\
    AudioSourceIntf.h \
    EmanateTypes.h \
    soundgenerator.h \
    parameteredobject.h \
    wavetable.h \
    parameter.hxx \
    parameter.h \
    sinustable.h \
    emanation.h \
    listener.h \
    soundengine.h \
    LibEmanateSound_c.h \
    parametermodulator.h \
    sinusmodulator.h \
    squaretable.h \
    sawtable.h \
    typefactory.h \
    EmanateTools.h \
    emexception.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
