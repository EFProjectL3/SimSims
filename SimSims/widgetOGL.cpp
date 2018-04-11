#include "widgetOGL.h"
#include <GL/glut.h>
#include <QOpenGLTexture>
#include <iostream>
#include "affichage.hh"

extern std::vector<std::shared_ptr<forme>> TOUTES_LES_FORMES;
extern std::vector<QOpenGLTexture *> TOUTES_LES_TEXTURES;

int angleX;
int angleY;
int anglePopupX;
int anglePopupY;

WidgetOGL::WidgetOGL(int fps, QWidget *parent, std::string type) : QOpenGLWidget(parent), _type(type), _formesAAfficher()
{
    setFocusPolicy(Qt::StrongFocus);

    if (fps == 0)
        _timer = NULL;
    else
    {
        int seconde = 1000; //ms
        int intervalle = seconde / fps;
        _timer = new QTimer(this);
        QObject::connect(_timer,&QTimer::timeout,this,&WidgetOGL::timeOutSlot);
        _timer->start(intervalle);
    }

    /* Camera */
    _posxcam = 0;
    _posycam = 0;
    _poszcam = -5;

    /* Lumières */
    _ambianteR = 0.8;
    _ambianteV = 0.8;
    _ambianteB = 0.8;
}

WidgetOGL::~WidgetOGL()
{}

void WidgetOGL::setAmbianteR(int r)
{
    float val = static_cast<float>(r);
    _ambianteR = val/255;
}

void WidgetOGL::setAmbianteV(int v)
{
    float val = static_cast<float>(v);
    _ambianteV = val/255;
}

void WidgetOGL::setAmbianteB(int b)
{
    float val = static_cast<float>(b);
    _ambianteB = val/255;
}

void WidgetOGL::setPosXCam(int x)
{
    float val = static_cast<float>(x);
    _posxcam = val;
}

void WidgetOGL::setPosYCam(int y)
{
    float val = static_cast<float>(y);
    _posycam = val;
}

void WidgetOGL::setPosZCam(int z)
{
    float val = static_cast<float>(z);
    _poszcam = val-5;
}

void WidgetOGL::setAngXCam(int x)
{
    float val = static_cast<float>(x);
    _angxcam = val;
}

void WidgetOGL::setAngYCam(int y)
{
    float val = static_cast<float>(y);
    _angycam = val;
}

void WidgetOGL::setAngZCam(int z)
{
    float val = static_cast<float>(z);
    _angzcam = val-5;
}

void WidgetOGL::initializeGL()
{
    initializeOpenGLFunctions();

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    //On dit ce que l'on voudra utiliser plus tard dans notre programme. Ensuite on choisira si on les utilise ou non

    glClearColor(0.0f,0.0f,0.0f,1.0f);	//couleur d'effacement

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    // Effacer les faces non visibles
    glFrontFace(GL_CCW);	//on dit que les faces visibles sont les ccw
    glCullFace(GL_CW);	//et celles qui seront à effacer seront les cw

    /***** LUMIERE *****/
    //Lumiere et matériel
    glEnable(GL_LIGHTING);
    //Lumiere ambiante: on voit peu de base
    GLfloat lumiere_ambiante[4] = { _ambianteR, _ambianteV, _ambianteB, 0.0 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lumiere_ambiante);
    /* // Lumière 0: soleil du soir
    GLfloat ambiante0 [] = {0.2,0.2,0.0,0.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT,ambiante0);
    GLfloat diffuse0[] = { 0.2, 0.1, 0.0, 0.0 };
    glLightfv(GL_LIGHT0,GL_DIFFUSE, diffuse0);
    GLfloat speculaire0[] = {0.2,0.1,0.0,0.0};
    glLightfv(GL_LIGHT0,GL_SPECULAR,speculaire0);
    glEnable(GL_LIGHT0);*/
    /*****************/

    /********** TEXTURES ************/
    /*glGenTextures(47,textures);

    //Murs en papier peint
    TEXTURE_STRUCT * TXpapierP = readPpm("./Images/murs.ppm");
    glBindTexture(GL_TEXTURE_2D,textures[1]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,TXpapierP->width,TXpapierP->height,0,GL_RGB,GL_UNSIGNED_BYTE,TXpapierP->data);

    glEnable(GL_TEXTURE_2D);		*/
    /*********************************/
}


void WidgetOGL::timeOutSlot()
{
    update();
}

void WidgetOGL::slotUpdate()
{
    std::cout << "Update à la demande" << std::endl;
    update();
}

void WidgetOGL::keyPressEvent(QKeyEvent * keyEvent)
{
    switch (keyEvent->key())
    {
    case Qt::Key_A:
        angleX++;
        break;
    case Qt::Key_Z:
        angleX--;
        break;
    case Qt::Key_Q:
        angleY++;
        break;
    case Qt::Key_S:
        angleY--;
        break;
    }

}

void WidgetOGL::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //On enleve les couleurs ainsi que la profondeur avant de continuer

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //Placement de la caméra
    glRotatef(_angxcam, 1, 0, 0);
    glRotatef(_angycam, 0, 1, 0);
    glRotatef(_angzcam, 0, 0, 1);
    glTranslatef(_posxcam,_posycam,_poszcam);

    /* Lumières */
    GLfloat lumiere_ambiante[4] = { _ambianteR, _ambianteV, _ambianteB, 0.0 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lumiere_ambiante);

    //C'est ici qu'il faudra lire le fichier des données à afficher

    if (_type == "main")   //affichage de toutes les formes
    {
        glRotatef(angleX,0,1,0);
        glRotatef(angleY,1,0,0);

        for (unsigned int i(0); i<_formesAAfficher.size(); i++)
            _formesAAfficher[i]->afficher_forme();
    }
    else if (_type == "popup")  //affichage type popu
    {
        glPushMatrix();
        {
            anglePopupX++;
            anglePopupY=anglePopupY+2;
            glRotatef(anglePopupX,0,1,0);
            glRotatef(anglePopupY,1,0,0);

            if (_formesAAfficher.size()>0)
                _formesAAfficher[0]->afficher_forme();

        }
        glPopMatrix();
    }



    //affichage(_type);
}

void WidgetOGL::resizeGL(int Width, int Height)
{
    //fixe la tranformation de cadrage (avec glViewport);
    glViewport(0,0,Width,Height);
    //sélectionne la matrice de projection (avec glMatrixMode);
    glMatrixMode(GL_PROJECTION);
    //charge la matrice identité (avec glLoadIdentity);
    glLoadIdentity();
    //définit la perspective (avec gluPerspective);
    gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f, 100.0f);
    //sélectionne la matrice de visualisation-modélisation (avec glMatrixMode).
    update();
}
