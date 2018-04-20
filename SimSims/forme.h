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

    forme creation_forme();

    void afficher_forme();

    void infoForme();

    /* Setters */
    void setAttribut(std::vector<float> valeursAtt);

    void setId(int id)
    { _idForme = id; }

    void setNomForme(std::string nom)
    { _nomForme = nom; }

    void setRed(GLfloat r)
    { _couleurR = r; }

    void setGreen(GLfloat g)
    { _couleurG = g; }

    void setBlue(GLfloat b)
    { _couleurB = b; }

    void setPosX(GLfloat x)
    { _positionX = x; }

    void setPosY(GLfloat y)
    { _positionY = y; }

    void setPosZ(GLfloat z)
    { _positionZ = z; }

    void setAng(GLfloat x)
    { _angleX = x; }

    void setAngY(GLfloat y)
    { _angleY = y; }

    void setAngZ(GLfloat z)
    { _angleZ = z; }

    void setScale(float s)
    { _scale = s; }

    void clearFormesFilles()
    { _FormesFille.clear(); }

    void supprimerFille(std::string nom);

    void ajoutFormesFilles(std::shared_ptr<forme> f)
    { _FormesFille.push_back(f); }

    void setParent(std::shared_ptr<forme> p)
    { _parent = p; }

    /* Getters */
    int getId()
    {return _idForme;}
    std::string getNomForme()
    { return _nomForme; }
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

    GLfloat getRed()
    { return _couleurR; }
    GLfloat getGreen()
    { return _couleurG; }
    GLfloat getBlue()
    { return _couleurB; }
    GLfloat getPosX()
    { return _positionX; }
    GLfloat getPosY()
    { return _positionY; }
    GLfloat getPosZ()
    { return _positionZ; }
    GLfloat getAngX()
    { return _angleX; }
    GLfloat getAngY()
    { return _angleY; }
    GLfloat getAngZ()
    { return _angleZ; }
    GLfloat getScale()
    { return _scale; }
    std::vector<std::shared_ptr<forme>> getFilles()
    { return _FormesFille; }

    std::shared_ptr<forme> getParent()
    { return _parent; }

private:
    int _idForme;
    std::string _nomForme;
    int _nbrFaces;
    int _nbrSommets;
    int _nbrAttributs;
    int _nbrSommetParFaceMax;

    int ** _faceConstruction;
    struct sommet * _sommets;
    struct face * _faces;

    std::map<std::string,float> _attributs;

    GLfloat _couleurR;
    GLfloat _couleurG;
    GLfloat _couleurB;
    GLfloat _positionX;
    GLfloat _positionY;
    GLfloat _positionZ;
    GLfloat _angleX;
    GLfloat _angleY;
    GLfloat _angleZ;
    GLfloat _scale;

    std::vector<std::shared_ptr<forme>> _FormesFille;
    std::shared_ptr<forme> _parent;
};

void lireFormes(char* fichier, int numeroObjet);
