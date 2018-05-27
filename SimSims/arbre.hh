#pragma once
#include <QOpenGLFunctions>


/* Un "arbre" sera en fait un colonne cannelée comme le TP 12 de Stephan Igor en OpenGL,
 * afin d'avoir une forme régulière.
 */

class arbre
{

public:
    arbre(GLfloat rInt, GLfloat rExt, GLfloat nbMot, GLfloat nbTra, GLfloat haut);
    ~arbre();

    void dessinerArbre();

private:
    GLfloat _rayonInt;
    GLfloat _rayonExt;
    GLfloat _nombreMotif;
    GLfloat _nombreTranche;
    GLfloat _hauteur;
};
