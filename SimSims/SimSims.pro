#-------------------------------------------------
#
# Project created by QtCreator 2018-04-04T15:14:42
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimSims
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp\
        widgetOGL.cpp\
        mainwindow.cpp\
        forme.cpp\
        lectureDoc.cpp\
        popup_lum.cc\
        popup_obj.cc\
        affichage.cpp\
        lumierepos.cc\
        objet.cc

HEADERS  += widgetOGL.h\
         mainwindow.h\
         forme.h\
         lectureDoc.h\
         popup_lum.hh\
         popup_obj.hh\
         affichage.hh\
         lumierepos.hh\
         objet.hh

LIBS += -lglut -lGLU

#####
