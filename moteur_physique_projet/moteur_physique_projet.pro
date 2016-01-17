TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-graphics -lsfml-window -lsfml-system

SOURCES += \
    masse_ressort/src/link.cpp \
    masse_ressort/src/main.cpp \
    masse_ressort/src/mat.cpp \
    masse_ressort/src/modeleur.cpp \
    masse_ressort/src/utils.cpp

HEADERS += \
    masse_ressort/include/modeleur.h \
    masse_ressort/include/link.h \
    masse_ressort/include/mat.h \
    masse_ressort/include/utils.h

