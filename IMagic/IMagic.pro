TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        consoleprocessing.cpp \
        imageprocessing.cpp \
        main.cpp


INCLUDEPATH += /home/a/ImageMagick-7.0.10-21
INCLUDEPATH += /home/a/ImageMagick-7.0.10-21/Magick++/lib

MAKE_CXXFLAGS += $(shell Magick++-config --cxxflags)
LIBS += $(shell Magick++-config --libs)
DEFINES += "MAGICKCORE_QUANTUM_DEPTH=16"
DEFINES += "MAGICKCORE_HDRI_ENABLE=0"

HEADERS += \
    consoleprocessing.h \
    imageprocessing.h
