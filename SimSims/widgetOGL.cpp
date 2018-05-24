#include "widgetOGL.h"
#include <GL/glut.h>
#include <QOpenGLTexture>
#include <fstream>
#include <iostream>
#include "ppm.h"
#include "environnement.hh"
#include <sstream>
#include "lectureDoc.h" //pour explode
#include <memory>
#include "forme.h"
#include <QtWidgets>

#define NOMBRE_TEXTURE 50
#define SELECT 1
#define RENDER 0

int angleX;
int angleY;
int anglePopupX;
int anglePopupY;

//
int angTest(0);
int score(0);

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

    _modeRendu = RENDER;
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
        //Tronc
        TEXTURE_STRUCT * TXTronc = readPpm("./Images/Tronc.ppm");
        glBindTexture(GL_TEXTURE_2D,textures[2]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,TXTronc->width,TXTronc->height,0,GL_RGB,GL_UNSIGNED_BYTE,TXTronc->data);

        //Autre
        for (unsigned int i(0); i<_adressesTX.size();i++)
        {
            char * adrChar = new char[_adressesTX[i].size() + 1];
            std::copy(_adressesTX[i].begin(), _adressesTX[i].end(), adrChar);
            adrChar[_adressesTX[i].size()] = '\0';

            TEXTURE_STRUCT * TX = readPpm(adrChar);
            glBindTexture(GL_TEXTURE_2D,textures[i+3]);
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
    if (_modeRendu == SELECT)
    {
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_LIGHTING);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        //Placement de la caméra
        glRotatef(_angxcam, 0, 1, 0);
        glRotatef(_angycam, 1, 0, 0);
        glRotatef(_angzcam, 0, 0, 1);
        glTranslatef(_posxcam,_posycam,_poszcam);

        dessinPicking();
        etudeHit();
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_LIGHTING);
        _modeRendu = RENDER;
    }

    if (_modeRendu == RENDER)
    {
        //On enleve les couleurs ainsi que la profondeur avant de continuer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        //Placement de la caméra
        glRotatef(_angxcam, 0, 1, 0);
        glRotatef(_angycam, 1, 0, 0);
        glRotatef(_angzcam, 0, 0, 1);
        glTranslatef(_posxcam,_posycam,_poszcam);

        //Lumières
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
    }
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


void WidgetOGL::mousePressEvent(QMouseEvent* mouseEvent)
{
    if(mouseEvent->button() == Qt::LeftButton)
    {
        std::cout << "Clic souris enregistré en " << mouseEvent->x() << ", " << mouseEvent->y() << std::endl;
        _curseurX = mouseEvent->x();
        _curseurY = mouseEvent->y();
        _modeRendu = SELECT;
    }
}



/*
 * Sauvegarde et chargement
 */

/**
 * @brief WidgetOGL::sauvegardeScene
 * Pour sauvegarder la scène complète
 */
void WidgetOGL::sauvegardeScene(std::string nomFichier)
{
    bool trouve = false;
    std::cout << "***** DEBUT DE SAUVEGARDE DE SCENE *****" << std::endl;

    nomFichier = "./Sauvegardes/" + nomFichier;
    QString nomQ = QString::fromStdString(nomFichier);
    std::cout << nomFichier << std::endl;

    std::ofstream fichier(nomFichier.c_str(), std::ios::out);
    if(fichier)  // si l'ouverture a réussi
    {
        trouve = true;
        std::cout << "Fichier " << nomFichier << " effacé." << std::endl;
    }
    fichier.close();

    for (unsigned int i(0); i<_formesAAfficher.size();i++)
    {
        _formesAAfficher[i]->sauvegardeForme(nomFichier);
    }
    if (trouve == true)
        QMessageBox::information(this, "Succès", "Fichier "+nomQ+" enregistré avec succès dans Programme/Sauvegardes/.");
    else
        QMessageBox::information(this, "Erreur", "Le fichier "+nomQ+" n'a pas pu être enregistré.");

    std::cout << "***** FIN DE SAUVEGARDE DE SCENE *****" << std::endl;
}

