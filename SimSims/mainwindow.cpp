#include "mainwindow.h"
#include <memory>
#include "forme.h"
#include "lectureDoc.h"
#include "iostream"
#include <sstream>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),TOUS_LES_OBJETS(),TOUTES_LES_ADRESSE_TEXTURES(), NOM_DES_FORMES(), ENSEMBLE_LUM_POS()
{
    /* Chargement initial des informations */
    char * fichierDonnees = "./FICHIER_DE_DONNEES";
    std::cout << "LECTURE DU NOM DES FORMES" << std::endl;
    // Obtention du vecteur avec le nom des formes (on connait donc le nombre avec sa taille)
    NOM_DES_FORMES = lireIntro(fichierDonnees);
    std::cout << "Terminé." << std::endl;
    std::cout << "LECTURE DES TEXTURES" << std::endl;
    // Obtention du vecteur avec le nom des formes (on connait donc le nombre avec sa taille)
    TOUTES_LES_ADRESSE_TEXTURES = lireAdresseTextures(fichierDonnees);
    std::cout << "Terminé." << std::endl;
    /***************************************/

    QMessageBox::StandardButton info;
    info = QMessageBox::information(this, "Information", "Veuillez déplacer le contenu du dossier \"Fichiers\" dans le dossier de compilation.");

    resize(1200, 600);

    _layoutprincipal = new QGridLayout();

    _affichage = new WidgetOGL(60,this, "main", ENSEMBLE_LUM_POS, TOUTES_LES_ADRESSE_TEXTURES);
    _affichage->setMinimumWidth(600);

    _tabs = new QTabWidget(this);


    _nbLumierePos = 0;
    _nbObjet = 0;

    /* -------------------- ONGLET OBJETS -------------------- */
    _layoutObjet = new QGridLayout();
    QWidget * _wObjet = new QWidget(this);
    _wObjet->setLayout(_layoutObjet);

    _obj = new QComboBox(this);
    _layoutObjet->addWidget(_obj, 0, 0, 1, 4);

    /* Parent */
    _choixParent = new QLabel("Base", this);
    _parent = new QComboBox(this);
    _parent->addItem("Aucun");
    _parent->setEnabled(true);
    _layoutObjet->addWidget(_choixParent, 1, 0, 1, 1);
    _layoutObjet->addWidget(_parent, 1, 2, 1, 4);

    /* Couleur */
    _couleurObj = new QLabel("Couleur", this);
    _couleurObj->setFixedSize(150, 25);
    _layoutObjet->addWidget(_couleurObj, 2, 0, 1, 5);

    /* Rouge */
    _red_obj = new QLabel("Rouge : ", this);
    _red_min_obj = new QLabel("0", this);
    _s_red_obj = new QSlider(Qt::Horizontal, this);
    _s_red_obj->setMinimum(0);
    _s_red_obj->setMaximum(255);
    _s_red_obj->setValue(204);
    _red_max_obj = new QLabel("255", this);
    _l_red_obj = new QLabel("valeur : ", this);
    _sp_red_obj = new QSpinBox(this);
    _sp_red_obj->setMaximum(255);

    _layoutObjet->addWidget(_red_obj, 3, 1, 1, 1);
    _layoutObjet->addWidget(_red_min_obj, 3, 2, 1, 1);
    _layoutObjet->addWidget(_s_red_obj, 3, 3, 1, 5);
    _layoutObjet->addWidget(_red_max_obj, 3, 9, 1, 1);
    _layoutObjet->addWidget(_l_red_obj, 3, 10, 1, 1);
    _layoutObjet->addWidget(_sp_red_obj, 3, 11, 1, 1);

    /* Vert */
    _green_obj = new QLabel("Vert : ", this);
    _green_min_obj = new QLabel("0", this);
    _s_green_obj = new QSlider(Qt::Horizontal, this);
    _s_green_obj->setMinimum(0);
    _s_green_obj->setMaximum(255);
    _s_green_obj->setValue(204);
    _green_max_obj = new QLabel("255", this);
    _l_green_obj = new QLabel("valeur : ", this);
    _sp_green_obj = new QSpinBox(this);
    _sp_green_obj->setMaximum(255);

    _layoutObjet->addWidget(_green_obj, 4, 1, 1, 1);
    _layoutObjet->addWidget(_green_min_obj, 4, 2, 1, 1);
    _layoutObjet->addWidget(_s_green_obj, 4, 3, 1, 5);
    _layoutObjet->addWidget(_green_max_obj, 4, 9, 1, 1);
    _layoutObjet->addWidget(_l_green_obj, 4, 10, 1, 1);
    _layoutObjet->addWidget(_sp_green_obj, 4, 11, 1, 1);

    /* Bleu */
    _blue_obj = new QLabel("Bleu : ", this);
    _blue_min_obj = new QLabel("0", this);
    _s_blue_obj = new QSlider(Qt::Horizontal, this);
    _s_blue_obj->setMinimum(0);
    _s_blue_obj->setMaximum(255);
    _s_blue_obj->setValue(204);
    _blue_max_obj = new QLabel("255", this);
    _l_blue_obj = new QLabel("valeur : ", this);
    _sp_blue_obj = new QSpinBox(this);
    _sp_blue_obj->setMaximum(255);

    _layoutObjet->addWidget(_blue_obj, 5, 1, 1, 1);
    _layoutObjet->addWidget(_blue_min_obj, 5, 2, 1, 1);
    _layoutObjet->addWidget(_s_blue_obj, 5, 3, 1, 5);
    _layoutObjet->addWidget(_blue_max_obj, 5, 9, 1, 1);
    _layoutObjet->addWidget(_l_blue_obj, 5, 10, 1, 1);
    _layoutObjet->addWidget(_sp_blue_obj, 5, 11, 1, 1);

    /* Position */
    _positionObj = new QLabel("Position", this);
    _positionObj->setFixedSize(150, 25);
    _layoutObjet->addWidget(_positionObj, 6, 0, 1, 2);

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

    _layoutObjet->addWidget(_posX_obj, 7, 1, 1, 1);
    _layoutObjet->addWidget(_posX_min_obj, 7, 2, 1, 1);
    _layoutObjet->addWidget(_s_posX_obj, 7, 3, 1, 5);
    _layoutObjet->addWidget(_posX_max_obj, 7, 9, 1, 1);
    _layoutObjet->addWidget(_l_posX_obj, 7, 10, 1, 1);
    _layoutObjet->addWidget(_le_posX_obj, 7, 11, 1, 1);

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

    _layoutObjet->addWidget(_posY_obj, 8, 1, 1, 1);
    _layoutObjet->addWidget(_posY_min_obj, 8, 2, 1, 1);
    _layoutObjet->addWidget(_s_posY_obj, 8, 3, 1, 5);
    _layoutObjet->addWidget(_posY_max_obj, 8, 9, 1, 1);
    _layoutObjet->addWidget(_l_posY_obj, 8, 10, 1, 1);
    _layoutObjet->addWidget(_le_posY_obj, 8, 11, 1, 1);

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

    _layoutObjet->addWidget(_posZ_obj, 9, 1, 1, 1);
    _layoutObjet->addWidget(_posZ_min_obj, 9, 2, 1, 1);
    _layoutObjet->addWidget(_s_posZ_obj, 9, 3, 1, 5);
    _layoutObjet->addWidget(_posZ_max_obj, 9, 9, 1, 1);
    _layoutObjet->addWidget(_l_posZ_obj, 9, 10, 1, 1);
    _layoutObjet->addWidget(_le_posZ_obj, 9, 11, 1, 1);


    /* Angle */
    _angleObj = new QLabel("Rotation", this);
    _angleObj->setFixedSize(150, 25);
    _layoutObjet->addWidget(_angleObj, 10, 0, 1, 2);

    /* Angle X */
    _angX_obj = new QLabel("RotX : ", this);
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

    _layoutObjet->addWidget(_angX_obj, 11, 1, 1, 1);
    _layoutObjet->addWidget(_angX_min_obj, 11, 2, 1, 1);
    _layoutObjet->addWidget(_s_angX_obj, 11, 3, 1, 5);
    _layoutObjet->addWidget(_angX_max_obj, 11, 9, 1, 1);
    _layoutObjet->addWidget(_l_angX_obj, 11, 10, 1, 1);
    _layoutObjet->addWidget(_le_angX_obj, 11, 11, 1, 1);
    _layoutObjet->addWidget(_ldeg_angX_obj, 11, 12, 1, 1);

    /* Angle Y */
    _angY_obj = new QLabel("RotY : ", this);
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

    _layoutObjet->addWidget(_angY_obj, 12, 1, 1, 1);
    _layoutObjet->addWidget(_angY_min_obj, 12, 2, 1, 1);
    _layoutObjet->addWidget(_s_angY_obj, 12, 3, 1, 5);
    _layoutObjet->addWidget(_angY_max_obj, 12, 9, 1, 1);
    _layoutObjet->addWidget(_l_angY_obj, 12, 10, 1, 1);
    _layoutObjet->addWidget(_le_angY_obj, 12, 11, 1, 1);
    _layoutObjet->addWidget(_ldeg_angY_obj, 12, 12, 1, 1);

    /* Angle Z */
    _angZ_obj = new QLabel("RotZ : ", this);
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

    _layoutObjet->addWidget(_angZ_obj, 13, 1, 1, 1);
    _layoutObjet->addWidget(_angZ_min_obj, 13, 2, 1, 1);
    _layoutObjet->addWidget(_s_angZ_obj, 13, 3, 1, 5);
    _layoutObjet->addWidget(_angZ_max_obj, 13, 9, 1, 1);
    _layoutObjet->addWidget(_l_angZ_obj, 13, 10, 1, 1);
    _layoutObjet->addWidget(_le_angZ_obj, 13, 11, 1, 1);
    _layoutObjet->addWidget(_ldeg_angZ_obj, 13, 12, 1, 1);

    /* Taille */
    _tailleObj = new QLabel("Taille", this);
    _tailleObj->setFixedSize(150, 25);
    _layoutObjet->addWidget(_tailleObj, 14, 0, 1, 2);

    /* Scale */
    _scale_obj = new QLabel("Taille : ", this);
    _le_scale_obj = new QLineEdit("1", this);
    _le_scale_obj->setFixedSize(80, 26);

    _layoutObjet->addWidget(_scale_obj, 15, 1, 1, 1);
    _layoutObjet->addWidget(_le_scale_obj, 15, 5, 1, 1);

    /* Boutons */
    _new_obj = new QPushButton("Nouv.", this);
    _new_obj->setMaximumWidth(50);
    _texture = new QPushButton("Texture", this);
    _delete_obj = new QPushButton("Supp.", this);
    _delete_obj->setMaximumWidth(50);
    _delete_obj->setEnabled(false);

    _layoutObjet->addWidget(_new_obj, 0, 12, 1, 1);
    _layoutObjet->addWidget(_texture, 1, 12, 1, 1);
    _layoutObjet->addWidget(_delete_obj, 16, 12, 1, 1);





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
    _positionnelle->setFixedSize(150, 25);
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
    _posX_min_cam = new QLabel("-30", this);
    _s_posX_cam = new QSlider(Qt::Horizontal, this);
    _s_posX_cam->setMinimum(-30);
    _s_posX_cam->setMaximum(30);
    _posX_max_cam = new QLabel("30", this);
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
    _posY_min_cam = new QLabel("-30", this);
    _s_posY_cam = new QSlider(Qt::Horizontal, this);
    _s_posY_cam->setMinimum(-30);
    _s_posY_cam->setMaximum(30);
    _posY_max_cam = new QLabel("30", this);
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
    _posZ_min_cam = new QLabel("-30", this);
    _s_posZ_cam = new QSlider(Qt::Horizontal, this);
    _s_posZ_cam->setMinimum(-30);
    _s_posZ_cam->setMaximum(30);
    _s_posZ_cam->setValue(-10);
    _posZ_max_cam = new QLabel("30", this);
    _l_posZ_cam = new QLabel("valeur : ", this);
    _le_posZ_cam = new QLineEdit("-10", this);
    _le_posZ_cam->setFixedSize(40, 26);
    _le_posZ_cam->setReadOnly(true);

    _layoutCamera->addWidget(_posZ_cam, 3, 1, 1, 1);
    _layoutCamera->addWidget(_posZ_min_cam, 3, 2, 1, 1);
    _layoutCamera->addWidget(_s_posZ_cam, 3, 3, 1, 5);
    _layoutCamera->addWidget(_posZ_max_cam, 3, 9, 1, 1);
    _layoutCamera->addWidget(_l_posZ_cam, 3, 10, 1, 1);
    _layoutCamera->addWidget(_le_posZ_cam, 3, 11, 1, 1);

    /* Angle */
    _angleCam = new QLabel("Rotation", this);
    _angleCam->setFixedSize(150, 25);
    _layoutCamera->addWidget(_angleCam, 4, 0, 1, 2);

    /* Angle X */
    _angX_cam = new QLabel("RotX : ", this);
    _angX_min_cam = new QLabel("-180", this);
    _s_angX_cam = new QSlider(Qt::Horizontal, this);
    _s_angX_cam->setMinimum(-180);
    _s_angX_cam->setMaximum(180);
    _angX_max_cam = new QLabel("180", this);
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
    _angY_cam = new QLabel("RotY : ", this);
    _angY_min_cam = new QLabel("-180", this);
    _s_angY_cam = new QSlider(Qt::Horizontal, this);
    _s_angY_cam->setMinimum(-180);
    _s_angY_cam->setMaximum(180);
    _angY_max_cam = new QLabel("180", this);
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
    _angZ_cam = new QLabel("RotZ : ", this);
    _angZ_min_cam = new QLabel("-180", this);
    _s_angZ_cam = new QSlider(Qt::Horizontal, this);
    _s_angZ_cam->setMinimum(-180);
    _s_angZ_cam->setMaximum(180);
    _angZ_max_cam = new QLabel("180", this);
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





    /* -------------------- FENETRE -------------------- */
    _tabs->setFixedWidth(500);
    _tabs->addTab(_wObjet, "Objets");
    _tabs->addTab(_wLumiere, "Lumières");
    _tabs->addTab(_wCamera, "Caméra");

    _layoutprincipal->addWidget(_tabs, 0, 0, 1, 1);
    _layoutprincipal->addWidget(_affichage, 0, 1, 1, 1);

    _window = new QWidget();
    _window->setLayout(_layoutprincipal);
    setCentralWidget(_window);

    /* -------------------- BARRE DE MENUS -------------------- */
    createActions();
    createMenus();

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

    /* De QComboBox à interface */
    QObject::connect(_lp, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &MainWindow::MAJInterfaceLum);
    QObject::connect(_obj, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &MainWindow::MAJInterfaceObj);

    /* De QSlider à la lumière positionnelle choisie */
    QObject::connect(_s_red_lp, &QSlider::valueChanged, this, &MainWindow::SliderALumierePos);
    QObject::connect(_s_green_lp, &QSlider::valueChanged, this, &MainWindow::SliderALumierePos);
    QObject::connect(_s_blue_lp, &QSlider::valueChanged, this, &MainWindow::SliderALumierePos);
    QObject::connect(_s_posX_lp, &QSlider::valueChanged, this, &MainWindow::SliderALumierePos);
    QObject::connect(_s_posY_lp, &QSlider::valueChanged, this, &MainWindow::SliderALumierePos);
    QObject::connect(_s_posZ_lp, &QSlider::valueChanged, this, &MainWindow::SliderALumierePos);

    /* De QSlider à l'objet choisi */
    QObject::connect(_s_red_obj, &QSlider::valueChanged, this, &MainWindow::SliderAObjet);
    QObject::connect(_s_green_obj, &QSlider::valueChanged, this, &MainWindow::SliderAObjet);
    QObject::connect(_s_blue_obj, &QSlider::valueChanged, this, &MainWindow::SliderAObjet);
    QObject::connect(_s_posX_obj, &QSlider::valueChanged, this, &MainWindow::SliderAObjet);
    QObject::connect(_s_posY_obj, &QSlider::valueChanged, this, &MainWindow::SliderAObjet);
    QObject::connect(_s_posZ_obj, &QSlider::valueChanged, this, &MainWindow::SliderAObjet);
    QObject::connect(_s_angX_obj, &QSlider::valueChanged, this, &MainWindow::SliderAObjet);
    QObject::connect(_s_angY_obj, &QSlider::valueChanged, this, &MainWindow::SliderAObjet);
    QObject::connect(_s_angZ_obj, &QSlider::valueChanged, this, &MainWindow::SliderAObjet);
    QObject::connect(_le_scale_obj, &QLineEdit::textChanged, this, &MainWindow::SliderAObjet);


    /* Boutons */
    QObject::connect(_new_lp, &QPushButton::clicked, this, &MainWindow::PopUpLum);
    QObject::connect(_new_obj, &QPushButton::clicked, this, &MainWindow::PopUpObj);
    QObject::connect(_delete_lp, &QPushButton::clicked, this, &MainWindow::OnClicDeleteLum);
    QObject::connect(_delete_obj, &QPushButton::clicked, this, &MainWindow::OnClicDeleteObj);


    /* Parent objet */
    QObject::connect(_parent, static_cast<void(QComboBox::*)(const QString&)>(&QComboBox::activated), this, &MainWindow::changementParent);

    /* Connexions mainwindow vers openGL */
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

    // Angle caméra
    QObject::connect(_s_angX_cam, &QSlider::valueChanged, _affichage, &WidgetOGL::setAngXCam);
    QObject::connect(_s_angY_cam, &QSlider::valueChanged, _affichage, &WidgetOGL::setAngYCam);
    QObject::connect(_s_angZ_cam, &QSlider::valueChanged, _affichage, &WidgetOGL::setAngZCam);

    // Modification textures
    QObject::connect(_texture, &QPushButton::clicked, this, &MainWindow::PopUpText);

    //Erreur de fichier au chargement
    QObject::connect(_affichage, &WidgetOGL::fichierNonTrouve, this, &MainWindow::fichierInconnu);

    //Reception objets au chargement
    QObject::connect(_affichage, &WidgetOGL::formeChargee, this, &MainWindow::receptionObjet);

    //Lumiere
    QObject::connect(this, &MainWindow::envoiLumiereOGL, _affichage, &WidgetOGL::recepetionLumiereOGL);

    /* Switch lumièrePos/LumiereDir */
     QObject::connect(_lp, static_cast<void(QComboBox::*)(const QString&)>(&QComboBox::activated), this, &MainWindow::switchPosDir);
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
+ * @brief MainWindow::MAJInterfaceLum
+ * Met les slider / spinbox / line edit aux bons endroits lors de la sélection d'une lumière dans le QComboBox
+ */
void MainWindow::MAJInterfaceLum()
{
    for (unsigned int i(0); i < ENSEMBLE_LUM_POS.size(); i++)
    {
        if(ENSEMBLE_LUM_POS[i].getNom() == _lp->currentText().toStdString())
        {
            _s_red_lp->setValue(ENSEMBLE_LUM_POS[i].getRed());
            _s_green_lp->setValue(ENSEMBLE_LUM_POS[i].getGreen());
            _s_blue_lp->setValue(ENSEMBLE_LUM_POS[i].getBlue());
            _s_posX_lp->setValue(ENSEMBLE_LUM_POS[i].getPosX());
            _s_posY_lp->setValue(ENSEMBLE_LUM_POS[i].getPosY());
            _s_posZ_lp->setValue(ENSEMBLE_LUM_POS[i].getPosZ());
        }
    }
}

/**
 * @brief MainWindow::MAJInterfaceObj
 * Met les slider / spinbox / line edit aux bons endroits lors de la sélection d'un objet dans le QComboBox
 */
void MainWindow::MAJInterfaceObj()
{
    _parent->clear();
    _parent->addItem("Aucun");
    for (unsigned int i(0); i < TOUS_LES_OBJETS.size(); i++)
    {
        if(TOUS_LES_OBJETS[i]->getNomForme() != _obj->currentText().toStdString())
        {
            _parent->addItem(QString::fromStdString(TOUS_LES_OBJETS[i]->getNomForme()));
        }
    }
    for (unsigned int i(0); i < TOUS_LES_OBJETS.size(); i++)
    {
        if(TOUS_LES_OBJETS[i]->getNomForme() == _obj->currentText().toStdString())
        {
            for (int h(1); h <= _parent->count(); h++)
            {
                if (TOUS_LES_OBJETS[i]->getParent() != 0)
                {
                    if (TOUS_LES_OBJETS[i]->getParent()->getNomForme() == _parent->itemText(h).toStdString())
                        _parent->setCurrentIndex(h);
                }
                else
                    _parent->setCurrentIndex(0);
            }
            _s_red_obj->setValue(TOUS_LES_OBJETS[i]->getRed());
            _s_green_obj->setValue(TOUS_LES_OBJETS[i]->getGreen());
            _s_blue_obj->setValue(TOUS_LES_OBJETS[i]->getBlue());
            _s_posX_obj->setValue(TOUS_LES_OBJETS[i]->getPosX());
            _s_posY_obj->setValue(TOUS_LES_OBJETS[i]->getPosY());
            _s_posZ_obj->setValue(TOUS_LES_OBJETS[i]->getPosZ());
            _s_angX_obj->setValue(TOUS_LES_OBJETS[i]->getAngX());
            _s_angY_obj->setValue(TOUS_LES_OBJETS[i]->getAngY());
            _s_angZ_obj->setValue(TOUS_LES_OBJETS[i]->getAngZ());
            _le_scale_obj->setText(QString::number(TOUS_LES_OBJETS[i]->getScale()));
        }
    }
}

/**
 * @brief MainWindow::SliderALumierePos
 * Met à jour les valeurs de la lumière positionnelle choisie quand il y a modification sur l'interface
 */
void MainWindow::SliderALumierePos()
{
    for (unsigned int i(0); i < ENSEMBLE_LUM_POS.size(); i++)
    {
        if(ENSEMBLE_LUM_POS[i].getNom() == _lp->currentText().toStdString())
        {
            if (sender() == _s_red_lp)
                ENSEMBLE_LUM_POS[i].setRed(_s_red_lp->value());
            if (sender() == _s_green_lp)
                ENSEMBLE_LUM_POS[i].setGreen(_s_green_lp->value());
            if (sender() == _s_blue_lp)
                ENSEMBLE_LUM_POS[i].setBlue(_s_blue_lp->value());
            if (sender()==_s_posX_lp)
                ENSEMBLE_LUM_POS[i].setPosX(_s_posX_lp->value());
            if (sender()==_s_posY_lp)
                ENSEMBLE_LUM_POS[i].setPosY(_s_posY_lp->value());
            if (sender()==_s_posZ_lp)
                ENSEMBLE_LUM_POS[i].setPosZ(_s_posZ_lp->value());
        }
    }
    _affichage->changerLumiere(ENSEMBLE_LUM_POS);
}

/**
 * @brief MainWindow::SliderAObjet
 * Met à jour les valeurs de l'objet choisi quand il y a modification sur l'interface
 */
void MainWindow::SliderAObjet()
{
    for (unsigned int i(0); i < TOUS_LES_OBJETS.size(); i++)
    {
        if(TOUS_LES_OBJETS[i]->getNomForme() == _obj->currentText().toStdString())
        {
            if (sender() == _s_red_obj)
                TOUS_LES_OBJETS[i]->setRed(_s_red_obj->value());
            if (sender() == _s_green_obj)
                TOUS_LES_OBJETS[i]->setGreen(_s_green_obj->value());
            if (sender() == _s_blue_obj)
                TOUS_LES_OBJETS[i]->setBlue(_s_blue_obj->value());
            if (sender()==_s_posX_obj)
                TOUS_LES_OBJETS[i]->setPosX(_s_posX_obj->value());
            if (sender()==_s_posY_obj)
                TOUS_LES_OBJETS[i]->setPosY(_s_posY_obj->value());
            if (sender()==_s_posZ_obj)
                TOUS_LES_OBJETS[i]->setPosZ(_s_posZ_obj->value());
            if (sender()==_s_angX_obj)
                TOUS_LES_OBJETS[i]->setAngX(_s_angX_obj->value());
            if (sender()==_s_angY_obj)
                TOUS_LES_OBJETS[i]->setAngY(_s_angY_obj->value());
            if (sender()==_s_angZ_obj)
                TOUS_LES_OBJETS[i]->setAngZ(_s_angZ_obj->value());
            if (sender()==_le_scale_obj)
                TOUS_LES_OBJETS[i]->setScale(_le_scale_obj->text().toFloat());

            //Debug
            //TOUS_LES_OBJETS[i]->infoForme();
        }
    }
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

    /* Reception de la lumière émise par le pop up */
    QObject::connect(ppl, &PopUpLumiere::lumiereCreee, this, &MainWindow::receptionLumiere);
}

/**
 * @brief MainWindow::PopUpObj
 * Fait apparaître la fenêtre de création d'objets
 */
void MainWindow::PopUpObj()
{
    PopUpObjet * ppo = new PopUpObjet(NOM_DES_FORMES,TOUS_LES_OBJETS);

    /* On empêche de toucher à la fenêtre parent pendant que la fenêtre enfant est ouverte */
    ppo->setWindowModality(Qt::ApplicationModal);
    ppo->show();

    QObject::connect(ppo, &PopUpObjet::creationObjet, this, &MainWindow::receptionObjet);
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
        for (unsigned int i(0); i < ENSEMBLE_LUM_POS.size(); i++)
        {
            if(ENSEMBLE_LUM_POS[i].getNom() == _lp->currentText().toStdString())
            {
                ENSEMBLE_LUM_POS.erase(ENSEMBLE_LUM_POS.begin()+i);
                _lp->removeItem(i);
            }
        }

        _nbLumierePos--;

        if (_nbLumierePos == 0)
        {
            _s_posX_lp->setValue(0);
            _s_posY_lp->setValue(0);
            _s_posZ_lp->setValue(0);
        }
        else
        {
            _lp->setCurrentIndex(0);
            _s_posX_lp->setValue(ENSEMBLE_LUM_POS[0].getPosX());
            _s_posY_lp->setValue(ENSEMBLE_LUM_POS[0].getPosY());
            _s_posZ_lp->setValue(ENSEMBLE_LUM_POS[0].getPosZ());
        }

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
 * On vérifie le nombre d'objets pour griser ou non les boutons de création/suppression et supprimer l'objet choisi ainsi que ses formes filles
 * On a choisi de supprimer tous les éléments filles d'une forme, au lieu de les remettre au milieu
 */
void MainWindow::OnClicDeleteObj()
{
    /*
     *
     * A FAIRE: VERIFIER QUE L'OBJET N'A PAS DE PARENT, SI C'EST LE CAS, LE VIRER DE SON PARENT
     *
     */


    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cancel", "Voulez-vous supprimer cet objet ?"
                                                  "(Tous les descendants seront aussi supprimés.)", (QMessageBox::No | QMessageBox::Yes));
    if (reply == QMessageBox::Yes)
    {
        unsigned int indiceSuppression(0);
        std::cout << "**** SUPPRESSION ****" << std::endl;
        /* A compléter avec la suppression de l'objet*/
        for (unsigned int i(0); i < TOUS_LES_OBJETS.size(); i++)
        {
            if(TOUS_LES_OBJETS[i]->getNomForme() == _obj->currentText().toStdString())
            {
                indiceSuppression = i;
            }
        }
        std::cout << "Debut de suppression de " << TOUS_LES_OBJETS[indiceSuppression]->getNomForme() << std::endl;
        if (TOUS_LES_OBJETS[indiceSuppression]->getFilles().size()>0)   //Si l'objet a des enfants à supprimer
        {
            for (unsigned int j(0); j < TOUS_LES_OBJETS[indiceSuppression]->getFilles().size(); j++)    //Pour tous les éléments filles
            {
                for (int h(0); h <= _obj->count(); h++)
                {
                    if (TOUS_LES_OBJETS[indiceSuppression]->getFilles()[j]->getNomForme() == _obj->itemText(h).toStdString())
                    {
                        _obj->removeItem(h);
                    }
                }
            }
            TOUS_LES_OBJETS[indiceSuppression]->getFilles().clear();    //On efface tous les éléments qui étaient attachés à la forme sélectionnée
        }
        _affichage->supprimerForme(TOUS_LES_OBJETS[indiceSuppression]->getNomForme());
        for (int h(0); h <= _obj->count(); h++)
        {
            if (TOUS_LES_OBJETS[indiceSuppression]->getNomForme() == _obj->itemText(h).toStdString())
            {
                _obj->removeItem(h);
            }
        }
        std::cout << "Suppression de " << TOUS_LES_OBJETS[indiceSuppression]->getNomForme() << std::endl;
        TOUS_LES_OBJETS.erase(TOUS_LES_OBJETS.begin()+indiceSuppression);
        std::cout << "**** FIN DE SUPPRESSION ****" << std::endl;



        _nbObjet--;

        if (_nbObjet == 0)
        {
            _s_posX_obj->setValue(0);
            _s_posY_obj->setValue(0);
            _s_posZ_obj->setValue(0);
        }
        else
        {
            _obj->setCurrentIndex(0);
            _s_posX_obj->setValue(TOUS_LES_OBJETS[0]->getPosX());
            _s_posY_obj->setValue(TOUS_LES_OBJETS[0]->getPosY());
            _s_posZ_obj->setValue(TOUS_LES_OBJETS[0]->getPosZ());
        }
    }
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
 * @brief MainWindow::receptionLumiere
 * @param lp
 * Ajoute la lumière positionnelle créée dans le popup dans le mainwindow
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

    if (_nbLumierePos == 0)
        _delete_lp->setEnabled(false);
    else
        _delete_lp->setEnabled(true);

    if (_nbLumierePos >= 7)
        _new_lp->setEnabled(false);
    else
        _new_lp->setEnabled(true);

    std::cout << "Lumieres actuelles:" << std::endl;
    for (unsigned int i(0); i<ENSEMBLE_LUM_POS.size(); i++)
        std::cout << "Lumiere " << i << ": " << ENSEMBLE_LUM_POS[i].getNom() << std::endl;

    emit envoiLumiereOGL(lp);
}


void MainWindow::receptionObjet(std::shared_ptr<forme> ptr, QString parent)
{
    TOUS_LES_OBJETS.push_back(ptr);
    _nbObjet++;
    _obj->addItem(QString::fromStdString(ptr->getNomForme()));
    _parent->clear();
    _parent->addItem("Aucun");
    for (unsigned int i(0); i < TOUS_LES_OBJETS.size(); i++)
    {
        if(TOUS_LES_OBJETS[i]->getNomForme() != _obj->currentText().toStdString())
        {
            _parent->addItem(QString::fromStdString(TOUS_LES_OBJETS[i]->getNomForme()));
        }
    }

    if (parent != "Aucun")  //L'objet créé a un parent, donc l'objet sera créé depuis son parent
    {
        for (unsigned int i(0); i<TOUS_LES_OBJETS.size();i++)
        {
            if (TOUS_LES_OBJETS[i]->getNomForme() == parent.toStdString())
            {
                TOUS_LES_OBJETS[i]->ajoutFormesFilles(ptr);
                ptr->setParent(TOUS_LES_OBJETS[i]);
            }
        }
    }
    else    //L'objet créé n'a pas de parent, il sera donc affiché depuis 0,0,0, donc ajout immédiat dans affichage
    {
        _affichage->ajouterForme(ptr);
    }

    if (_nbObjet == 0)
        _delete_obj->setEnabled(false);
    else
        _delete_obj->setEnabled(true);

    if (_nbObjet >= 100)
        _new_obj->setEnabled(false);
    else
        _new_obj->setEnabled(true);
}


void MainWindow::changementParent(QString nomParent)
{
    /* EN COURS D'IMPLEMENTATION */

    for (unsigned int i(0); i < TOUS_LES_OBJETS.size(); i++)
    {
        if (TOUS_LES_OBJETS[i]->getNomForme() == _obj->currentText().toStdString())   //I est l'objet en cours
        {
            for (unsigned int j(0); j <TOUS_LES_OBJETS.size(); j++)
            {
                if (TOUS_LES_OBJETS[i]->getParent() != 0)   //Si l'objet en cours a déjà un parent
                {
                    //Effacement du parent actuel
                    TOUS_LES_OBJETS[i]->getParent()->supprimerFille(TOUS_LES_OBJETS[i]->getNomForme());

                    if (nomParent != "Aucun")
                    {
                        //Ajout dans le nouveau parent
                        if (TOUS_LES_OBJETS[j]->getNomForme() == nomParent.toStdString())  //J est l'objet parent
                        {
                            bool correct = true; //Va permettre de vérifier qu'un parent ne peut pas avoir un fils comme parent
                            for (unsigned int c(0); c<TOUS_LES_OBJETS[i]->getFilles().size();c++)
                            {
                                if (TOUS_LES_OBJETS[i]->getFilles()[c]->checkNomFilles(nomParent.toStdString()) == false)
                                    correct = false;
                            }
                            if (correct == false)
                            {
                                //Pour obtenir un message clair
                                std::string erreur;
                                std::ostringstream p1;
                                std::ostringstream p2;
                                p1 << TOUS_LES_OBJETS[i]->getNomForme();
                                p2 << TOUS_LES_OBJETS[j]->getNomForme();
                                erreur = "L'objet nommé ";
                                erreur += p1.str();
                                erreur += " contient l'objet ";
                                erreur += p2.str();
                                erreur += " dans ses objets fils. ";
                                erreur += p2.str();
                                erreur += " ne peut pas être un parent de ";
                                erreur += p1.str();
                                erreur += ". Veuillez recommencer.";
                                QString erreurQ = QString::fromStdString(erreur);
                                QMessageBox::warning(this, "Error",erreurQ);
                                //On remet la combobox à son état initial
                                if (TOUS_LES_OBJETS[i]->getParent() != 0)
                                {
                                    for (int h(0); h <= _obj->count(); h++)
                                    {
                                        if (TOUS_LES_OBJETS[i]->getParent()->getNomForme() == _parent->itemText(h).toStdString())
                                        {
                                            _parent->setCurrentIndex(h);
                                        }
                                    }
                                }
                                return;
                            }
                            else
                            {
                                TOUS_LES_OBJETS[j]->ajoutFormesFilles(TOUS_LES_OBJETS[i]);  //Ajout de l'objet au parent
                                TOUS_LES_OBJETS[i]->setParent(TOUS_LES_OBJETS[j]);  //Ajout du parent à l'objet
                                return;
                            }
                        }
                    }
                    else
                    {
                        TOUS_LES_OBJETS[i]->setParent(0);  //Ajout du parent nul à l'objet
                        _affichage->ajouterForme(TOUS_LES_OBJETS[i]);
                        return;
                    }
                }
                else    //L'objet n'avait pas de parent avant
                {
                    if (nomParent != "Aucun")   //On vérifie qu'on veut bien lui mettre un parent
                    {
                        if (TOUS_LES_OBJETS[j]->getNomForme() == nomParent.toStdString())  //J est l'objet parent
                        {
                            //Ajout dans le nouveau parent uniquement
                            for (unsigned int k(0); k<_affichage->getFormeAfficher().size();k++)
                            {
                                if (TOUS_LES_OBJETS[i]->getNomForme() == _affichage->getFormeAfficher()[k]->getNomForme()) //I est le futur enfant
                                {
                                    bool correct = true; //Va permettre de vérifier qu'un parent ne peut pas avoir un fils comme parent
                                    // On regarde dans le futur fils si il n'y a pas déjà le nom du futur parent quelque part
                                    for (unsigned int c(0); c<TOUS_LES_OBJETS[i]->getFilles().size();c++)
                                    {
                                        if (TOUS_LES_OBJETS[i]->getFilles()[c]->checkNomFilles(nomParent.toStdString()) == false)
                                            correct = false;
                                    }
                                    if (correct == false)
                                    {
                                        //Pour obtenir un message clair
                                        std::string erreur;
                                        std::ostringstream p1;
                                        std::ostringstream p2;
                                        p1 << TOUS_LES_OBJETS[i]->getNomForme();
                                        p2 << TOUS_LES_OBJETS[j]->getNomForme();
                                        erreur = "L'objet nommé ";
                                        erreur += p1.str();
                                        erreur += " contient l'objet ";
                                        erreur += p2.str();
                                        erreur += " dans ses objets fils. ";
                                        erreur += p2.str();
                                        erreur += " ne peut pas être un parent de ";
                                        erreur += p1.str();
                                        erreur += ". Veuillez recommencer.";
                                        QString erreurQ = QString::fromStdString(erreur);
                                        QMessageBox::warning(this, "Error",erreurQ);
                                        _parent->setCurrentIndex(0);    //Le parent de base était aucun
                                        return;
                                    }
                                    else
                                    {
                                        TOUS_LES_OBJETS[j]->ajoutFormesFilles(TOUS_LES_OBJETS[i]);  //Ajout de l'objet au parent
                                        TOUS_LES_OBJETS[i]->setParent(TOUS_LES_OBJETS[j]);  //Ajout du parent à l'objet
                                        _affichage->supprimerForme(TOUS_LES_OBJETS[i]->getNomForme()); //Suppression de l'objet de _affichage
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void MainWindow::PopUpText()
{
    PopUpTexture * ppt = new PopUpTexture(TOUTES_LES_ADRESSE_TEXTURES);

    /* On empêche de toucher à la fenêtre parent pendant que la fenêtre enfant est ouverte */
    ppt->setWindowModality(Qt::ApplicationModal);
    ppt->show();

    /* Reception de la texture émise par le pop up */
    QObject::connect(ppt, &PopUpTexture::textureAppliquee, this, &MainWindow::changementTexture);
}

/**
 * @brief changementTexture
 * @param idTX
 * Slot qui permet de changer ou supprimer la texture de l'objet en cours
 */
void MainWindow::changementTexture(unsigned int idTX)
{
    for (unsigned int i(0); i < TOUS_LES_OBJETS.size(); i++)
    {
        if (TOUS_LES_OBJETS[i]->getNomForme() == _obj->currentText().toStdString())   //On est sur l'objet en cours
        {
            int nouvID = static_cast<int>(idTX);

            if (nouvID != 0)
                TOUS_LES_OBJETS[i]->setTexture(nouvID);
            else
                TOUS_LES_OBJETS[i]->setTexture(-4);
        }
    }
}


/**
 * @brief MainWindow::createActions
 * Créer les actions des menus de la MenuBar
 */
void MainWindow::createActions()
{
    _save = new QAction("&Sauvegarder", this);
    _save->setShortcuts(QKeySequence::Save);
    _save->setStatusTip("Sauvegarde la scène");
    QObject::connect(_save, &QAction::triggered, this, &MainWindow::sauvegardeScn);

    _load = new QAction("&Ouvrir", this);
    _load->setShortcuts(QKeySequence::Open);
    _load->setStatusTip("Charge une scène");
    QObject::connect(_load, &QAction::triggered, this, &MainWindow::chargementScn);

    _exit = new QAction("&Quitter", this);
    _exit->setShortcuts(QKeySequence::Quit);
    _exit->setStatusTip("Quitte l'application");
    QObject::connect(_exit, &QAction::triggered, this, &QWidget::close);

    _aboutUs = new QAction("&Nous concernant", this);
    _aboutUs->setStatusTip("Affiche les créateurs de l'application");
    // A REMPLIR

    _howToUse = new QAction("&Comment ça marche ?", this);
    _howToUse->setShortcuts(QKeySequence::WhatsThis);
    _howToUse->setStatusTip("Affiche un tutoriel pour utiliser l'application");
    // A REMPLIR
}

/**
 * @brief MainWindow::createMenus
 * Créer les menus contenant les actions
 */
void MainWindow::createMenus()
{
    _file = new QMenu(this);
    _file = menuBar()->addMenu("&Fichier");
    _file->addAction(_save);
    _file->addAction(_load);
    _file->addSeparator();
    _file->addAction(_exit);

    _help = new QMenu(this);
    _help = menuBar()->addMenu("&Aide");
    _help->addAction(_aboutUs);
    _help->addSeparator();
    _help->addAction(_howToUse);
}

void MainWindow::sauvegardeScn(bool clic)
{
    QDir dossier;
    dossier.mkdir("Sauvegardes");
    QString fichierSave = QInputDialog::getText(this, "Sauvegarde", "Donnez le nom du fichier à sauvegarder.");
    std::string nomFichier = fichierSave.toStdString();
    _affichage->sauvegardeScene(nomFichier);
}

void MainWindow::chargementScn(bool clic)
{
    QString fichierSave = QInputDialog::getText(this, "Chargement", "Donnez le nom du fichier à charger. Il doit être situé dans Programme/Sauvegarde/");
    std::string nomFichier = fichierSave.toStdString();
    TOUS_LES_OBJETS.clear();
    _obj->clear();
    _nbObjet = 0;
    _affichage->chargementScene(nomFichier);
}

void MainWindow::fichierInconnu(std::string nomFichier)
{
    QString nom = QString::fromStdString(nomFichier);
    QMessageBox messageBox;
    messageBox.critical(0,"Erreur", "Impossible de charger le fichier "+nom+". Celui ci n'existe pas.");
    messageBox.setFixedSize(500,200);
}


void MainWindow::switchPosDir()
{
    for (unsigned int i(0); i < ENSEMBLE_LUM_POS.size(); i++)
    {
        if (ENSEMBLE_LUM_POS[i].getNom() == _lp->currentText().toStdString())
        {
            if (ENSEMBLE_LUM_POS[i].getType() == true)
            {
               _positionnelle->setText("Positionnelle");
               _posX_lp->setText("PosX");
               _posY_lp->setText("PosY");
               _posZ_lp->setText("PosZ");
            }
            else
            {
                _positionnelle->setText("Directionnelle");
                _posX_lp->setText("DirX");
                _posY_lp->setText("DirY");
                _posZ_lp->setText("DirZ");
            }
        }
    }
}
