QT   += core gui widgets
LIBS += -lglut -lGLU

RESOURCES += ressource.qrc

QMAKE_CC = gcc
QMAKE_CXX = g++

TARGET = Aster.ia.ds
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++2a

INCLUDEPATH += discordRichPresence/lib/lib
LIBS += -ldiscord_game_sdk -Lsrc/discordRichPresence/lib/lib/x86_64/

SOURCES += \
     \
     $$files(src/discordRichPresence/*.cpp) \
     $$files(src/discordRichPresence/lib/*.cpp) \
     $$files(src/fonctions/*.cpp) \
     $$files(src/qt/*.cpp) \
     $$files(src/objets/*.cpp) \
     $$files(src/rendu/*.cpp) \
     $$files(src/touches/*.cpp) \
     $$files(src/math/*.cpp) \
     $$files(src/*.cpp) \
     $$files(includes/*.cpp) \

HEADERS += \
     \
     $$files(includes/*.h) \
     $$files(src/fonctions/*.h) \
     $$files(src/qt/*.h) \
     $$files(src/objets/*.h) \
     $$files(src/rendu/*.h) \
     $$files(src/touches/*.h) \
     $$files(src/math/*.h) \
     $$files(src/discordRichPresence/*.h) \
     $$files(src/discordRichPresence/lib/*.h) \


DESTDIR = ./
OBJECTS_DIR = build/obj
MOC_DIR = build/moc
UI_DIR = build/ui
