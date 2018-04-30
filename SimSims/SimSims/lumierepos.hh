#pragma once
#include <string>
#include <QOpenGLFunctions>

class LumierePos
{
public:
    LumierePos(std::string n, int posXInit, int posYInit, int posZInit);
    ~LumierePos() = default;

    void afficher_lumiere(int i);

    std::string getNom()
    { return _nom; }

    int getPosX()
    { return _positionX; }

    int getPosY()
    { return _positionY; }

    int getPosZ()
    { return _positionZ; }

    int getRed()
    { return _couleurR; }

    int getGreen()
    { return _couleurG; }

    int getBlue()
    { return _couleurB; }

    /* SETTER */
    void setPosX(int px)
    { _positionX = px; }

    void setPosY(int py)
    { _positionY = py; }

    void setPosZ(int pz)
    { _positionZ = pz; }

    void setRed(int r)
    { _couleurR = r; }

    void setGreen(int g)
    { _couleurG = g; }

    void setBlue(int b)
    { _couleurB = b; }

    void getNom(std::string n)
    { _nom = n; }

private:

    std::string _nom;
    int _positionX;
    int _positionY;
    int _positionZ;
    int _couleurR;
    int _couleurG;
    int _couleurB;
};