void WidgetOGL::chargementScene(std::string nomFichier)
{
    nomFichier = "./Sauvegardes/" + nomFichier;

    _formesAAfficher.clear();   //On supprime tout ce qui existait

    int etape=0;

    bool coeffAttribut = true;  //vrai si on est sur le coeff de l'attribut, faux si on est sur l'attribut lui même
    float valeurCoeff;

    std::ifstream fichier(nomFichier.c_str(), std::ios::in);  // on ouvre le fichier en lecture
    std::string ligneEnCours;
    std::string lignePrecedente;

    if(fichier)  // si l'ouverture a réussi
    {
        int idTmp;
        std::string nomFormeTmp;
        int nbFacTmp;
        int nbSomTmp;
        int nbAttTmp;
        int nbFacMax;
        bool coeffAttribut = false;
        std::map<std::string,float> attTmp;                  //map d'attributs
        int coulRTmp;
        int coulVTmp;
        int coulBTmp;
        int posXTmp;
        int posYTmp;
        int posZTmp;
        int rotXTmp;
        int rotYTmp;
        int rotZTmp;
        int idTXTmp;
        float tailleTmp;
        sommet sommetTemporaire;
        face faceTemporaire;

        std::shared_ptr<forme> formePtr;

        std::vector<int **> vecFacesTabTmp;
        std::vector<int **> vecSomTabTmp;
        std::vector<sommet *> vecSomTmp;
        std::vector<face *> vecFacTmp;
        unsigned int indiceFormeEnCours(0);

        int iFacesCons = 0; //Indice dans le tableau de construction des faces
        int iAtt = 0;   //Indice dans le tableau des attributs
        int iFaces = 0; //Indice pour le tableau de sommets
        int iSommet = 0;    //Indice pour le tableau de faces
        int sommetsTraites = 0;
        int facesTraitees = 0;

        while(getline(fichier, ligneEnCours))  // tant que l'on peut mettre la ligne dans "contenu"
        {
            if (ligneEnCours == "////FORME////")
            {
                etape = 0;

                int ** facesTabTmp = new int*[100];  //correspond au tableau de construction des faces
                for(int i(0); i < 100; i++)
                { facesTabTmp[i] = new int[3]; }
                for (int i(0); i<100; i++)          //toutes les valeurs à 0 pour éviter d'avoir des valeurs aléatoires en fin de tableau
                {
                    for (int j(0); j<3; j++)
                        facesTabTmp[i][j] = 0;
                }

                vecFacesTabTmp.push_back(facesTabTmp);

                int ** somTabTmp = new int*[100];   //correspond au tableau de construction des sommets
                for(int i(0); i < 100; i++)
                { somTabTmp[i] = new int[3]; }

                vecSomTabTmp.push_back(somTabTmp);

                sommet * somTmp = new sommet [50];         //tableau de sommets
                vecSomTmp.push_back(somTmp);

                face * facTmp = new face [50];     //tableau de faces

                vecFacTmp.push_back(facTmp);
            }

            if (lignePrecedente == "//ID//")
                idTmp = atoi(ligneEnCours.c_str());
            if (lignePrecedente == "//NOM FORME//")
                nomFormeTmp = ligneEnCours;
            if (lignePrecedente == "//NOMBRE FACE//")
                nbFacTmp = atoi(ligneEnCours.c_str());
            if (lignePrecedente == "//NOMBRE SOMMET//")
                nbSomTmp = atoi(ligneEnCours.c_str());
            if (lignePrecedente == "//NOMBRE ATTRIBUTS//")
                nbAttTmp = atoi(ligneEnCours.c_str());
            if (lignePrecedente == "//NOMBRE SOMMETS PAR FACE MAXIMUM//")
                nbFacMax = atoi(ligneEnCours.c_str());


            /*** ETAPES ***/
            if (ligneEnCours == "//ATTRIBUTS//")
                etape = 1;
            if (ligneEnCours == "//TABLEAU CONSTRUCTION FACES//")
                etape = 2;
            if (ligneEnCours == "//VALEUR ROUGE//")
                etape = -1;
            if (ligneEnCours == "//TABLEAU FACES//")
                etape = 3;
            if (ligneEnCours == "//TABLEAU SOMMETS//")
                etape = 4;
            if (ligneEnCours == "//PARENT//")
                etape = 5;


            if (etape == 1 && ligneEnCours != "//ATTRIBUTS//") //Lecture des attributs, et on les relie à leur valeur
            {
                if (coeffAttribut)
                {
                    std::stringstream stream(ligneEnCours);
                    stream >> valeurCoeff;
                }
                else
                {
                    attTmp.insert(std::make_pair(ligneEnCours,valeurCoeff));
                    iAtt++;
                }
            }
            if (coeffAttribut)
                coeffAttribut = false;
            else
                coeffAttribut = true;

            if (lignePrecedente == "//VALEUR ROUGE//")
                coulRTmp = atoi(ligneEnCours.c_str());
            if (lignePrecedente == "//VALEUR VERT//")
                coulVTmp = atoi(ligneEnCours.c_str());
            if (lignePrecedente == "//VALEUR BLEU//")
                coulBTmp = atoi(ligneEnCours.c_str());
            if (lignePrecedente == "//VALEUR POS X//")
                posXTmp = atoi(ligneEnCours.c_str());
            if (lignePrecedente == "//VALEUR POS Y//")
                posYTmp = atoi(ligneEnCours.c_str());
            if (lignePrecedente == "//VALEUR POS Z//")
                posZTmp = atoi(ligneEnCours.c_str());
            if (lignePrecedente == "//VALEUR ROT X//")
                rotXTmp = atoi(ligneEnCours.c_str());
            if (lignePrecedente == "//VALEUR ROT Y//")
                rotYTmp = atoi(ligneEnCours.c_str());
            if (lignePrecedente == "//VALEUR ROT Z//")
                rotZTmp = atoi(ligneEnCours.c_str());
            if (lignePrecedente == "//ID TEXTURE//")
                idTXTmp = atoi(ligneEnCours.c_str());
            if (lignePrecedente == "//TAILLE//")
            {
                std::stringstream stream(ligneEnCours);
                stream >> tailleTmp;
            }

            if (etape == 2 && ligneEnCours != "//TABLEAU CONSTRUCTION FACES//") //Lecture du tableau de création de faces
            {
                int j = 0;
                std::vector<std::string> res = explode(ligneEnCours, ' ');
                while (j<nbFacMax)
                {
                    std::string chaine = res[j];
                    int val = std::stoi(chaine);

                    vecFacesTabTmp[indiceFormeEnCours][iFacesCons][j] = val;
                    j++;
                }
                iFacesCons++;
            }

            if (etape == 3 && ligneEnCours != "//TABLEAU FACES//")
            {
                if (facesTraitees < nbFacTmp)
                {
                    int j = 0;
                    std::vector<std::string> res = explode(ligneEnCours, ' ');
                    while (j<nbFacMax)
                    {
                        std::string chaine = res[j];
                        std::stringstream stream(chaine);
                        float val;
                        stream >> val;
                        if (j==0)
                            faceTemporaire.centre.x = val;
                        if (j==1)
                            faceTemporaire.centre.y = val;
                        if (j==2)
                            faceTemporaire.centre.z = val;
                        j++;
                    }
                    vecFacTmp[indiceFormeEnCours][iFaces]=faceTemporaire;
                    iFaces++;
                    facesTraitees++;
                }
            }

            if (etape == 4 && ligneEnCours != "//TABLEAU SOMMETS//")
            {
                if (sommetsTraites < nbSomTmp)
                {
                    int j = 0;
                    std::vector<std::string> res = explode(ligneEnCours, ' ');
                    while (j<nbFacMax)
                    {
                        std::string chaine = res[j];
                        std::stringstream stream(chaine);
                        float val;
                        stream >> val;
                        if (j==0)
                            sommetTemporaire.coordonnees.x = val;
                        if (j==1)
                            sommetTemporaire.coordonnees.y = val;
                        if (j==2)
                            sommetTemporaire.coordonnees.z = val;
                        j++;
                    }
                    vecSomTmp[indiceFormeEnCours][iSommet]=sommetTemporaire;
                    iSommet++;

                    sommetsTraites++;
                }
            }

            if (lignePrecedente == "//PARENT//")    //A ce stade on a toutes les informations nécessaires (A REVOIR)
            {
                //Calcul des normales
                for (int j(0);j<nbFacTmp;j++)
                {
                    calcul_normale(
                                vecSomTmp[indiceFormeEnCours][vecFacesTabTmp[indiceFormeEnCours][j][0]].coordonnees.x,
                            vecSomTmp[indiceFormeEnCours][vecFacesTabTmp[indiceFormeEnCours][j][0]].coordonnees.y,
                            vecSomTmp[indiceFormeEnCours][vecFacesTabTmp[indiceFormeEnCours][j][0]].coordonnees.z,
                            vecSomTmp[indiceFormeEnCours][vecFacesTabTmp[indiceFormeEnCours][j][1]].coordonnees.x,
                            vecSomTmp[indiceFormeEnCours][vecFacesTabTmp[indiceFormeEnCours][j][1]].coordonnees.y,
                            vecSomTmp[indiceFormeEnCours][vecFacesTabTmp[indiceFormeEnCours][j][1]].coordonnees.z,
                            vecSomTmp[indiceFormeEnCours][vecFacesTabTmp[indiceFormeEnCours][j][2]].coordonnees.x,
                            vecSomTmp[indiceFormeEnCours][vecFacesTabTmp[indiceFormeEnCours][j][2]].coordonnees.y,
                            vecSomTmp[indiceFormeEnCours][vecFacesTabTmp[indiceFormeEnCours][j][2]].coordonnees.z,
                            &(vecFacTmp[indiceFormeEnCours][j].norm));
                }

                formePtr = std::make_shared<forme>(idTmp, nomFormeTmp, nbFacTmp, nbSomTmp, nbAttTmp, nbFacMax, vecFacesTabTmp[indiceFormeEnCours],
                                                   vecSomTmp[indiceFormeEnCours], vecFacTmp[indiceFormeEnCours], attTmp, coulRTmp, coulVTmp, coulBTmp, posXTmp, posYTmp,
                                                   posZTmp, rotXTmp, rotYTmp, rotZTmp, tailleTmp, idTXTmp);

                if (ligneEnCours != "Aucun")
                {
                    emit formeChargee(formePtr,QString::fromStdString(ligneEnCours));
                }
                else
                {
                    emit formeChargee(formePtr, "Aucun");
                }

                // Remises des valeurs par défaut //
                indiceFormeEnCours++;
                formePtr.reset();
                etape = 0;
                iFacesCons = 0;
                iAtt = 0;
                iFaces = 0;
                iSommet = 0;
                coeffAttribut = false;
                attTmp.clear();
                facesTraitees = 0;
                sommetsTraites = 0;
            }
            lignePrecedente = ligneEnCours;
        }   //Fin de lecture du fichier
        fichier.close();
        //On supprime tout ce que les vecteurs stockaient
        vecFacesTabTmp.clear();
        vecFacTmp.clear();
        vecSomTabTmp.clear();
        vecSomTmp.clear();

        QString nomQ = QString::fromStdString(nomFichier);
        QMessageBox::information(this, "Succès", "Le fichier "+nomQ+" a été chargé!");
    }
    else  // Sinon
    {
        emit fichierNonTrouve(nomFichier);
        std::cout << "Impossible d'ouvrir le fichier !" << std::endl;
    }
}

/*
 *
 * *************************************** PICKING ***********************************
 *
 */

void WidgetOGL::dessinPicking()
{
    float val(0);
    int tmp;
    for (unsigned int i(0); i<_formesAAfficher.size(); i++)
    {
        _formesAAfficher[i]->afficher_forme_picking(val);
    }
}

void WidgetOGL::etudeHit()
{
    GLint viewport[4];
    unsigned char pixels[3];

    glGetIntegerv(GL_VIEWPORT,viewport);

    glReadPixels(_curseurX,viewport[3]-_curseurY,1,1,
            GL_RGB,GL_UNSIGNED_BYTE,&pixels[0]);

    std::cout << "Couleur: " << static_cast<int>(pixels[0]) << ", " << (int)(pixels[1]) << ", " << (int)(pixels[2]) << std::endl;
    bool trouve(false);
    for (unsigned int c(0); c<255; c++)
    {
        if (pixels[0] == c && pixels[1]!=0 && pixels[2]!=0)
        {
            trouve = true;
            std::cout << "Forme " << c << std::endl;
            emit formePick(c);
        }
    }
    if (trouve != true)
        std::cout << "Vous n'avez cliqué sur rien" << std::endl;

    std::cout << std::endl;
}
