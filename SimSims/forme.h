#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QTimer>
#include <vector>
#include <iostream>
#include <memory>

#include "normale.hh"

/* Structures communes à toutes les formes */

struct couleur {
    GLfloat r,g,b,a;
};

struct coordonnees{
    GLfloat x,y,z;
};

struct sommet {
    struct coordonnees coordonnees;
};

struct face {
    struct couleur coul;
    struct normale norm;
    struct coordonnees centre;
};
/*******************************************/

class forme
{

public:
    forme(int id, int nbFac, int nbSom, int nbAtt, int nbrSommetParFaceMax, int ** faceCons, struct sommet * tabSom, struct face * tabFac, std::map<std::string,float> tabAtt);
    ~forme();

    forme(std::shared_ptr<forme> f);

    forme creation_forme();

    //void calcul_normale(float s0x, float s0y, float s0z, float s1x, float s1y, float s1z, float s2x, float s2y, float s2z, struct normale * normale);

    void afficher_forme();

    void infoForme();

    void test()
    { std::cout << "ID FORME EN COURS: " << _idForme << std::endl; }

    /* Setters */
    void setAttribut(std::vector<float> valeursAtt);

    /* Getters */
    int getId()
    {return _idForme;}
    int getNbrFace()
    {return _nbrFaces;}
    int getNbrSommet()
    {return _nbrSommets;}
    int getNbrAtt()
    {return _nbrAttributs;}
    int getnbrSommetsParFaceMax()
    {return _nbrSommetParFaceMax;}
    int ** getFaceConstruction()
    {return _faceConstruction;}
    struct sommet * getSommets()
    { return _sommets; }
    struct face * getFaces()
    { return _faces; }
    std::map<std::string,float> getAttributs()
    { return _attributs; }

private:
    int _idForme;
    int _nbrFaces;
    int _nbrSommets;
    int _nbrAttributs;
    int _nbrSommetParFaceMax;

    int ** _faceConstruction;
    struct sommet * _sommets;
    struct face * _faces;

    std::map<std::string,float> _attributs;

};

void lireFormes(char* fichier, int numeroObjet);
