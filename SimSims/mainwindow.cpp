#include "mainwindow.h"
#include <memory>
#include "forme.h"
#include "lectureDoc.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),TOUS_LES_OBJETS(),TOUTES_LES_ADRESSE_TEXTURES(), NOM_DES_FORMES(), ENSEMBLE_LUM_POS()
{
    resize(1200, 600);

    _layoutprincipal = new QGridLayout();

    _affichage = new WidgetOGL(60,this, "main");
    _affichage->setMinimumWidth(600);

    _tabs = new QTabWidget(this);


    _nbLumierePos = 0;
    _nbObjet = 0;

    /* Chargement initial des informations */
    char * fichierDonnees = "./FICHIER_DE_DONNEES";
    std::cout << "LECTURE DU NOM DES FORMES" << std::endl;
    // Obtention du vecteur avec le nom des formes (on connait donc le nombre avec sa taille)
    NOM_DES_FORMES = lireIntro(fichierDonnees);
    std::cout << "Terminé." << std::endl;
    std::cout << "LECTURE DES TEXTURESS" << std::endl;
    // Obtention du vecteur avec le nom des formes (on connait donc le nombre avec sa taille)
    TOUTES_LES_ADRESSE_TEXTURES = lireAdresseTextures(fichierDonnees);
    std::cout << "Terminé." << std::endl;
    /***************************************/

    /* -------------------- ONGLET LUMIERES -------------------- */
    _layoutLumiere = new QGridLayout();
    QWidget * _wLumiere = new QWidget(this);
    _wLumiere->setLayout(_layoutLumiere);

    /* Ambiante */
    _ambiante = new QLabel("Ambiante", this);
    _ambiante->setFixedSize(150, 25);
    _layoutLumiere->addWidget(_ambiante, 0, 0, 1, 5);

    /* Rouge */
    _red_la = new QLabel("Rouge : ", this);
    _red_min_la = new QLabel("0", this);
    _s_red_la = new QSlider(Qt::Horizontal, this);
    _s_red_la->setMinimum(0);
    _s_red_la->setMaximum(255);
    _s_red_la->setValue(204);
    _red_max_la = new QLabel("255", this);
    _l_red_la = new QLabel("valeur : ", this);
    _sp_red_la = new QSpinBox(this);
    _sp_red_la->setMaximum(255);
    _sp_red_la->setValue(204);

    _layoutLumiere->addWidget(_red_la, 1, 1, 1, 1);
    _layoutLumiere->addWidget(_red_min_la, 1, 2, 1, 1);
    _layoutLumiere->addWidget(_s_red_la, 1, 3, 1, 5);
    _layoutLumiere->addWidget(_red_max_la, 1, 9, 1, 1);
    _layoutLumiere->addWidget(_l_red_la, 1, 10, 1, 1);
    _layoutLumiere->addWidget(_sp_red_la, 1, 11, 1, 1);

    /* Vert */
    _green_la = new QLabel("Vert : ", this);
    _green_min_la = new QLabel("0", this);
    _s_green_la = new QSlider(Qt::Horizontal, this);
    _s_green_la->setMinimum(0);
    _s_green_la->setMaximum(255);
    _s_green_la->setValue(204);
    _green_max_la = new QLabel("255", this);
    _l_green_la = new QLabel("valeur : ", this);
    _sp_green_la = new QSpinBox(this);
    _sp_green_la->setMaximum(255);
    _sp_green_la->setValue(204);

    _layoutLumiere->addWidget(_green_la, 2, 1, 1, 1);
    _layoutLumiere->addWidget(_green_min_la, 2, 2, 1, 1);
    _layoutLumiere->addWidget(_s_green_la, 2, 3, 1, 5);
    _layoutLumiere->addWidget(_green_max_la, 2, 9, 1, 1);
    _layoutLumiere->addWidget(_l_green_la, 2, 10, 1, 1);
    _layoutLumiere->addWidget(_sp_green_la, 2, 11, 1, 1);

    /* Bleu */
    _blue_la = new QLabel("Bleu : ", this);
    _blue_min_la = new QLabel("0", this);
    _s_blue_la = new QSlider(Qt::Horizontal, this);
    _s_blue_la->setMinimum(0);
    _s_blue_la->setMaximum(255);
    _s_blue_la->setValue(204);
    _blue_max_la = new QLabel("255", this);
    _l_blue_la = new QLabel("valeur : ", this);
    _sp_blue_la = new QSpinBox(this);
    _sp_blue_la->setMaximum(255);
    _sp_blue_la->setValue(204);

    _layoutLumiere->addWidget(_blue_la, 3, 1, 1, 1);
    _layoutLumiere->addWidget(_blue_min_la, 3, 2, 1, 1);
    _layoutLumiere->addWidget(_s_blue_la, 3, 3, 1, 5);
    _layoutLumiere->addWidget(_blue_max_la, 3, 9, 1, 1);
    _layoutLumiere->addWidget(_l_blue_la, 3, 10, 1, 1);
    _layoutLumiere->addWidget(_sp_blue_la, 3, 11, 1, 1);


    /* Positionnelle */
    _positionnelle = new QLabel("Positionnelle", this);
    _layoutLumiere->addWidget(_positionnelle, 4, 0, 1, 2);

    _lp = new QComboBox(this);
    _layoutLumiere->addWidget(_lp, 4, 2, 1, 4);

    /* Rouge */
    _red_lp = new QLabel("Rouge : ", this);
    _red_min_lp = new QLabel("0", this);
    _s_red_lp = new QSlider(Qt::Horizontal, this);
    _s_red_lp->setMinimum(0);
    _s_red_lp->setMaximum(255);
    _red_max_lp = new QLabel("255", this);
    _l_red_lp = new QLabel("valeur : ", this);
    _sp_red_lp = new QSpinBox(this);
    _sp_red_lp->setMaximum(255);

    _layoutLumiere->addWidget(_red_lp, 5, 1, 1, 1);
    _layoutLumiere->addWidget(_red_min_lp, 5, 2, 1, 1);
    _layoutLumiere->addWidget(_s_red_lp, 5, 3, 1, 5);
    _layoutLumiere->addWidget(_red_max_lp, 5, 9, 1, 1);
    _layoutLumiere->addWidget(_l_red_lp, 5, 10, 1, 1);
    _layoutLumiere->addWidget(_sp_red_lp, 5, 11, 1, 1);

    /* Vert */
    _green_lp = new QLabel("Vert : ", this);
    _green_min_lp = new QLabel("0", this);
    _s_green_lp = new QSlider(Qt::Horizontal, this);
    _s_green_lp->setMinimum(0);
    _s_green_lp->setMaximum(255);
    _green_max_lp = new QLabel("255", this);
    _l_green_lp = new QLabel("valeur : ", this);
    _sp_green_lp = new QSpinBox(this);
    _sp_green_lp->setMaximum(255);

    _layoutLumiere->addWidget(_green_lp, 6, 1, 1, 1);
    _layoutLumiere->addWidget(_green_min_lp, 6, 2, 1, 1);
    _layoutLumiere->addWidget(_s_green_lp, 6, 3, 1, 5);
    _layoutLumiere->addWidget(_green_max_lp, 6, 9, 1, 1);
    _layoutLumiere->addWidget(_l_green_lp, 6, 10, 1, 1);
    _layoutLumiere->addWidget(_sp_green_lp, 6, 11, 1, 1);

    /* Bleu */
    _blue_lp = new QLabel("Bleu : ", this);
    _blue_min_lp = new QLabel("0", this);
    _s_blue_lp = new QSlider(Qt::Horizontal, this);
    _s_blue_lp->setMinimum(0);
    _s_blue_lp->setMaximum(255);
    _blue_max_lp = new QLabel("255", this);
    _l_blue_lp = new QLabel("valeur : ", this);
    _sp_blue_lp = new QSpinBox(this);
    _sp_blue_lp->setMaximum(255);

    _layoutLumiere->addWidget(_blue_lp, 7, 1, 1, 1);
    _layoutLumiere->addWidget(_blue_min_lp, 7, 2, 1, 1);
    _layoutLumiere->addWidget(_s_blue_lp, 7, 3, 1, 5);
    _layoutLumiere->addWidget(_blue_max_lp, 7, 9, 1, 1);
    _layoutLumiere->addWidget(_l_blue_lp, 7, 10, 1, 1);
    _layoutLumiere->addWidget(_sp_blue_lp, 7, 11, 1, 1);


    /* Position X */
    _posX_lp = new QLabel("PosX : ", this);
    _posX_min_lp = new QLabel("-10", this);
    _s_posX_lp = new QSlider(Qt::Horizontal, this);
    _s_posX_lp->setMinimum(-10);
    _s_posX_lp->setMaximum(10);
    _posX_max_lp = new QLabel("10", this);
    _l_posX_lp = new QLabel("valeur : ", this);
    _le_posX_lp = new QLineEdit("0", this);
    _le_posX_lp->setFixedSize(40, 26);
    _le_posX_lp->setReadOnly(true);

    _layoutLumiere->addWidget(_posX_lp, 8, 1, 1, 1);
    _layoutLumiere->addWidget(_posX_min_lp, 8, 2, 1, 1);
    _layoutLumiere->addWidget(_s_posX_lp, 8, 3, 1, 5);
    _layoutLumiere->addWidget(_posX_max_lp, 8, 9, 1, 1);
    _layoutLumiere->addWidget(_l_posX_lp, 8, 10, 1, 1);
    _layoutLumiere->addWidget(_le_posX_lp, 8, 11, 1, 1);

    /* Position Y */
    _posY_lp = new QLabel("PosY : ", this);
    _posY_min_lp = new QLabel("-10", this);
    _s_posY_lp = new QSlider(Qt::Horizontal, this);
    _s_posY_lp->setMinimum(-10);
    _s_posY_lp->setMaximum(10);
    _posY_max_lp = new QLabel("10", this);
    _l_posY_lp = new QLabel("valeur : ", this);
    _le_posY_lp = new QLineEdit("0", this);
    _le_posY_lp->setFixedSize(40, 26);
    _le_posY_lp->setReadOnly(true);

    _layoutLumiere->addWidget(_posY_lp, 9, 1, 1, 1);
    _layoutLumiere->addWidget(_posY_min_lp, 9, 2, 1, 1);
    _layoutLumiere->addWidget(_s_posY_lp, 9, 3, 1, 5);
    _layoutLumiere->addWidget(_posY_max_lp, 9, 9, 1, 1);
    _layoutLumiere->addWidget(_l_posY_lp, 9, 10, 1, 1);
    _layoutLumiere->addWidget(_le_posY_lp, 9, 11, 1, 1);

    /* Position Z */
    _posZ_lp = new QLabel("PosZ : ", this);
    _posZ_min_lp = new QLabel("-10", this);
    _s_posZ_lp = new QSlider(Qt::Horizontal, this);
    _s_posZ_lp->setMinimum(-10);
    _s_posZ_lp->setMaximum(10);
    _posZ_max_lp = new QLabel("10", this);
    _l_posZ_lp = new QLabel("valeur : ", this);
    _le_posZ_lp = new QLineEdit("0", this);
    _le_posZ_lp->setFixedSize(40, 26);
    _le_posZ_lp->setReadOnly(true);

    _layoutLumiere->addWidget(_posZ_lp, 10, 1, 1, 1);
    _layoutLumiere->addWidget(_posZ_min_lp, 10, 2, 1, 1);
    _layoutLumiere->addWidget(_s_posZ_lp, 10, 3, 1, 5);
    _layoutLumiere->addWidget(_posZ_max_lp, 10, 9, 1, 1);
    _layoutLumiere->addWidget(_l_posZ_lp, 10, 10, 1, 1);
    _layoutLumiere->addWidget(_le_posZ_lp, 10, 11, 1, 1);

    /* Boutons */
    _delete_lp = new QPushButton("Supp.", this);
    _delete_lp->setMaximumWidth(50);
    _delete_lp->setEnabled(false);
    _new_lp = new QPushButton("Nouv.", this);
    _new_lp->setMaximumWidth(50);

    _layoutLumiere->addWidget(_delete_lp, 11, 10, 1, 1);
    _layoutLumiere->addWidget(_new_lp, 11, 11, 1, 1);


    /* -------------------- ONGLET CAMERA -------------------- */
    _layoutCamera = new QGridLayout();
    QWidget * _wCamera = new QWidget(this);
    _wCamera->setLayout(_layoutCamera);

    /* Position */
    _positionCam = new QLabel("Position", this);
    _positionCam->setFixedSize(150, 25);
    _layoutCamera->addWidget(_positionCam, 0, 0, 1, 2);

    /* Position X */
    _posX_cam = new QLabel("PosX : ", this);
    _posX_min_cam = new QLabel("-10", this);
    _s_posX_cam = new QSlider(Qt::Horizontal, this);
    _s_posX_cam->setMinimum(-10);
    _s_posX_cam->setMaximum(10);
    _posX_max_cam = new QLabel("10", this);
    _l_posX_cam = new QLabel("valeur : ", this);
    _le_posX_cam = new QLineEdit("0", this);
    _le_posX_cam->setFixedSize(40, 26);
    _le_posX_cam->setReadOnly(true);

    _layoutCamera->addWidget(_posX_cam, 1, 1, 1, 1);
    _layoutCamera->addWidget(_posX_min_cam, 1, 2, 1, 1);
    _layoutCamera->addWidget(_s_posX_cam, 1, 3, 1, 5);
    _layoutCamera->addWidget(_posX_max_cam, 1, 9, 1, 1);
    _layoutCamera->addWidget(_l_posX_cam, 1, 10, 1, 1);
    _layoutCamera->addWidget(_le_posX_cam, 1, 11, 1, 1);

    /* Position Y */
    _posY_cam = new QLabel("PosY : ", this);
    _posY_min_cam = new QLabel("-10", this);
    _s_posY_cam = new QSlider(Qt::Horizontal, this);
    _s_posY_cam->setMinimum(-10);
    _s_posY_cam->setMaximum(10);
    _posY_max_cam = new QLabel("10", this);
    _l_posY_cam = new QLabel("valeur : ", this);
    _le_posY_cam = new QLineEdit("0", this);
    _le_posY_cam->setFixedSize(40, 26);
    _le_posY_cam->setReadOnly(true);

    _layoutCamera->addWidget(_posY_cam, 2, 1, 1, 1);
    _layoutCamera->addWidget(_posY_min_cam, 2, 2, 1, 1);
    _layoutCamera->addWidget(_s_posY_cam, 2, 3, 1, 5);
    _layoutCamera->addWidget(_posY_max_cam, 2, 9, 1, 1);
    _layoutCamera->addWidget(_l_posY_cam, 2, 10, 1, 1);
    _layoutCamera->addWidget(_le_posY_cam, 2, 11, 1, 1);

    /* Position Z */
    _posZ_cam = new QLabel("PosZ : ", this);
    _posZ_min_cam = new QLabel("-10", this);
    _s_posZ_cam = new QSlider(Qt::Horizontal, this);
    _s_posZ_cam->setMinimum(-10);
    _s_posZ_cam->setMaximum(10);
    _posZ_max_cam = new QLabel("10", this);
    _l_posZ_cam = new QLabel("valeur : ", this);
    _le_posZ_cam = new QLineEdit("0", this);
    _le_posZ_cam->setFixedSize(40, 26);
    _le_posZ_cam->setReadOnly(true);

    _layoutCamera->addWidget(_posZ_cam, 3, 1, 1, 1);
    _layoutCamera->addWidget(_posZ_min_cam, 3, 2, 1, 1);
    _layoutCamera->addWidget(_s_posZ_cam, 3, 3, 1, 5);
    _layoutCamera->addWidget(_posZ_max_cam, 3, 9, 1, 1);
    _layoutCamera->addWidget(_l_posZ_cam, 3, 10, 1, 1);
    _layoutCamera->addWidget(_le_posZ_cam, 3, 11, 1, 1);

    /* Angle */
    _angleCam = new QLabel("Angle", this);
    _angleCam->setFixedSize(150, 25);
    _layoutCamera->addWidget(_angleCam, 4, 0, 1, 2);

    /* Angle X */
    _angX_cam = new QLabel("AngX : ", this);
    _angX_min_cam = new QLabel("0", this);
    _s_angX_cam = new QSlider(Qt::Horizontal, this);
    _s_angX_cam->setMinimum(0);
    _s_angX_cam->setMaximum(360);
    _angX_max_cam = new QLabel("360", this);
    _l_angX_cam = new QLabel("valeur : ", this);
    _le_angX_cam = new QLineEdit("0", this);
    _le_angX_cam->setFixedSize(40, 26);
    _le_angX_cam->setReadOnly(true);
    _ldeg_angX_cam = new QLabel("°", this);

    _layoutCamera->addWidget(_angX_cam, 5, 1, 1, 1);
    _layoutCamera->addWidget(_angX_min_cam, 5, 2, 1, 1);
    _layoutCamera->addWidget(_s_angX_cam, 5, 3, 1, 5);
    _layoutCamera->addWidget(_angX_max_cam, 5, 9, 1, 1);
    _layoutCamera->addWidget(_l_angX_cam, 5, 10, 1, 1);
    _layoutCamera->addWidget(_le_angX_cam, 5, 11, 1, 1);
    _layoutCamera->addWidget(_ldeg_angX_cam, 5, 12, 1, 1);

    /* Angle Y */
    _angY_cam = new QLabel("AngY : ", this);
    _angY_min_cam = new QLabel("0", this);
    _s_angY_cam = new QSlider(Qt::Horizontal, this);
    _s_angY_cam->setMinimum(0);
    _s_angY_cam->setMaximum(360);
    _angY_max_cam = new QLabel("360", this);
    _l_angY_cam = new QLabel("valeur : ", this);
    _le_angY_cam = new QLineEdit("0", this);
    _le_angY_cam->setFixedSize(40, 26);
    _le_angY_cam->setReadOnly(true);
    _ldeg_angY_cam = new QLabel("°", this);

    _layoutCamera->addWidget(_angY_cam, 6, 1, 1, 1);
    _layoutCamera->addWidget(_angY_min_cam, 6, 2, 1, 1);
    _layoutCamera->addWidget(_s_angY_cam, 6, 3, 1, 5);
    _layoutCamera->addWidget(_angY_max_cam, 6, 9, 1, 1);
    _layoutCamera->addWidget(_l_angY_cam, 6, 10, 1, 1);
    _layoutCamera->addWidget(_le_angY_cam, 6, 11, 1, 1);
    _layoutCamera->addWidget(_ldeg_angY_cam, 6, 12, 1, 1);

    /* Angle Z */
    _angZ_cam = new QLabel("AngZ : ", this);
    _angZ_min_cam = new QLabel("0", this);
    _s_angZ_cam = new QSlider(Qt::Horizontal, this);
    _s_angZ_cam->setMinimum(0);
    _s_angZ_cam->setMaximum(360);
    _angZ_max_cam = new QLabel("360", this);
    _l_angZ_cam = new QLabel("valeur : ", this);
    _le_angZ_cam = new QLineEdit("0", this);
    _le_angZ_cam->setFixedSize(40, 26);
    _le_angZ_cam->setReadOnly(true);
    _ldeg_angZ_cam = new QLabel("°", this);

    _layoutCamera->addWidget(_angZ_cam, 7, 1, 1, 1);
    _layoutCamera->addWidget(_angZ_min_cam, 7, 2, 1, 1);
    _layoutCamera->addWidget(_s_angZ_cam, 7, 3, 1, 5);
    _layoutCamera->addWidget(_angZ_max_cam, 7, 9, 1, 1);
    _layoutCamera->addWidget(_l_angZ_cam, 7, 10, 1, 1);
    _layoutCamera->addWidget(_le_angZ_cam, 7, 11, 1, 1);
    _layoutCamera->addWidget(_ldeg_angZ_cam, 7, 12, 1, 1);




    /* -------------------- ONGLET OBJETS -------------------- */
    _layoutObjet = new QGridLayout();
    QWidget * _wObjet = new QWidget(this);
    _wObjet->setLayout(_layoutObjet);

    _obj = new QComboBox(this);
    _layoutObjet->addWidget(_obj, 0, 0, 1, 4);

    /* Couleur */
    _couleurObj = new QLabel("Couleur", this);
    _couleurObj->setFixedSize(150, 25);
    _layoutObjet->addWidget(_couleurObj, 1, 0, 1, 5);

    /* Rouge */
    _red_obj = new QLabel("Rouge : ", this);
    _red_min_obj = new QLabel("0", this);
    _s_red_obj = new QSlider(Qt::Horizontal, this);
    _s_red_obj->setMinimum(0);
    _s_red_obj->setMaximum(255);
    _red_max_obj = new QLabel("255", this);
    _l_red_obj = new QLabel("valeur : ", this);
    _sp_red_obj = new QSpinBox(this);
    _sp_red_obj->setMaximum(255);

    _layoutObjet->addWidget(_red_obj, 2, 1, 1, 1);
    _layoutObjet->addWidget(_red_min_obj, 2, 2, 1, 1);
    _layoutObjet->addWidget(_s_red_obj, 2, 3, 1, 5);
    _layoutObjet->addWidget(_red_max_obj, 2, 9, 1, 1);
    _layoutObjet->addWidget(_l_red_obj, 2, 10, 1, 1);
    _layoutObjet->addWidget(_sp_red_obj, 2, 11, 1, 1);

    /* Vert */
    _green_obj = new QLabel("Vert : ", this);
    _green_min_obj = new QLabel("0", this);
    _s_green_obj = new QSlider(Qt::Horizontal, this);
    _s_green_obj->setMinimum(0);
    _s_green_obj->setMaximum(255);
    _green_max_obj = new QLabel("255", this);
    _l_green_obj = new QLabel("valeur : ", this);
    _sp_green_obj = new QSpinBox(this);
    _sp_green_obj->setMaximum(255);

    _layoutObjet->addWidget(_green_obj, 3, 1, 1, 1);
    _layoutObjet->addWidget(_green_min_obj, 3, 2, 1, 1);
    _layoutObjet->addWidget(_s_green_obj, 3, 3, 1, 5);
    _layoutObjet->addWidget(_green_max_obj, 3, 9, 1, 1);
    _layoutObjet->addWidget(_l_green_obj, 3, 10, 1, 1);
    _layoutObjet->addWidget(_sp_green_obj, 3, 11, 1, 1);

    /* Bleu */
    _blue_obj = new QLabel("Bleu : ", this);
    _blue_min_obj = new QLabel("0", this);
    _s_blue_obj = new QSlider(Qt::Horizontal, this);
    _s_blue_obj->setMinimum(0);
    _s_blue_obj->setMaximum(255);
    _blue_max_obj = new QLabel("255", this);
    _l_blue_obj = new QLabel("valeur : ", this);
    _sp_blue_obj = new QSpinBox(this);
    _sp_blue_obj->setMaximum(255);

    _layoutObjet->addWidget(_blue_obj, 4, 1, 1, 1);
    _layoutObjet->addWidget(_blue_min_obj, 4, 2, 1, 1);
    _layoutObjet->addWidget(_s_blue_obj, 4, 3, 1, 5);
    _layoutObjet->addWidget(_blue_max_obj, 4, 9, 1, 1);
    _layoutObjet->addWidget(_l_blue_obj, 4, 10, 1, 1);
    _layoutObjet->addWidget(_sp_blue_obj, 4, 11, 1, 1);

    /* Position */
    _positionObj = new QLabel("Position", this);
    _positionObj->setFixedSize(150, 25);
    _layoutObjet->addWidget(_positionObj, 5, 0, 1, 2);

    /* Position X */
    _posX_obj = new QLabel("PosX : ", this);
    _posX_min_obj = new QLabel("-10", this);
    _s_posX_obj = new QSlider(Qt::Horizontal, this);
    _s_posX_obj->setMinimum(-10);
    _s_posX_obj->setMaximum(10);
    _posX_max_obj = new QLabel("10", this);
    _l_posX_obj = new QLabel("valeur : ", this);
    _le_posX_obj = new QLineEdit("0", this);
    _le_posX_obj->setFixedSize(40, 26);
    _le_posX_obj->setReadOnly(true);

    _layoutObjet->addWidget(_posX_obj, 6, 1, 1, 1);
    _layoutObjet->addWidget(_posX_min_obj, 6, 2, 1, 1);
    _layoutObjet->addWidget(_s_posX_obj, 6, 3, 1, 5);
    _layoutObjet->addWidget(_posX_max_obj, 6, 9, 1, 1);
    _layoutObjet->addWidget(_l_posX_obj, 6, 10, 1, 1);
    _layoutObjet->addWidget(_le_posX_obj, 6, 11, 1, 1);

    /* Position Y */
    _posY_obj = new QLabel("PosY : ", this);
    _posY_min_obj = new QLabel("-10", this);
    _s_posY_obj = new QSlider(Qt::Horizontal, this);
    _s_posY_obj->setMinimum(-10);
    _s_posY_obj->setMaximum(10);
    _posY_max_obj = new QLabel("10", this);
    _l_posY_obj = new QLabel("valeur : ", this);
    _le_posY_obj = new QLineEdit("0", this);
    _le_posY_obj->setFixedSize(40, 26);
    _le_posY_obj->setReadOnly(true);

    _layoutObjet->addWidget(_posY_obj, 7, 1, 1, 1);
    _layoutObjet->addWidget(_posY_min_obj, 7, 2, 1, 1);
    _layoutObjet->addWidget(_s_posY_obj, 7, 3, 1, 5);
    _layoutObjet->addWidget(_posY_max_obj, 7, 9, 1, 1);
    _layoutObjet->addWidget(_l_posY_obj, 7, 10, 1, 1);
    _layoutObjet->addWidget(_le_posY_obj, 7, 11, 1, 1);

    /* Position Z */
    _posZ_obj = new QLabel("PosZ : ", this);
    _posZ_min_obj = new QLabel("-10", this);
    _s_posZ_obj = new QSlider(Qt::Horizontal, this);
    _s_posZ_obj->setMinimum(-10);
    _s_posZ_obj->setMaximum(10);
    _posZ_max_obj = new QLabel("10", this);
    _l_posZ_obj = new QLabel("valeur : ", this);
    _le_posZ_obj = new QLineEdit("0", this);
    _le_posZ_obj->setFixedSize(40, 26);
    _le_posZ_obj->setReadOnly(true);

    _layoutObjet->addWidget(_posZ_obj, 8, 1, 1, 1);
    _layoutObjet->addWidget(_posZ_min_obj, 8, 2, 1, 1);
    _layoutObjet->addWidget(_s_posZ_obj, 8, 3, 1, 5);
    _layoutObjet->addWidget(_posZ_max_obj, 8, 9, 1, 1);
    _layoutObjet->addWidget(_l_posZ_obj, 8, 10, 1, 1);
    _layoutObjet->addWidget(_le_posZ_obj, 8, 11, 1, 1);


    /* Angle */
    _angleObj = new QLabel("Angle", this);
    _angleObj->setFixedSize(150, 25);
    _layoutObjet->addWidget(_angleObj, 9, 0, 1, 2);

    /* Angle X */
    _angX_obj = new QLabel("AngX : ", this);
    _angX_min_obj = new QLabel("0", this);
    _s_angX_obj = new QSlider(Qt::Horizontal, this);
    _s_angX_obj->setMinimum(0);
    _s_angX_obj->setMaximum(360);
    _angX_max_obj = new QLabel("360", this);
    _l_angX_obj = new QLabel("valeur : ", this);
    _le_angX_obj = new QLineEdit("0", this);
    _le_angX_obj->setFixedSize(40, 26);
    _le_angX_obj->setReadOnly(true);
    _ldeg_angX_obj = new QLabel("°", this);

    _layoutObjet->addWidget(_angX_obj, 10, 1, 1, 1);
    _layoutObjet->addWidget(_angX_min_obj, 10, 2, 1, 1);
    _layoutObjet->addWidget(_s_angX_obj, 10, 3, 1, 5);
    _layoutObjet->addWidget(_angX_max_obj, 10, 9, 1, 1);
    _layoutObjet->addWidget(_l_angX_obj, 10, 10, 1, 1);
    _layoutObjet->addWidget(_le_angX_obj, 10, 11, 1, 1);
    _layoutObjet->addWidget(_ldeg_angX_obj, 10, 12, 1, 1);

    /* Angle Y */
    _angY_obj = new QLabel("AngY : ", this);
    _angY_min_obj = new QLabel("0", this);
    _s_angY_obj = new QSlider(Qt::Horizontal, this);
    _s_angY_obj->setMinimum(0);
    _s_angY_obj->setMaximum(360);
    _angY_max_obj = new QLabel("360", this);
    _l_angY_obj = new QLabel("valeur : ", this);
    _le_angY_obj = new QLineEdit("0", this);
    _le_angY_obj->setFixedSize(40, 26);
    _le_angY_obj->setReadOnly(true);
    _ldeg_angY_obj = new QLabel("°", this);

    _layoutObjet->addWidget(_angY_obj, 11, 1, 1, 1);
    _layoutObjet->addWidget(_angY_min_obj, 11, 2, 1, 1);
    _layoutObjet->addWidget(_s_angY_obj, 11, 3, 1, 5);
    _layoutObjet->addWidget(_angY_max_obj, 11, 9, 1, 1);
    _layoutObjet->addWidget(_l_angY_obj, 11, 10, 1, 1);
    _layoutObjet->addWidget(_le_angY_obj, 11, 11, 1, 1);
    _layoutObjet->addWidget(_ldeg_angY_obj, 11, 12, 1, 1);

    /* Angle Z */
    _angZ_obj = new QLabel("AngZ : ", this);
    _angZ_min_obj = new QLabel("0", this);
    _s_angZ_obj = new QSlider(Qt::Horizontal, this);
    _s_angZ_obj->setMinimum(0);
    _s_angZ_obj->setMaximum(360);
    _angZ_max_obj = new QLabel("360", this);
    _l_angZ_obj = new QLabel("valeur : ", this);
    _le_angZ_obj = new QLineEdit("0", this);
    _le_angZ_obj->setFixedSize(40, 26);
    _le_angZ_obj->setReadOnly(true);
    _ldeg_angZ_obj = new QLabel("°", this);

    _layoutObjet->addWidget(_angZ_obj, 12, 1, 1, 1);
    _layoutObjet->addWidget(_angZ_min_obj, 12, 2, 1, 1);
    _layoutObjet->addWidget(_s_angZ_obj, 12, 3, 1, 5);
    _layoutObjet->addWidget(_angZ_max_obj, 12, 9, 1, 1);
    _layoutObjet->addWidget(_l_angZ_obj, 12, 10, 1, 1);
    _layoutObjet->addWidget(_le_angZ_obj, 12, 11, 1, 1);
    _layoutObjet->addWidget(_ldeg_angZ_obj, 12, 12, 1, 1);

    /* Taille */
    _tailleObj = new QLabel("Taille", this);
    _tailleObj->setFixedSize(150, 25);
    _layoutObjet->addWidget(_tailleObj, 13, 0, 1, 2);

    /* Scale */
    _scale_obj = new QLabel("Scale : ", this);
    _le_scale_obj = new QLineEdit("1", this);
    _le_scale_obj->setFixedSize(80, 26);

    _layoutObjet->addWidget(_scale_obj, 14, 1, 1, 1);
    _layoutObjet->addWidget(_le_scale_obj, 14, 5, 1, 1);

    /* Boutons */
    _delete_obj = new QPushButton("Supp.", this);
    _delete_obj->setMaximumWidth(50);
    _delete_obj->setEnabled(false);
    _new_obj = new QPushButton("Nouv.", this);
    _new_obj->setMaximumWidth(50);

    _layoutObjet->addWidget(_delete_obj, 15, 11, 1, 1);
    _layoutObjet->addWidget(_new_obj, 15, 12, 1, 1);



    /* -------------------- FENETRE -------------------- */
    _tabs->setFixedWidth(500);
    _tabs->addTab(_wLumiere, "Lumières");
    _tabs->addTab(_wCamera, "Caméra");
    _tabs->addTab(_wObjet, "Objets");

    _layoutprincipal->addWidget(_tabs, 0, 0, 1, 1);
    _layoutprincipal->addWidget(_affichage, 0, 1, 1, 1);

    _window = new QWidget();
    _window->setLayout(_layoutprincipal);
    setCentralWidget(_window);




    /* -------------------- CONNEXIONS -------------------- */
    /* De QSlider à QSpinBox */
    QObject::connect(_s_red_la, &QSlider::valueChanged, _sp_red_la, &QSpinBox::setValue);
    QObject::connect(_s_green_la, &QSlider::valueChanged, _sp_green_la, &QSpinBox::setValue);
    QObject::connect(_s_blue_la, &QSlider::valueChanged, _sp_blue_la, &QSpinBox::setValue);
    QObject::connect(_s_red_lp, &QSlider::valueChanged, _sp_red_lp, &QSpinBox::setValue);
    QObject::connect(_s_green_lp, &QSlider::valueChanged, _sp_green_lp, &QSpinBox::setValue);
    QObject::connect(_s_blue_lp, &QSlider::valueChanged, _sp_blue_lp, &QSpinBox::setValue);
    QObject::connect(_s_red_obj, &QSlider::valueChanged, _sp_red_obj, &QSpinBox::setValue);
    QObject::connect(_s_green_obj, &QSlider::valueChanged, _sp_green_obj, &QSpinBox::setValue);
    QObject::connect(_s_blue_obj, &QSlider::valueChanged, _sp_blue_obj, &QSpinBox::setValue);

    /* De QSpinBox à QSlider */
    QObject::connect(_sp_red_la, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), _s_red_la, &QSlider::setValue);
    QObject::connect(_sp_green_la, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), _s_green_la, &QSlider::setValue);
    QObject::connect(_sp_blue_la, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), _s_blue_la, &QSlider::setValue);
    QObject::connect(_sp_red_lp, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), _s_red_lp, &QSlider::setValue);
    QObject::connect(_sp_green_lp, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), _s_green_lp, &QSlider::setValue);
    QObject::connect(_sp_blue_lp, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), _s_blue_lp, &QSlider::setValue);
    QObject::connect(_sp_red_obj, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), _s_red_obj, &QSlider::setValue);
    QObject::connect(_sp_green_obj, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), _s_green_obj, &QSlider::setValue);
    QObject::connect(_sp_blue_obj, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), _s_blue_obj, &QSlider::setValue);

    /* De QSlider à QLineEdit */
    QObject::connect(_s_posX_lp, &QSlider::valueChanged, this, &MainWindow::SliderALineEdit);
    QObject::connect(_s_posY_lp, &QSlider::valueChanged, this, &MainWindow::SliderALineEdit);
    QObject::connect(_s_posZ_lp, &QSlider::valueChanged, this, &MainWindow::SliderALineEdit);
    QObject::connect(_s_posX_cam, &QSlider::valueChanged, this, &MainWindow::SliderALineEdit);
    QObject::connect(_s_posY_cam, &QSlider::valueChanged, this, &MainWindow::SliderALineEdit);
    QObject::connect(_s_posZ_cam, &QSlider::valueChanged, this, &MainWindow::SliderALineEdit);
    QObject::connect(_s_angX_cam, &QSlider::valueChanged, this, &MainWindow::SliderALineEdit);
    QObject::connect(_s_angY_cam, &QSlider::valueChanged, this, &MainWindow::SliderALineEdit);
    QObject::connect(_s_angZ_cam, &QSlider::valueChanged, this, &MainWindow::SliderALineEdit);
    QObject::connect(_s_posX_obj, &QSlider::valueChanged, this, &MainWindow::SliderALineEdit);
    QObject::connect(_s_posY_obj, &QSlider::valueChanged, this, &MainWindow::SliderALineEdit);
    QObject::connect(_s_posZ_obj, &QSlider::valueChanged, this, &MainWindow::SliderALineEdit);
    QObject::connect(_s_angX_obj, &QSlider::valueChanged, this, &MainWindow::SliderALineEdit);
    QObject::connect(_s_angY_obj, &QSlider::valueChanged, this, &MainWindow::SliderALineEdit);
    QObject::connect(_s_angZ_obj, &QSlider::valueChanged, this, &MainWindow::SliderALineEdit);

    /* Boutons */
    QObject::connect(_new_lp, &QPushButton::clicked, this, &MainWindow::PopUpLum);
    QObject::connect(_new_obj, &QPushButton::clicked, this, &MainWindow::PopUpObj);
    QObject::connect(_delete_lp, &QPushButton::clicked, this, &MainWindow::OnClicDeleteLum);
    QObject::connect(_delete_obj, &QPushButton::clicked, this, &MainWindow::OnClicDeleteObj);


    /* Connexion mainwindow vers openGL */
    // Lumière ambiante
    QObject::connect(_s_red_la, &QSlider::valueChanged, _affichage, &WidgetOGL::setAmbianteR);
    QObject::connect(_s_green_la, &QSlider::valueChanged, _affichage, &WidgetOGL::setAmbianteV);
    QObject::connect(_s_blue_la, &QSlider::valueChanged, _affichage, &WidgetOGL::setAmbianteB);

    // Position caméra
    QObject::connect(_s_posX_cam, &QSlider::valueChanged, _affichage, &WidgetOGL::setPosXCam);
    QObject::connect(_s_posY_cam, &QSlider::valueChanged, _affichage, &WidgetOGL::setPosYCam);
    QObject::connect(_s_posZ_cam, &QSlider::valueChanged, _affichage, &WidgetOGL::setPosZCam);

    // Angle caméra
    QObject::connect(_s_angX_cam, &QSlider::valueChanged, _affichage, &WidgetOGL::setAngXCam);
    QObject::connect(_s_angY_cam, &QSlider::valueChanged, _affichage, &WidgetOGL::setAngYCam);
    QObject::connect(_s_angZ_cam, &QSlider::valueChanged, _affichage, &WidgetOGL::setAngZCam);

}

