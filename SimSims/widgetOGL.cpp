#include "widgetOGL.h"
#include <GL/glut.h>
#include <QOpenGLTexture>
#include <fstream>
#include <iostream>
#include "ppm.h"
#include "environnement.hh"
#define NOMBRE_TEXTURE 50

int angleX;
int angleY;
int anglePopupX;
int anglePopupY;

GLuint textures[NOMBRE_TEXTURE];

WidgetOGL::WidgetOGL(int fps, QWidget *parent, std::string type, std::vector<LumierePos> ptr_lum, std::vector<std::string> adr) : QOpenGLWidget(parent), _type(type), _formesAAfficher(), _ensemble_lumiere(ptr_lum), _adressesTX(adr)
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
    if (_type == "main")
        _poszcam = -10;
    else
        _poszcam = -8;
    _angxcam = 0;
    _angycam = 0;
    _angzcam = 0;

    /* Lumières */
    _ambianteR = 0.8;
    _ambianteV = 0.8;
    _ambianteB = 0.8;
}

WidgetOGL::~WidgetOGL()
{}

void WidgetOGL::supprimerForme(std::string nom)
{
    std::cout << "******************** SUPPRIMER FORME *************************" << std::endl;
    for (unsigned int i(0); i < _formesAAfficher.size(); i++)
    {
        if(_formesAAfficher[i]->getNomForme() == nom)
        {
            std::cout << "On supprime de l'affichage de base la forme: " << _formesAAfficher[i]->getNomForme() << std::endl;
            _formesAAfficher.erase(_formesAAfficher.begin()+i);
        }
    }
}

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
    /*****************/

    /********** TEXTURES ************/
    if (_type == "main")
    {
        glGenTextures(NOMBRE_TEXTURE,textures);
        //Ciel
        TEXTURE_STRUCT * TXCiel = readPpm("./Images/Ciel.ppm");
        glBindTexture(GL_TEXTURE_2D,textures[0]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,TXCiel->width,TXCiel->height,0,GL_RGB,GL_UNSIGNED_BYTE,TXCiel->data);
        //Herbe
        TEXTURE_STRUCT * TXHerbe = readPpm("./Images/Herbe.ppm");
        glBindTexture(GL_TEXTURE_2D,textures[1]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,TXHerbe->width,TXHerbe->height,0,GL_RGB,GL_UNSIGNED_BYTE,TXHerbe->data);
        //Autre
        for (unsigned int i(0); i<_adressesTX.size();i++)
        {
            char * adrChar = new char[_adressesTX[i].size() + 1];
            std::copy(_adressesTX[i].begin(), _adressesTX[i].end(), adrChar);
            adrChar[_adressesTX[i].size()] = '\0';

            TEXTURE_STRUCT * TX = readPpm(adrChar);
            glBindTexture(GL_TEXTURE_2D,textures[i+2]);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,TX->width,TX->height,0,GL_RGB,GL_UNSIGNED_BYTE,TX->data);

            delete[] adrChar;
        }
        glEnable(GL_TEXTURE_2D);
    }
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
    glRotatef(_angxcam, 0, 1, 0);
    glRotatef(_angycam, 1, 0, 0);
    glRotatef(_angzcam, 0, 0, 1);
    glTranslatef(_posxcam,_posycam,_poszcam);

    /* Lumières */
    GLfloat lumiere_ambiante[4] = { _ambianteR, _ambianteV, _ambianteB, 0.0 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lumiere_ambiante);
    for (unsigned int i(0); i<_ensemble_lumiere.size(); i++)
        _ensemble_lumiere[i].afficher_lumiere(i);

    if (_type == "main")   //affichage de toutes les formes
    {
        creerEnvironnement();

        glRotatef(angleX,0,1,0);
        glRotatef(angleY,1,0,0);

        for (unsigned int i(0); i<_formesAAfficher.size(); i++)
        {
            _formesAAfficher[i]->afficher_forme();
        }
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


/*
 * Sauvegarde et chargement
 */

void WidgetOGL::sauvegardeScene()
{
    std::cout << "***** DEBUT DE SAUVEGARDE DE SCENE *****" << std::endl;

    std::string nomFichier;
    //std::cout << "Entrer non du fichier" << std::endl;
    //std::cin >> nomFichier;
    nomFichier = "fichierTest";
    nomFichier = "./" + nomFichier;
    std::ofstream fichier(nomFichier.c_str(), std::ios::out);
    if(fichier)  // si l'ouverture a réussi
    {
        for (unsigned int i(0); i<_formesAAfficher.size();i++)
        {
            fichier << "//FORME" << std::endl;
            fichier << _formesAAfficher[i]->getId() << std::endl;
            fichier << _formesAAfficher[i]->getNomForme() << std::endl;
            fichier << _formesAAfficher[i]->getNbrFace() << std::endl;
            fichier << _formesAAfficher[i]->getNbrSommet() << std::endl;
            fichier << _formesAAfficher[i]->getNbrAtt() << std::endl;
            fichier << _formesAAfficher[i]->getnbrSommetsParFaceMax() << std::endl;
            //fichier << _formesAAfficher[i]->getAttributs().to_string() << std::endl;
            fichier << _formesAAfficher[i]->getRed() << std::endl;
            fichier << _formesAAfficher[i]->getGreen() << std::endl;
            fichier << _formesAAfficher[i]->getBlue() << std::endl;
            fichier << _formesAAfficher[i]->getPosX() << std::endl;
            fichier << _formesAAfficher[i]->getPosY() << std::endl;
            fichier << _formesAAfficher[i]->getPosZ() << std::endl;
            fichier << _formesAAfficher[i]->getAngX() << std::endl;
            fichier << _formesAAfficher[i]->getAngY() << std::endl;
            fichier << _formesAAfficher[i]->getAngZ() << std::endl;
            fichier << _formesAAfficher[i]->getScale() << std::endl;
            fichier << "//TABFACECONS" << std::endl;
            for (int j(0); j< _formesAAfficher[i]->getNbrFace(); j++)
                for (int k(0); k<3; k++)
                    fichier << j << " " << k << _formesAAfficher[i]->getFaceConstruction()[j][k] << std::endl;
            fichier << "//TABFACES" << std::endl;
            for (int j(0); j<_formesAAfficher[i]->getNbrFace(); j++)
            {
                //fichier << "" << _formesAAfficher[i]->getFaces()[j].getCentre().x << " " << _formesAAfficher[i]->getFaces[j].getCentre().y << " " << _formesAAfficher[i]->getFaces[j].getCentre().z << std::endl;
            }
            fichier << "//TABSOMMETS" << std::endl;
            for (int j(0); j<_formesAAfficher[i]->getNbrSommet(); j++)
            {
                //fichier << "" << _formesAAfficher[i]->getSommets()[j].coordonnees.x << " " << _formesAAfficher[i]->getSommets()[j]->coordonnees.y << " " << _formesAAfficher[i]->getSommets()->coordonnees.z << std::endl;
            }
        }

        fichier.close();  // je referme le fichier

        std::cout << "***** FIN DE SAUVEGARDE DE SCENE *****" << std::endl;
    }
    else  // sinon
        std::cerr << "Erreur à l'ouverture !" << std::endl;
}

void WidgetOGL::chargementScene(std::string nomFichier)
{

}
