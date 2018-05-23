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

SOURCES += main.cpp\
        mainwindow.cpp\
        forme.cpp\
        lectureDoc.cpp\
        lumiereposdir.cc\
        normale.cc\
        popup_lum.cc\
        popup_obj.cc\
        popup_text.cc\
        ppm.cc\
        widgetOGL.cpp\
        labelClic.cc\
        environnement.cc\
        arbre.cc

HEADERS  += mainwindow.h\
         forme.h\
         lectureDoc.h\
         lumiereposdir.hh\
         normale.hh\
         popup_lum.hh\
         popup_obj.hh\
         popup_text.hh\
         ppm.h\
         widgetOGL.h\
         labelClic.hh\
         environnement.hh\
         arbre.hh

LIBS += -lglut -lGLU

#####