MainWindow::~MainWindow()
{}

/**
 * @brief MainWindow::SliderALineEdit
 * @param i
 * Met le LineEdit à la valeur indiquée par le Slider
 */
void MainWindow::SliderALineEdit(int i)
{
    QString texte = QString::number(i);
    if (sender()==_s_posX_lp)
        _le_posX_lp->setText(texte);
    if (sender()==_s_posY_lp)
        _le_posY_lp->setText(texte);
    if (sender()==_s_posZ_lp)
        _le_posZ_lp->setText(texte);
    if (sender()==_s_posX_cam)
        _le_posX_cam->setText(texte);
    if (sender()==_s_posY_cam)
        _le_posY_cam->setText(texte);
    if (sender()==_s_posZ_cam)
        _le_posZ_cam->setText(texte);
    if (sender()==_s_angX_cam)
        _le_angX_cam->setText(texte);
    if (sender()==_s_angY_cam)
        _le_angY_cam->setText(texte);
    if (sender()==_s_angZ_cam)
        _le_angZ_cam->setText(texte);
    if (sender()==_s_posX_obj)
        _le_posX_obj->setText(texte);
    if (sender()==_s_posY_obj)
        _le_posY_obj->setText(texte);
    if (sender()==_s_posZ_obj)
        _le_posZ_obj->setText(texte);
    if (sender()==_s_angX_obj)
        _le_angX_obj->setText(texte);
    if (sender()==_s_angY_obj)
        _le_angY_obj->setText(texte);
    if (sender()==_s_angZ_obj)
        _le_angZ_obj->setText(texte);
}

