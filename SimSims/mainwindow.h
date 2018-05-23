#pragma once
#include <QMainWindow>
#include "widgetOGL.h"
#include <QSlider>
#include <QtWidgets>
#include "popup_lum.hh"
#include "popup_obj.hh"
#include "popup_text.hh"
#include "labelClic.hh"

class QAction;
class QActionGroup;
class QLabel;
class QMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    std::vector<std::string> getNomFormes()
    { return NOM_DES_FORMES; }

signals:
    void envoiLumiereOGL(LumierePos lp);

public slots:
    void PopUpLum();
    void PopUpObj();

    void OnClicDeleteLum();
    void OnClicDeleteObj();

    void MAJInterfaceLum();
    void MAJInterfaceObj();

    void SliderALumierePosDir();
    void SliderAObjet();

    void receptionLumiere(LumierePos lp);
    void receptionObjet(std::shared_ptr<forme> ptr, QString parent);

    void changementParent(QString nomParent);

    void PopUpText();
    void changementTexture(unsigned int idTX);

    void sauvegardeScn(bool clic);
    void chargementScn(bool clic);

    void fichierInconnu(std::string nomFichier);

    void switchPosDir();

    void infoCrea();
    void infoTuto();

private:
    QGridLayout * _layoutprincipal;
    WidgetOGL * _affichage;

    /* Onglet de gestion des lumières */
    QTabWidget * _tabs;
    QGridLayout * _layoutLumiere;

    QLabel *_ambiante;
    QLabel * _red_la;
    QLabel * _red_min_la;
    QSlider * _s_red_la;
    QLabel * _red_max_la;
    QLabel * _l_red_la;
    QSpinBox * _sp_red_la;

    QLabel * _green_la;
    QLabel * _green_min_la;
    QSlider * _s_green_la;
    QLabel * _green_max_la;
    QLabel * _l_green_la;
    QSpinBox * _sp_green_la;

    QLabel * _blue_la;
    QLabel * _blue_min_la;
    QSlider * _s_blue_la;
    QLabel * _blue_max_la;
    QLabel * _l_blue_la;
    QSpinBox * _sp_blue_la;


    QLabel * _positionnelleDirectionnelle;
    QComboBox * _lpd;

    QLabel * _red_lpd;
    QLabel * _red_min_lpd;
    QSlider * _s_red_lpd;
    QLabel * _red_max_lpd;
    QLabel * _l_red_lpd;
    QSpinBox * _sp_red_lpd;

    QLabel * _green_lpd;
    QLabel * _green_min_lpd;
    QSlider * _s_green_lpd;
    QLabel * _green_max_lpd;
    QLabel * _l_green_lpd;
    QSpinBox * _sp_green_lpd;

    QLabel * _blue_lpd;
    QLabel * _blue_min_lpd;
    QSlider * _s_blue_lpd;
    QLabel * _blue_max_lpd;
    QLabel * _l_blue_lpd;
    QSpinBox * _sp_blue_lpd;

    QLabel * _posDirX_lpd;
    QLabel * _posDirX_min_lpd;
    QSlider * _s_posDirX_lpd;
    QLabel * _posDirX_max_lpd;
    QLabel * _l_posDirX_lpd;
    QSpinBox * _sp_posDirX_lpd;

    QLabel * _posDirY_lpd;
    QLabel * _posDirY_min_lpd;
    QSlider * _s_posDirY_lpd;
    QLabel * _posDirY_max_lpd;
    QLabel * _l_posDirY_lpd;
    QSpinBox * _sp_posDirY_lpd;

    QLabel * _posDirZ_lpd;
    QLabel * _posDirZ_min_lpd;
    QSlider * _s_posDirZ_lpd;
    QLabel * _posDirZ_max_lpd;
    QLabel * _l_posDirZ_lpd;
    QSpinBox * _sp_posDirZ_lpd;


    QPushButton * _delete_lpd;
    QPushButton * _new_lpd;

    int _nbLumierePosDir;


    /* Onglet de gestion de la caméra */
    QGridLayout * _layoutCamera;

    QLabel * _positionCam;
    QLabel * _posX_cam;
    QLabel * _posX_min_cam;
    QSlider * _s_posX_cam;
    QLabel * _posX_max_cam;
    QLabel * _l_posX_cam;
    QSpinBox * _sp_posX_cam;

    QLabel * _posY_cam;
    QLabel * _posY_min_cam;
    QSlider * _s_posY_cam;
    QLabel * _posY_max_cam;
    QLabel * _l_posY_cam;
    QSpinBox * _sp_posY_cam;

    QLabel * _posZ_cam;
    QLabel * _posZ_min_cam;
    QSlider * _s_posZ_cam;
    QLabel * _posZ_max_cam;
    QLabel * _l_posZ_cam;
    QSpinBox * _sp_posZ_cam;

    QLabel * _angleCam;
    QLabel * _angX_cam;
    QLabel * _angX_min_cam;
    QSlider * _s_angX_cam;
    QLabel * _angX_max_cam;
    QLabel * _l_angX_cam;
    QSpinBox * _sp_angX_cam;
    QLabel * _ldeg_angX_cam;

    QLabel * _angY_cam;
    QLabel * _angY_min_cam;
    QSlider * _s_angY_cam;
    QLabel * _angY_max_cam;
    QLabel * _l_angY_cam;
    QSpinBox * _sp_angY_cam;
    QLabel * _ldeg_angY_cam;

    QLabel * _angZ_cam;
    QLabel * _angZ_min_cam;
    QSlider * _s_angZ_cam;
    QLabel * _angZ_max_cam;
    QLabel * _l_angZ_cam;
    QSpinBox * _sp_angZ_cam;
    QLabel * _ldeg_angZ_cam;





    /* Onglet de gestion des objets */
    QGridLayout * _layoutObjet;

    QComboBox * _obj;

    QLabel * _choixParent;
    QComboBox * _parent;

    QLabel * _couleurObj;
    QLabel * _red_obj;
    QLabel * _red_min_obj;
    QSlider * _s_red_obj;
    QLabel * _red_max_obj;
    QLabel * _l_red_obj;
    QSpinBox * _sp_red_obj;

    QLabel * _green_obj;
    QLabel * _green_min_obj;
    QSlider * _s_green_obj;
    QLabel * _green_max_obj;
    QLabel * _l_green_obj;
    QSpinBox * _sp_green_obj;

    QLabel * _blue_obj;
    QLabel * _blue_min_obj;
    QSlider * _s_blue_obj;
    QLabel * _blue_max_obj;
    QLabel * _l_blue_obj;
    QSpinBox * _sp_blue_obj;

    QLabel * _positionObj;
    QLabel * _posX_obj;
    QLabel * _posX_min_obj;
    QSlider * _s_posX_obj;
    QLabel * _posX_max_obj;
    QLabel * _l_posX_obj;
    QSpinBox * _sp_posX_obj;

    QLabel * _posY_obj;
    QLabel * _posY_min_obj;
    QSlider * _s_posY_obj;
    QLabel * _posY_max_obj;
    QLabel * _l_posY_obj;
    QSpinBox * _sp_posY_obj;

    QLabel * _posZ_obj;
    QLabel * _posZ_min_obj;
    QSlider * _s_posZ_obj;
    QLabel * _posZ_max_obj;
    QLabel * _l_posZ_obj;
    QSpinBox * _sp_posZ_obj;

    QLabel * _angleObj;
    QLabel * _angX_obj;
    QLabel * _angX_min_obj;
    QSlider * _s_angX_obj;
    QLabel * _angX_max_obj;
    QLabel * _l_angX_obj;
    QSpinBox * _sp_angX_obj;
    QLabel * _ldeg_angX_obj;

    QLabel * _angY_obj;
    QLabel * _angY_min_obj;
    QSlider * _s_angY_obj;
    QLabel * _angY_max_obj;
    QLabel * _l_angY_obj;
    QSpinBox * _sp_angY_obj;
    QLabel * _ldeg_angY_obj;

    QLabel * _angZ_obj;
    QLabel * _angZ_min_obj;
    QSlider * _s_angZ_obj;
    QLabel * _angZ_max_obj;
    QLabel * _l_angZ_obj;
    QSpinBox * _sp_angZ_obj;
    QLabel * _ldeg_angZ_obj;

    QLabel * _tailleObj;
    QLabel * _scale_obj;
    QLineEdit * _le_scale_obj;


    QPushButton * _delete_obj;
    QPushButton * _new_obj;
    QPushButton * _sauvegarde_obj;    
    QPushButton * _charger_obj;

    int _nbObjet;

    /* Textures */
    QPushButton * _texture;


    void createActions();
    void createMenus();

    /* Barre de menus */
    QMenu * _file;
    QAction * _load;
    QAction * _save;
    QAction * _exit;

    QMenu * _help;
    QAction * _aboutUs;
    QAction * _howToUse;

    std::vector<std::shared_ptr<forme>> TOUS_LES_OBJETS;
    std::vector<std::string> TOUTES_LES_ADRESSE_TEXTURES;
    std::vector<std::string> NOM_DES_FORMES;
    std::vector<LumierePos> ENSEMBLE_LUM_POSDIR;

    QWidget * _window;
};

