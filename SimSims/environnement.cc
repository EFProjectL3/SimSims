#include "environnement.hh"

extern GLuint textures[];

GLfloat largeurMoitieSol(40);

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
}
