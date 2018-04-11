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

std::vector<std::shared_ptr<forme>> TOUTES_LES_FORMES;
std::vector<QOpenGLTexture *> TOUTES_LES_TEXTURES;

int main(int argc, char *argv[])
{
    /* DEBUG */
    float longueur = 0.25;
    float largeur = 0.25;
    float hauteur = 0.25;

    std::vector<float> test;
    test.push_back(longueur);
    test.push_back(largeur);
    test.push_back(hauteur);
    test.push_back(0.5*longueur);
    test.push_back(0.5*largeur);
    test.push_back(0.5*hauteur);
    test.push_back(1.33*longueur);
    test.push_back(1.33*largeur);
    test.push_back(1.33*hauteur);
    test.push_back(1.4*longueur);
    test.push_back(1.4*largeur);
    test.push_back(1.4*hauteur);
    test.push_back(1.5*longueur);
    test.push_back(1.5*largeur);
    test.push_back(1.5*hauteur);
    test.push_back(1.75*longueur);
    test.push_back(1.75*largeur);
    test.push_back(1.75*hauteur);
    test.push_back(2.15*longueur);
    test.push_back(2.15*largeur);
    test.push_back(2.15*hauteur);
    test.push_back(2.5*longueur);
    test.push_back(2.5*largeur);
    test.push_back(2.5*hauteur);


    char * fichierDonnees = "./FICHIER_DE_DONNEES";
    std::cout << "LECTURE DE L'INTRO" << std::endl;
    // Obtention du vecteur avec le nom des formes (on connait donc le nombre avec sa taille)
    std::vector<std::string> nomDesFormes = lireIntro(fichierDonnees);
    std::cout << "Terminé." << std::endl;
    for (unsigned int i(1); i<nomDesFormes.size()+1; i++)
    {
        std::cout << " ----- LECTURE DE L'OBJET " << i << " -----" << std::endl;
        std::shared_ptr<forme> ptrForme;
        ptrForme = creerFormesLecture(fichierDonnees,i,test);
        ptrForme->infoForme();
        TOUTES_LES_FORMES.push_back(ptrForme);
        std::cout << " ----- FIN DE L'OBJET " << i << " -----" << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << " ----- LECTURE DES TEXTURES -----" << std::endl;
    TOUTES_LES_TEXTURES = lireTextures(fichierDonnees);
    std::cout << " ----- TERMINE -----" << std::endl;
    std::cout << "***************************************" << std::endl;

    /*********************************/

    glutInit(&argc,argv);

    QApplication a(argc, argv);
    MainWindow w;

    QTranslator qtTranslator;
    qtTranslator.load("qt_"+QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&qtTranslator);

    //std::cout << "coucou";
    w.resize(640,480);
    w.show();

    return a.exec();
}
