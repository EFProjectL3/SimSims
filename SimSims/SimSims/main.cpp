#include <QApplication>
#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <QOpenGLTexture>

#include "forme.h"
#include "lectureDoc.h"
#include "mainwindow.h"
#include "forme.h"
#include "mainwindow.h"
#include "popup_obj.hh"
#include "popup_lum.hh"

int main(int argc, char *argv[])
{
    glutInit(&argc,argv);

    QApplication a(argc, argv);
    MainWindow w;

    QTranslator qtTranslator;
    qtTranslator.load("qt_"+QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&qtTranslator);

    w.resize(640,480);
    w.show();
    return a.exec();
}
