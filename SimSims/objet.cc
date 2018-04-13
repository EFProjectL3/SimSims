#include "objet.hh"
#include "forme.h"

Objet::Objet(std::string n, std::shared_ptr<forme> ptr) : _nom(n), _forme(ptr), _couleurR(0), _couleurG(0), _couleurB(0),
                                                                                 _positionX(0), _positionY(0), _positionZ(0),
                                                                                 _angleX(0), _angleY(0), _angleZ(0),
                                                                                 _scale(1)
{

}
