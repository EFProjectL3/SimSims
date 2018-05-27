#include "environnement.hh"
#include <stdlib.h>
#include <time.h>
#include <iostream>


extern GLuint textures[];

GLfloat largeurMoitieSol(40);

std::vector<arbre> arbres;
bool arbreCrees = false;

std::vector<arbre> creerArbres()
{
    srand(time(NULL));

    std::vector<arbre> lesArbres;

    for (unsigned int i(0); i<50; i++)
    {
        GLfloat rInt = 0.9 + static_cast <GLfloat> (rand()) /( static_cast <GLfloat> (RAND_MAX/(0.2)));
        GLfloat rExt = rInt + 0.1 + static_cast <GLfloat> (rand()) /( static_cast <GLfloat> (RAND_MAX/(0.2)));
        int nbMotifInt = rand() % 8 + 10;
        GLfloat nbMot = static_cast <GLfloat>(nbMotifInt);
        GLfloat nbTra = 20 + static_cast <GLfloat> (rand()) /( static_cast <GLfloat> (RAND_MAX/(20)));
        GLfloat haut = 8 + static_cast <GLfloat> (rand()) /( static_cast <GLfloat> (RAND_MAX/(3)));
        arbre a(rInt, rExt, nbMot, nbTra, haut);
        lesArbres.push_back(a);
    }
    return lesArbres;
}

void affiche7(unsigned int & indiceArbre)
{
    glPushMatrix();
    {
        arbres[indiceArbre].dessinerArbre();    //Arbre 1
        indiceArbre++;
        glTranslated(10,0,0);
        arbres[indiceArbre].dessinerArbre();    //Arbre 2
        indiceArbre++;
        glTranslated(10,0,0);
        arbres[indiceArbre].dessinerArbre();    //Arbre 3
        indiceArbre++;
        glTranslated(10,0,0);
        arbres[indiceArbre].dessinerArbre();    //Arbre 4
        indiceArbre++;
        glTranslated(10,0,0);
        arbres[indiceArbre].dessinerArbre();    //Arbre 5
        indiceArbre++;
        glTranslated(10,0,0);
        arbres[indiceArbre].dessinerArbre();    //Arbre 6
        indiceArbre++;
        glTranslated(10,0,0);
        arbres[indiceArbre].dessinerArbre();    //Arbre 7
        indiceArbre++;
    }
    glPopMatrix();
}

void affiche2(unsigned int & indiceArbre)
{
    glPushMatrix();
    {
        arbres[indiceArbre].dessinerArbre();    //Arbre 1
        indiceArbre++;
        glTranslated(70,0,0);
        arbres[indiceArbre].dessinerArbre();    //Arbre 2
        indiceArbre++;
    }
    glPopMatrix();
}

