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

void affiche15(unsigned int & indiceArbre)
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

void affiche6(unsigned int & indiceArbre)
{
    glPushMatrix();
    {
        arbres[indiceArbre].dessinerArbre();    //Arbre 1
        indiceArbre++;
        glTranslated(70,0,0);
       /* arbres[indiceArbre].dessinerArbre();    //Arbre 2
        indiceArbre++;
        glTranslated(5,0,0);
        arbres[indiceArbre].dessinerArbre();    //Arbre 3
        indiceArbre++;
        glTranslated(45,0,0);
        arbres[indiceArbre].dessinerArbre();    //Arbre 4
        indiceArbre++;
        glTranslated(5,0,0);
        arbres[indiceArbre].dessinerArbre();    //Arbre 5
        indiceArbre++;
        glTranslated(5,0,0);
        */
        arbres[indiceArbre].dessinerArbre();    //Arbre 6
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

    bool fond = true;
    bool coteD = false;
    bool avant = false;
    bool coteG = false;

    if (arbreCrees == false)
    {
        arbres = creerArbres();
        arbreCrees = true;
    }

    glPushMatrix();
    {

        glBindTexture(GL_TEXTURE_2D,textures[2]);

        glTranslated(arbXInit,arbYInit,arbZInit);
        affiche15(indiceArbre);    //Premier rangée
        glTranslated(0,0,10);
        affiche6(indiceArbre);     //Deuxieme rangée
        glTranslated(0,0,10);
        affiche6(indiceArbre);     //Troisieme rangée
        glTranslated(0,0,10);
        affiche6(indiceArbre);      //Quatième rangée
        glTranslated(0,0,10);
        affiche6(indiceArbre);      //Cinquieme rangée
        glTranslated(0,0,10);
        affiche6(indiceArbre);      //Sixème rangée
        glTranslated(0,0,10);
        affiche15(indiceArbre);     //Septieme rangée



        /* PLACEMENT MANUEL */
        //glTranslated(arbX, arbY, arbZ);

        //glTranslated(3, arbY, 0);
        //arbres[0].dessinerArbre();

        /*  PLACEMENT AUTOMATIQUE
        for (unsigned int i(0); i<29;i++)
        {
            if ((arbX%5 == 0 && (avant == true || fond == true)) || (arbZ%5==0 && (coteG == true || coteD == true)))
            {
                std::cout << "Dessin " << i << "en X: " << arbX << " et Z: " << arbZ << std::endl;
                arbres[i].dessinerArbre();
                arbres[i].infoArbre();
            }


            if (fond == true && arbX == largeurMoitieSol-1)
            {
                fond = false;
                coteD = true;
                arbZ++;
                glTranslated(0,0,1);
            }
            if (fond == true && arbX < largeurMoitieSol-1)
            {
                arbX++;
                glTranslated(1,0,0);
            }
            //
            if (coteD == true && arbZ == largeurMoitieSol-1)
            {
                coteD = false;
                avant = true;
                arbX--;
                glTranslated(-1,0,0);
            }
            if (coteD == true && arbZ < largeurMoitieSol-1)
            {
                glTranslated(0,0,1);
                arbZ++;
            }
            //
            if (avant == true && arbZ == -largeurMoitieSol+1)
            {
                avant = false;
                coteG = true;
                arbZ--;
                glTranslated(0,0,-1);
            }
            if (avant == true && arbX > -largeurMoitieSol+1)
            {
                arbX--;
                glTranslated(-1,0,0);
            }
            //
            if (coteG == true && arbZ == -largeurMoitieSol+3)
            {
                coteG = false;
                fond = true;
                arbX++;
                glTranslated(1,0,0);
            }
            if (coteG == true && arbZ < -largeurMoitieSol+3)
            {
                arbZ++;
                glTranslated(0,0,1);
            }
    }*/
    }
    glPopMatrix();
}


