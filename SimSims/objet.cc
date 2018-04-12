#include "objet.hh"
#include "forme.h"

Objet::Objet(std::string n, int tailleXInit, int tailleYInit, int tailleZInit) : _nom(n), _tailleX(tailleXInit), _tailleY(tailleYInit), _tailleZ(tailleZInit),
                                                                                 _couleurR(0), _couleurG(0), _couleurB(0),
                                                                                 _positionX(0), _positionY(0), _positionZ(0),
                                                                                 _angleX(0), _angleY(0), _angleZ(0),
                                                                                 _scale(1)
{
    if (forme.getId() == 1)
        _id = 1;
}
