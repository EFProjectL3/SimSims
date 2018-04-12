#pragma once
#include <QMainWindow>
#include "widgetOGL.h"
#include <QSlider>
#include <QtWidgets>
#include "popup_lum.hh"
#include "popup_obj.hh"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    std::vector<std::string> getNomFormes()
    { return NOM_DES_FORMES; }

public slots:
    void SliderALineEdit(int i);

    void PopUpLum();
    void PopUpObj();

    void IncNbLum();
    void IncNbObj();

    void OnClicDeleteLum();
    void OnClicDeleteObj();

    void receptionLumiere(LumierePos lp);
    void receptionObjet(Objet o);

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


        QLabel * _positionnelle;
            QComboBox * _lp;

            QLabel * _red_lp;
            QLabel * _red_min_lp;
            QSlider * _s_red_lp;
            QLabel * _red_max_lp;
            QLabel * _l_red_lp;
            QSpinBox * _sp_red_lp;

            QLabel * _green_lp;
            QLabel * _green_min_lp;
            QSlider * _s_green_lp;
            QLabel * _green_max_lp;
            QLabel * _l_green_lp;
            QSpinBox * _sp_green_lp;

            QLabel * _blue_lp;
            QLabel * _blue_min_lp;
            QSlider * _s_blue_lp;
            QLabel * _blue_max_lp;
            QLabel * _l_blue_lp;
            QSpinBox * _sp_blue_lp;

            QLabel * _posX_lp;
            QLabel * _posX_min_lp;
            QSlider * _s_posX_lp;
            QLabel * _posX_max_lp;
            QLabel * _l_posX_lp;
            QLineEdit * _le_posX_lp;

            QLabel * _posY_lp;
            QLabel * _posY_min_lp;
            QSlider * _s_posY_lp;
            QLabel * _posY_max_lp;
            QLabel * _l_posY_lp;
            QLineEdit * _le_posY_lp;

            QLabel * _posZ_lp;
            QLabel * _posZ_min_lp;
            QSlider * _s_posZ_lp;
            QLabel * _posZ_max_lp;
            QLabel * _l_posZ_lp;
            QLineEdit * _le_posZ_lp;


        QPushButton * _delete_lp;
        QPushButton * _new_lp;





    /* Onglet de gestion de la caméra */
    QGridLayout * _layoutCamera;

    QLabel * _positionCam;
        QLabel * _posX_cam;
        QLabel * _posX_min_cam;
        QSlider * _s_posX_cam;
        QLabel * _posX_max_cam;
        QLabel * _l_posX_cam;
        QLineEdit * _le_posX_cam;

        QLabel * _posY_cam;
        QLabel * _posY_min_cam;
        QSlider * _s_posY_cam;
        QLabel * _posY_max_cam;
        QLabel * _l_posY_cam;
        QLineEdit * _le_posY_cam;

        QLabel * _posZ_cam;
        QLabel * _posZ_min_cam;
        QSlider * _s_posZ_cam;
        QLabel * _posZ_max_cam;
        QLabel * _l_posZ_cam;
        QLineEdit * _le_posZ_cam;

    QLabel * _angleCam;
        QLabel * _angX_cam;
        QLabel * _angX_min_cam;
        QSlider * _s_angX_cam;
        QLabel * _angX_max_cam;
        QLabel * _l_angX_cam;
        QLineEdit * _le_angX_cam;
        QLabel * _ldeg_angX_cam;

        QLabel * _angY_cam;
        QLabel * _angY_min_cam;
        QSlider * _s_angY_cam;
        QLabel * _angY_max_cam;
        QLabel * _l_angY_cam;
        QLineEdit * _le_angY_cam;
        QLabel * _ldeg_angY_cam;

        QLabel * _angZ_cam;
        QLabel * _angZ_min_cam;
        QSlider * _s_angZ_cam;
        QLabel * _angZ_max_cam;
        QLabel * _l_angZ_cam;
        QLineEdit * _le_angZ_cam;
        QLabel * _ldeg_angZ_cam;





    /* Onglet de gestion des objets */
    QGridLayout * _layoutObjet;

        QComboBox * _obj;

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
            QLineEdit * _le_posX_obj;

            QLabel * _posY_obj;
            QLabel * _posY_min_obj;
            QSlider * _s_posY_obj;
            QLabel * _posY_max_obj;
            QLabel * _l_posY_obj;
            QLineEdit * _le_posY_obj;

            QLabel * _posZ_obj;
            QLabel * _posZ_min_obj;
            QSlider * _s_posZ_obj;
            QLabel * _posZ_max_obj;
            QLabel * _l_posZ_obj;
            QLineEdit * _le_posZ_obj;

        QLabel * _angleObj;
            QLabel * _angX_obj;
            QLabel * _angX_min_obj;
            QSlider * _s_angX_obj;
            QLabel * _angX_max_obj;
            QLabel * _l_angX_obj;
            QLineEdit * _le_angX_obj;
            QLabel * _ldeg_angX_obj;

            QLabel * _angY_obj;
            QLabel * _angY_min_obj;
            QSlider * _s_angY_obj;
            QLabel * _angY_max_obj;
            QLabel * _l_angY_obj;
            QLineEdit * _le_angY_obj;
            QLabel * _ldeg_angY_obj;

            QLabel * _angZ_obj;
            QLabel * _angZ_min_obj;
            QSlider * _s_angZ_obj;
            QLabel * _angZ_max_obj;
            QLabel * _l_angZ_obj;
            QLineEdit * _le_angZ_obj;
            QLabel * _ldeg_angZ_obj;

        QLabel * _tailleObj;
            QLabel * _scale_obj;
            QLineEdit * _le_scale_obj;


        QPushButton * _delete_obj;
        QPushButton * _new_obj;

        int _nbLumierePos;
        int _nbObjet;

        std::vector<std::shared_ptr<forme>> TOUTES_LES_FORMES;
        std::vector<QOpenGLTexture *> TOUTES_LES_TEXTURES;
        std::vector<std::string> NOM_DES_FORMES;
        std::vector<LumierePos> ENSEMBLE_LUM_POS;
        std::vector<Objet> ENSEMBLE_OBJET;

    QWidget * _window;
};

