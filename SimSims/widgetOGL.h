#pragma once
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QTimer>
#include <QKeyEvent>
#include <string>
#include <memory>
#include "forme.h"
#include "lumiereposdir.hh"

class WidgetOGL : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit WidgetOGL(int fps = 0, QWidget *parent = 0, std::string type = "main", std::vector<LumierePos> ptr_lum = std::vector<LumierePos>(), std::vector<std::string> adr = std::vector<std::string>());
    ~WidgetOGL();

    void chargerTexture(std::string nomTexture);

    void ajouterForme(std::shared_ptr<forme> frm)
    { _formesAAfficher.push_back(frm); }

    void supprimerForme(std::string nom);

    void toutEffacer()
    { _formesAAfficher.clear(); }

    std::vector<std::shared_ptr<forme>> getFormeAfficher()
    { return _formesAAfficher; }

    void sauvegardeScene(std::string nomFichier);
    void chargementScene(std::string nomFichier);

    void dessinPicking();
    void etudeHit();

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent * keyEvent);
    void mousePressEvent(QMouseEvent* mouseEvent);

public slots:
    void timeOutSlot();
    void slotUpdate();
    /* Lumière ambiante */
    void setAmbianteR(int r);
    void setAmbianteV(int v);
    void setAmbianteB(int b);


    /* Camera */
    void setPosXCam(int x);
    void setPosYCam(int y);
    void setPosZCam(int z);

    void setAngXCam(int x);
    void setAngYCam(int y);
    void setAngZCam(int z);

    /* Lumière */
    void recepetionLumiereOGL(LumierePos lp)
    { _ensemble_lumiere.push_back(lp); }

    void changerLumiere(std::vector<LumierePos> vecLum)
    { _ensemble_lumiere = vecLum; }

signals:
    void formeChargee(std::shared_ptr<forme> ptr, QString nomParent);
    void fichierNonTrouve(std::string nomFichier);
    void formePick(unsigned int idForme);

private:
    std::string _type;
    QTimer * _timer;
    float _posxcam;
    float _posycam;
    float _poszcam;

    float _angxcam;
    float _angycam;
    float _angzcam;

    /* Lumières */
    float _ambianteR;
    float _ambianteV;
    float _ambianteB;

    std::vector<std::shared_ptr<forme>> _formesAAfficher;
    std::vector<LumierePos> _ensemble_lumiere;
    std::vector<std::string> _adressesTX;

    /* Picking */
    float _curseurX;
    float _curseurY;
    int _modeRendu;

    //

    static const int selectBufferSize = 100;
    std::vector<unsigned int> selectBuffer = std::vector<uint>(selectBufferSize);
};
