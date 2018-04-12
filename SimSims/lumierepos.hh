#pragma once
#include <string>

class LumierePos
{
public:
    LumierePos(std::string n, int posXInit, int posYInit, int posZInit);
    ~LumierePos() = default;

    std::string getNom()
    { return _nom; }

    int getPosX()
    { return _positionX; }

    int getPosY()
    { return _positionY; }

    int getPosZ()
    { return _positionZ; }

    float getRed()
    { return _couleurR; }

    float getGreen()
    { return _couleurG; }

    float getBlue()
    { return _couleurB; }

private:
    std::string _nom;
    int _positionX;
    int _positionY;
    int _positionZ;
    float _couleurR;
    float _couleurG;
    float _couleurB;
};