/**
 * @brief MainWindow::PopUpLum
 * Fait apparaître la fenêtre de création de lumières positionnelles
 */
void MainWindow::PopUpLum()
{
    PopUpLumiere * ppl = new PopUpLumiere;

    /* On empêche de toucher à la fenêtre parent pendant que la fenêtre enfant est ouverte */
    ppl->setWindowModality(Qt::ApplicationModal);
    ppl->show();

    QObject::connect(ppl->_create_lp, &QPushButton::clicked, this, &MainWindow::IncNbLum);

    /* Reception de la lumière émise par le pop up */
    QObject::connect(ppl, &PopUpLumiere::lumiereCreee, this, &MainWindow::receptionLumiere);
}

/**
 * @brief MainWindow::PopUpObj
 * Fait apparaître la fenêtre de création d'objets
 */
void MainWindow::PopUpObj()
{
    PopUpObjet * ppo = new PopUpObjet(NOM_DES_FORMES);

    /* On empêche de toucher à la fenêtre parent pendant que la fenêtre enfant est ouverte */
    ppo->setWindowModality(Qt::ApplicationModal);
    ppo->show();

    QObject::connect(ppo->_create_obj, &QPushButton::clicked, this, &MainWindow::IncNbObj);
    QObject::connect(ppo, &PopUpObjet::creationObjet, this, &MainWindow::receptionObjet);
}

