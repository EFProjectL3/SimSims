#include "lumiereposdir.hh"
#include <iostream>

#define LUMIERE_POSITIONNELLE 1.0
#define LUMIERE_DIRECTIONNELLE 0.0


LumierePos::LumierePos(bool t, std::__cxx11::string n, int XInit, int YInit, int ZInit) : _typeButton(t), _nom(n), _positionDirectionX(XInit), _positionDirectionY(YInit), _positionDirectionZ(ZInit), _couleurR(0), _couleurG(0), _couleurB(0)
{}


void LumierePos::afficher_lumiere(int i)
{
    GLfloat rTmp = static_cast<GLfloat>(_couleurR);
    GLfloat gTmp = static_cast<GLfloat>(_couleurG);
    GLfloat bTmp = static_cast<GLfloat>(_couleurB);
    GLfloat r = rTmp/255;
    GLfloat g = gTmp/255;
    GLfloat b = bTmp/255;
    GLfloat ambiante[] = {r, g, b, 0.0};
    GLfloat speculaire[] = {r, g, b, 0.0};
    GLfloat diffuse[] = {r, g, b, 0.0};

    GLfloat posDirX = static_cast<GLfloat>(_positionDirectionX);
    GLfloat posDirY = static_cast<GLfloat>(_positionDirectionY);
    GLfloat posDirZ = static_cast<GLfloat>(_positionDirectionZ);

    GLfloat lumiere[4];

    if (_typeButton == true)
    {
        lumiere[0] = posDirX;
        lumiere[1] = posDirY;
        lumiere[2] = posDirZ;
        lumiere[3] = LUMIERE_POSITIONNELLE;
    }
    else
    {
        lumiere[0] = posDirX;
        lumiere[1] = posDirY;
        lumiere[2] = posDirZ;
        lumiere[3] = LUMIERE_DIRECTIONNELLE;
    }

    switch (i)
    {
    case 0:
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambiante);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, speculaire);
        glLightfv(GL_LIGHT0, GL_POSITION, lumiere);
        glEnable(GL_LIGHT0);
        break;
    case 1:
        glLightfv(GL_LIGHT1, GL_AMBIENT, ambiante);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
        glLightfv(GL_LIGHT1, GL_SPECULAR, speculaire);
        glLightfv(GL_LIGHT1, GL_POSITION, lumiere);
        glEnable(GL_LIGHT1);
        break;
    case 2:
        glLightfv(GL_LIGHT2, GL_AMBIENT, ambiante);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse);
        glLightfv(GL_LIGHT2, GL_SPECULAR, speculaire);
        glLightfv(GL_LIGHT2, GL_POSITION, lumiere);
        glEnable(GL_LIGHT2);
        break;
    case 3:
        glLightfv(GL_LIGHT3, GL_AMBIENT, ambiante);
        glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuse);
        glLightfv(GL_LIGHT3, GL_SPECULAR, speculaire);
        glLightfv(GL_LIGHT3, GL_POSITION, lumiere);
        glEnable(GL_LIGHT3);
        break;
    case 4:
        glLightfv(GL_LIGHT4, GL_AMBIENT, ambiante);
        glLightfv(GL_LIGHT4, GL_DIFFUSE, diffuse);
        glLightfv(GL_LIGHT4, GL_SPECULAR, speculaire);
        glLightfv(GL_LIGHT4, GL_POSITION, lumiere);
        glEnable(GL_LIGHT4);
        break;
    case 5:
        glLightfv(GL_LIGHT5, GL_AMBIENT, ambiante);
        glLightfv(GL_LIGHT5, GL_DIFFUSE, diffuse);
        glLightfv(GL_LIGHT5, GL_SPECULAR, speculaire);
        glLightfv(GL_LIGHT5, GL_POSITION, lumiere);
        glEnable(GL_LIGHT5);
        break;
    case 6:
        glLightfv(GL_LIGHT6, GL_AMBIENT, ambiante);
        glLightfv(GL_LIGHT6, GL_DIFFUSE, diffuse);
        glLightfv(GL_LIGHT6, GL_SPECULAR, speculaire);
        glLightfv(GL_LIGHT6, GL_POSITION, lumiere);
        glEnable(GL_LIGHT6);
        break;
    case 7:
        glLightfv(GL_LIGHT7, GL_AMBIENT,ambiante);
        glLightfv(GL_LIGHT7, GL_DIFFUSE, diffuse);
        glLightfv(GL_LIGHT7, GL_SPECULAR, speculaire);
        glLightfv(GL_LIGHT7, GL_POSITION, lumiere);
        glEnable(GL_LIGHT7);
        break;
    }
}
