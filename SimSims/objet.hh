#pragma once
#include <string>

class Objet
{
public:
    Objet(std::string n, int tailleXInit, int tailleYInit, int tailleZInit);
    ~Objet() = default;

    std::string getNom()
    { return _nom; }

    float getRed()
    { return _couleurR; }

    float getGreen()
    { return _couleurG; }

    float getBlue()
    { return _couleurB; }

    int getPosX()
    { return _positionX; }

    int getPosY()
    { return _positionY; }

    int getPosZ()
    { return _positionZ; }

    int getAngX()
    { return _angleX; }

    int getAngY()
    { return _angleY; }

    int getAngZ()
    { return _angleZ; }

    int getScale()
    { return _scale; }

    int getTaiX()
    { return _tailleX; }

    int getTaiY()
    { return _tailleY; }

    int getTaiZ()
    { return _tailleZ; }

    int getId()
    { return _id; }

private:
    std::string _nom;
    int _id;
    int _tailleX;
    int _tailleY;
    int _tailleZ;

    float _couleurR;
    float _couleurG;
    float _couleurB;
    int _positionX;
    int _positionY;
    int _positionZ;
    int _angleX;
    int _angleY;
    int _angleZ;
    int _scale;
};