void creerEnvironnement()
{
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();		//Sol
    {
        glColor3f(0.2,0.2,0.2);
        glBindTexture(GL_TEXTURE_2D,textures[1]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0,0.0);
        glVertex3f(-largeurMoitieSol, -0.9f, largeurMoitieSol);  //bas gauche
        glTexCoord2f(30.0,0.0);
        glVertex3f(largeurMoitieSol, -0.9f, largeurMoitieSol);  //bas droite
        glTexCoord2f(30.0,30.0);
        glVertex3f(largeurMoitieSol, -0.9f, -largeurMoitieSol);  //haut droite
        glTexCoord2f(0.0,30.0);
        glVertex3f(-largeurMoitieSol, -0.9f, -largeurMoitieSol); //haut gauche
        glEnd();
    }
    glPopMatrix();

    glPushMatrix();	//Plafond
    {
        glColor3f(1,1,1);
        glBindTexture(GL_TEXTURE_2D,textures[0]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0,0.0);
        glVertex3f(-largeurMoitieSol, 35.0f, -largeurMoitieSol);  //bas gauche
        glTexCoord2f(1.0,0.0);
        glVertex3f(largeurMoitieSol, 35.0f, -largeurMoitieSol);  //bas droite
        glTexCoord2f(1.0,2.0);
        glVertex3f(largeurMoitieSol, 35.0f, largeurMoitieSol);  //haut droite
        glTexCoord2f(0.0,1.0);
        glVertex3f(-largeurMoitieSol, 35.0f, largeurMoitieSol); //haut gauche
        glEnd();
    }
    glPopMatrix();

    glPushMatrix();	//Mur droit
    {
        glColor3f(1,1,1);
        glBindTexture(GL_TEXTURE_2D,textures[0]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0,0.0);
        glVertex3f(largeurMoitieSol, -0.9f, -largeurMoitieSol);  //bas gauche
        glTexCoord2f(5.0,0.0);
        glVertex3f(largeurMoitieSol, -0.9f, largeurMoitieSol);  //bas droite
        glTexCoord2f(5.0,1.0);
        glVertex3f(largeurMoitieSol, 35.0f, largeurMoitieSol);  //haut droite
        glTexCoord2f(0.0,1.0);
        glVertex3f(largeurMoitieSol, 35.0f, -largeurMoitieSol); //haut gauche
        glEnd();
    }
    glPopMatrix();
    glPushMatrix(); //Mur gauche
    {
        glColor3f(1,1,1);
        glBindTexture(GL_TEXTURE_2D,textures[0]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0,0.0);
        glVertex3f(-largeurMoitieSol, -0.9f, largeurMoitieSol);  //bas gauche
        glTexCoord2f(5.0,0.0);
        glVertex3f(-largeurMoitieSol, -0.9f, -largeurMoitieSol);  //bas droite
        glTexCoord2f(5.0,1.0);
        glVertex3f(-largeurMoitieSol, 35.0f, -largeurMoitieSol);  //haut droite
        glTexCoord2f(0.0,1.0);
        glVertex3f(-largeurMoitieSol, 35.0f, largeurMoitieSol); //haut gauche
        glEnd();
    }
    glPopMatrix();

    glPushMatrix(); //Mur fond
    {
        glColor3f(1,1,1);
        glBindTexture(GL_TEXTURE_2D,textures[0]); //On dit qu'on utilise cette texture
        glBegin(GL_QUADS);
        glTexCoord2f(0.0,0.0);
        glVertex3f(-largeurMoitieSol, -0.9f, -largeurMoitieSol);  //bas gauche
        glTexCoord2f(5.0,0.0);
        glVertex3f(largeurMoitieSol, -0.9f, -largeurMoitieSol);  //bas droite
        glTexCoord2f(5.0,1.0);
        glVertex3f(largeurMoitieSol, 35.0f, -largeurMoitieSol);  //haut droite
        glTexCoord2f(0.0,1.0);
        glVertex3f(-largeurMoitieSol, 35.0f, -largeurMoitieSol); //haut gauche
        glEnd();
    }
    glPopMatrix();


    glPushMatrix(); //Mur avant
    {
        glColor3f(1,1,1);
        glBindTexture(GL_TEXTURE_2D,textures[0]); //On dit qu'on utilise cette texture
        glBegin(GL_QUADS);
        glTexCoord2f(0.0,0.0);
        glVertex3f(largeurMoitieSol, -0.9f, largeurMoitieSol);  //bas gauche
        glTexCoord2f(5.0,0.0);
        glVertex3f(-largeurMoitieSol, -0.9f, largeurMoitieSol);  //bas droite
        glTexCoord2f(5.0,1.0);
        glVertex3f(-largeurMoitieSol, 35.0f, largeurMoitieSol);  //haut droite
        glTexCoord2f(0.0,1.0);
        glVertex3f(largeurMoitieSol, 35.0f, largeurMoitieSol); //haut gauche
        glEnd();
    }
    glPopMatrix();

    unsigned int indiceArbre(0);

    int arbXInit = -largeurMoitieSol+3;
    int arbZInit = -largeurMoitieSol+3;
    int arbYInit = -2;

    if (arbreCrees == false)
    {
        arbres = creerArbres();
        arbreCrees = true;
    }

    glPushMatrix();
    {

        glBindTexture(GL_TEXTURE_2D,textures[2]);

        glTranslated(arbXInit,arbYInit,arbZInit);
        affiche7(indiceArbre);    //Premier rangée
        glTranslated(0,0,10);
        affiche2(indiceArbre);     //Deuxieme rangée
        glTranslated(0,0,10);
        affiche2(indiceArbre);     //Troisieme rangée
        glTranslated(0,0,10);
        affiche2(indiceArbre);      //Quatième rangée
        glTranslated(0,0,10);
        affiche2(indiceArbre);      //Cinquieme rangée
        glTranslated(0,0,10);
        affiche2(indiceArbre);      //Sixème rangée
        glTranslated(0,0,10);
        affiche7(indiceArbre);     //Septieme rangée
    }
    glPopMatrix();
}

/*
 *
 * Les ombres sont basées sur ce tutoriel:
 * https://learnopengl.com/Advanced-Lighting/Shadows/Shadow-Mapping
 * et
 * https://opengl.developpez.com/tutoriels/opengl-tutorial/16-textures-ombre-shadow-mapping/
 *
 */

//A VOIR


