#pragma once
#include <string>
#include <QOpenGLFunctions>

class LumierePos
{
public:
    LumierePos(bool t, std::string n, int posXInit, int posYInit, int posZInit);
    ~LumierePos() = default;

    void afficher_lumiere(int i);

    bool getType()
    { return _typeButton; }

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
    void setType(bool t)
    { _typeButton = t; }

    void getNom(std::string n)
    { _nom = n; }

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


private:

    /* Le booléen va nous servir à enregistrer le type de la lumière créée, true pour Positionnelle, false pour Directionnelle.
        Dans le cas où la lumière sera directionnelle, les variables de position X, Y et Z correspondront à sa direction X, Y et Z. */
    bool _typeButton;
    std::string _nom;
    int _positionX;
    int _positionY;
    int _positionZ;
    int _couleurR;
    int _couleurG;
    int _couleurB;
};
