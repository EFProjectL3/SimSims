#pragma once
#include <string>
#include <memory>
#include "forme.h"

class Objet
{
public:
    Objet(std::string n, std::shared_ptr<forme> ptr);
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

    std::shared_ptr<forme> getForme()
    { return _forme; }
/*
    int getTaiX()
    { return _tailleX; }

    int getTaiY()
    { return _tailleY; }

    int getTaiZ()
    { return _tailleZ; }

    int getId()
    { return _id; }
*/

private:
    std::string _nom;
    std::shared_ptr<forme> _forme;


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

    std::vector<Objet> _formesFilles;
};