/**
 * @brief MainWindow::IncNbLum
 * On vérifie le nombre de lumières positionnelles pour griser ou non les boutons de création/suppression
 */
void MainWindow::IncNbLum()
{
    _nbLumierePos++;

    if (_nbLumierePos == 0)
        _delete_lp->setEnabled(false);
    else
        _delete_lp->setEnabled(true);

    if (_nbLumierePos >= 7)
        _new_lp->setEnabled(false);
    else
        _new_lp->setEnabled(true);
}

/**
 * @brief MainWindow::IncNbObj
 * On vérifie le nombre d'objets pour griser ou non les boutons de création/suppression
 */
void MainWindow::IncNbObj()
{
    _nbObjet++;

    if (_nbObjet == 0)
        _delete_obj->setEnabled(false);
    else
        _delete_obj->setEnabled(true);

    if (_nbObjet >= 100)
        _new_obj->setEnabled(false);
    else
        _new_obj->setEnabled(true);
}

/**
 * @brief MainWindow::OnClicDeleteLum
 * On vérifie le nombre de lumières positionnelles pour griser ou non les boutons de création/suppression
 * et supprimer la lumière positionnelle choisie
 */
void MainWindow::OnClicDeleteLum()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cancel", "Voulez-vous supprimer cette lumière positionnelle ?", (QMessageBox::No | QMessageBox::Yes));
    if (reply == QMessageBox::Yes)
    {
        /* A compléter avec la suppression de la lumière*/
        _nbLumierePos--;

        if (_nbLumierePos == 0)
            _delete_lp->setEnabled(false);
        else
            _delete_lp->setEnabled(true);

        if (_nbLumierePos >= 7)
            _new_lp->setEnabled(false);
        else
            _new_lp->setEnabled(true);
    }
}

