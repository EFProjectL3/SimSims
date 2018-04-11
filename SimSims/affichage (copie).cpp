#include "affichage.hh"
#include <memory>
#include <GL/glut.h>
#include "forme.h"

extern std::vector<std::shared_ptr<forme>> TOUTES_LES_FORMES;
extern int angleX;
extern int angleY;

int anglePopupX;
int anglePopupY;

void affichage(std::string type)
{
    if (type == "main")   //affichage de toutes les formes
    {
//DebutAffichageMain
        glPushMatrix();
        {
            glRotatef(angleX,0,1,0);
            glRotatef(angleY,1,0,0);
            TOUTES_LES_FORMES[1]->afficher_forme();
        }
        glPopMatrix();
//FinAffichageMain
    }
    else if (type == "popup")  //affichage type popu
    {

        glPushMatrix();
        {
            anglePopupX++;
            anglePopupY=anglePopupY+2;
            glRotatef(anglePopupX,0,1,0);
            glRotatef(anglePopupY,1,0,0);
//DebutAffichagePopup

            TOUTES_LES_FORMES[0]->afficher_forme();
	    TOUTES_LES_FORMES[0]->infoForme();
//FinAffichagePopup
        }
        glPopMatrix();
    }
}
