#include "forme.h"
#include <math.h>
#include <iostream>

#define NB_TEXTURE 50

struct coordonnees face::getCentre()
{
    return centre;
}


forme::forme(int id, int nbFac, int nbSom, int nbAtt, int nbrSommetParFaceMax, int ** facCons, struct sommet * tabSom, struct face * tabFac,
             std::map<std::string,float> tabAtt) : _idForme(id), _nomForme(""), _nbrFaces(nbFac), _nbrSommets(nbSom), _nbrAttributs(nbAtt),
    _nbrSommetParFaceMax(nbrSommetParFaceMax), _faceConstruction(facCons), _sommets(tabSom), _faces(tabFac), _attributs(tabAtt),
    _couleurR(204), _couleurG(204), _couleurB(204), _positionX(0), _positionY(0), _positionZ(0),
    _angleX(0), _angleY(0), _angleZ(0), _scale(1), _idTexture(-1), _FormesFille(), _parent(0)
{}

forme::~forme(){}

void forme::setAttribut(std::vector<float> valeursAtt)
{
    unsigned int indice = 0;
    for (std::map<std::string,float>::iterator it = _attributs.begin(); it!=_attributs.end();++it)
    {
        float valeur = valeursAtt[indice];
        it->second = valeur;
    }
}

void forme::supprimerFille(std::string nom)
{
    for (unsigned int i(0); i<_FormesFille.size(); i++)
    {
        if (_FormesFille[i]->getNomForme() == nom)
            _FormesFille.erase(_FormesFille.begin() + i);
    }
}

/**
 * @brief forme::checkNom
 * @param s
 * @return
 * Renvoie vrai si le nom donné en paramètre ne correspond ni au nom de la forme ni au nom de toutes ses filles
 */
bool forme::checkNomFilles(std::string s)
{
    bool chk = true;
    if (s == _nomForme)
    {
        chk = false;
        return chk;
    }
    if (_FormesFille.size() > 0)
    {
        unsigned int i(0);
        while (i<_FormesFille.size() && chk)
        {
            chk = _FormesFille[i]->checkNomFilles(s);
            i++;
        }
    }
    return chk;
}

void forme::infoForme()
{
    std::cout << "ID: " << _idForme << std::endl;
    //std::cout << "Nom forme: " << NOM_FORMES[_idForme-1] << std::endl;
    std::cout << "Nom de la forme: " << _nomForme << std::endl;
    std::cout << "Nombre de faces: " << _nbrFaces << std::endl;
    std::cout << "Nombre d'attributs: " << _nbrAttributs << std::endl;
    std::cout << "Nombre de sommets: " << _nbrSommets << std::endl;

    std::cout << "Map des attributs" << std::endl;
    for (std::map<std::string,float>::const_iterator it=_attributs.begin();it!=_attributs.end();++it)
    {
        std::cout << (*it).first << "," << (*it).second << " | ";
    }
    std::cout << std::endl;
    std::cout << "Tableau de construction" << std::endl;
    for (int i(0); i<_nbrFaces; i++)
        for (int j(0); j<3; j++)
            std::cout << "Initiale[" << i << "][" << j << "] : " << getFaceConstruction()[i][j] << std::endl;
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

extern GLuint textures[NB_TEXTURE];

void forme::afficher_forme()
{
    glPushMatrix();
    {

        glTranslatef(_positionX,_positionY,_positionZ);
        glPushMatrix();
        {
            glRotatef(_angleX,1,0,0);
            glRotatef(_angleY,0,1,0);
            glRotatef(_angleZ,0,0,1);
            glScalef(_scale,_scale,_scale);
            if (_idTexture != -1)
                glBindTexture(GL_TEXTURE_2D,textures[_idTexture]);
            glBegin(GL_TRIANGLES);
            {
                struct couleur coul;
                coul.r=static_cast<GLfloat>(_couleurR/255);
                coul.g=static_cast<GLfloat>(_couleurG/255);
                coul.b=static_cast<GLfloat>(_couleurB/255);
                coul.a=1.0;
                int j;
                for (j=0; j<=_nbrFaces; j++)	//parcours des faces
                {
                    glColor3f(coul.r,coul.g,coul.b);
                    for (int i(0); i<=2; i++)	// on parcours les 3 sommets de chaque face
                    {
                        if (_idTexture !=-1)
                        {
                            if (i==0)
                                glTexCoord2f(1.0,0.0);
                            if (i==1)
                                glTexCoord2f(0.0,1.0);
                            if (i==2)
                                glTexCoord2f(1.0,1.0);
                        }
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
        }
        glPopMatrix();
        for (unsigned int i(0); i<_FormesFille.size(); i++) //Pour que l'affichage de la forme se face par rapport à la forme parent
            _FormesFille[i]->afficher_forme();
    }
    glPopMatrix();
}