/**
 * @brief MainWindow::OnClicDeleteObj
 * On vérifie le nombre d'objets pour griser ou non les boutons de création/suppression et supprimer l'objet choisi
 */
void MainWindow::OnClicDeleteObj()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cancel", "Voulez-vous supprimer cet objet ?", (QMessageBox::No | QMessageBox::Yes));
    if (reply == QMessageBox::Yes)
    {
        /* A compléter avec la suppression de l'objet*/
        _nbObjet--;

        if (_nbObjet == 0)
            _delete_obj->setEnabled(false);
        else
            _delete_obj->setEnabled(true);

        if (_nbObjet >= 100)
            _new_obj->setEnabled(false);
        else
            _new_obj->setEnabled(true);
    }
}

/**
 * @brief MainWindow::receptionLumiere
 * @param lp
 * Ajoute la lumière positionnelle créée dans la popup dans le mainwindow
 */
void MainWindow::receptionLumiere(LumierePos lp)
{
    _lp->addItem(QString::fromStdString(lp.getNom()));
    ENSEMBLE_LUM_POS.push_back(lp);

    if (_nbLumierePos == 0)
    {
        _s_posX_lp->setValue(lp.getPosX());
        _s_posY_lp->setValue(lp.getPosY());
        _s_posZ_lp->setValue(lp.getPosZ());
    }

    _nbLumierePos++;
}


void MainWindow::receptionObjet(std::string nom, std::shared_ptr<forme> ptr)
{
    Objet obj(nom,ptr);
    TOUS_LES_OBJETS.push_back(obj);

    std::cout << "Objets actuels:" << std::endl;
    for (unsigned int i(0); i<TOUS_LES_OBJETS.size();i++)
        std::cout << TOUS_LES_OBJETS[i].getNom() << " | ";
    std::cout << std::endl;
    std::cout << "J'ai reçu l'objet" << std::endl;
    //_affichage->ajouterForme(obj.getForme());
    std::cout << "J'ai envoyé la forme" << std::endl;
}
