QT   += core gui widgets
LIBS += -lglut -lGLU

QMAKE_CC = gcc
QMAKE_CXX = g++

TARGET = Aster.IA.ds
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++1z

SOURCES += \
     \
     $$files(src/fonctions/*.cpp,true) \
     $$files(src/objets/*.cpp) \
     $$files(src/rendu/*.cpp) \
     $$files(src/touches/*.cpp) \
     $$files(src/*.cpp) \

HEADERS += \
     \
     $$files(src/fonctions/*.h) \
     $$files(src/objets/*.h) \
     $$files(src/rendu/*.h) \
     $$files(src/touches/*.h) \
     $$files(src/*.h) \

DESTDIR = ./
OBJECTS_DIR = build/obj
MOC_DIR = build/moc
UI_DIR = build/ui