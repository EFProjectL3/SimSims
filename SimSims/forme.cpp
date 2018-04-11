#include "forme.h"
#include <math.h>
#include <iostream>


forme::forme(int id, int nbFac, int nbSom, int nbAtt, int nbrSommetParFaceMax, int ** facCons, struct sommet * tabSom, struct face * tabFac, std::map<std::string,float> tabAtt) : _idForme(id), _nbrFaces(nbFac), _nbrSommets(nbSom), _nbrAttributs(nbAtt), _nbrSommetParFaceMax(nbrSommetParFaceMax), _faceConstruction(facCons), _sommets(tabSom), _faces(tabFac), _attributs(tabAtt)
{}

forme::forme(std::shared_ptr<forme> f): _idForme(f->getId()), _nbrFaces(f->getNbrFace()), _nbrSommets(f->getNbrSommet()), _nbrAttributs(f->getNbrAtt()), _nbrSommetParFaceMax(f->getnbrSommetsParFaceMax())
{
    _faceConstruction = f->getFaceConstruction();
    _sommets = f->getSommets();
    _faces = f->getFaces();
    _attributs = f->getAttributs();
}

void forme::setAttribut(std::vector<float> valeursAtt)
{
    unsigned int indice = 0;
    for (std::map<std::string,float>::iterator it = _attributs.begin(); it!=_attributs.end();++it)
    {
        float valeur = valeursAtt[indice];
        it->second = valeur;
    }
}

forme::~forme(){}

/*************/
int _idForme;
int _nbrFaces;
int _nbrSommets;
int _nbrAttributs;

struct sommet * _sommets;
struct face * _faces;

std::map<std::string,float> _attributs;

void forme::infoForme()
{
    std::cout << "ID: " << _idForme << std::endl;
    //std::cout << "Nom forme: " << NOM_FORMES[_idForme-1] << std::endl;
    std::cout << "Nombre de faces: " << _nbrFaces << std::endl;
    std::cout << "Nombre d'attributs: " << _nbrAttributs << std::endl;
    std::cout << "Nombre de sommets: " << _nbrSommets << std::endl;

    std::cout << "Map des attributs" << std::endl;
    for (std::map<std::string,float>::const_iterator it=_attributs.begin();it!=_attributs.end();++it)
    {
        std::cout << (*it).first << "," << (*it).second << " | ";
    }
    std::cout << std::endl;

    std::cout << "Tableau des sommets (coordonnées)" << std::endl;
    for (int i(0); i<_nbrSommets; i++)
    {
        std::cout << "Sommet numéro " << i << ":" << std::endl;
        std::cout << "X: " << _sommets[i].coordonnees.x << ", Y: " << _sommets[i].coordonnees.y << ", Z: " << _sommets[i].coordonnees.z << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Tableau des faces (centres)" << std::endl;
    for (int i(0); i<_nbrFaces; i++)
    {
        std::cout << "Face numéro " << i << ":" << std::endl;
        std::cout << "Sommets associés: " << _faceConstruction[i][0] << ", " << _faceConstruction[i][1] << ", " << _faceConstruction[i][2] << std::endl;
        std::cout << "Centre face: X:" << _faces[i].centre.x << ", Y: " << _faces[i].centre.y << ", Z: " << _faces[i].centre.z << std::endl;
    }
    std::cout << std::endl;
}

void forme::afficher_forme()
{
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    {
        struct couleur coul;
        coul.r=1.0;
        coul.g=1.0;
        coul.b=1.0;
        coul.a=1.0;
        int j;
        for (j=0; j<=_nbrFaces; j++)	//parcours des faces
        {
            glColor3f(coul.r,coul.g,coul.b);
            int i;
            for (i=0; i<=2; i++)	// on parcours les 3 sommets de chaque face
            {
                glVertex3f(
                            _sommets[_faceConstruction[j][i]].coordonnees.x,
                        _sommets[_faceConstruction[j][i]].coordonnees.y,
                        _sommets[_faceConstruction[j][i]].coordonnees.z
                        );
            }

        }
    }
    glEnd();
    //Pour voir la normale "physiquement"
    glBegin(GL_LINES);
    {
        int j;
        for (j=0;j<=_nbrFaces;j++)
        {
            glVertex3f(_faces[j].centre.x, _faces[j].centre.y, _faces[j].centre.z);
            glVertex3f(_faces[j].centre.x+_faces[j].norm.x, _faces[j].centre.y+_faces[j].norm.y, _faces[j].centre.z+_faces[j].norm.z);
        }
    }
    glEnd();
    glPopMatrix();
}
