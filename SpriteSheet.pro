QT -=gui
TARGET=SpriteSheet
DESTDIR=./
SOURCES+=SpriteSheet.c \
    player.c
cache()

QMAKE_CC= gcc -std=c99
QMAKE_CFLAGS+=$$system(sdl2-config  --cflags)
message(output from sdl2-config --cflags added to CXXFLAGS= $$QMAKE_CFLAGS)

LIBS+=$$system(sdl2-config  --libs)
message(output from sdl2-config --libs added to LIB=$$LIBS)
LIBS+=-lSDL2_image
macx:DEFINES+=MAC_OS_X_VERSION_MIN_REQUIRED=1060
CONFIG += console
CONFIG -= app_bundle

HEADERS += \
    player.h

