#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QTimer>
#include <QKeyEvent>
#include <string>

class WidgetOGL : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit WidgetOGL(int fps = 0, QWidget *parent = 0, std::string type = "main");
    ~WidgetOGL();

    void chargerTexture(std::string nomTexture);



protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent * keyEvent);

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
};
