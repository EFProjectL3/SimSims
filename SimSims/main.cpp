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
    std::cout << "DEBUT MAIN" << std::endl;
    glutInit(&argc,argv);

    QApplication a(argc, argv);
    MainWindow w;

    QTranslator qtTranslator;
    qtTranslator.load("qt_"+QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&qtTranslator);

    w.resize(640,480);
    std::cout << "LANCEMENT AFFICHAGE" << std::endl;
    w.show();
    std::cout << "FIN LANCEMENT AFFICHAGE" << std::endl;
    std::cout << "FIN MAIN" << std::endl;
    return a.exec();
}
