#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QTimer>
#include <QKeyEvent>

class WidgetOGL : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit WidgetOGL(int fps = 0, QWidget *parent = 0);
    ~WidgetOGL();

    void chargerTexture(std::string nomTexture);



protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent * keyEvent);

public slots:
    void timeOutSlot();
    /* Lumière ambiante */
    void setAmbianteR(int r);
    void setAmbianteV(int v);
    void setAmbianteB(int b);


    /* Camera */
    void setPosXCam(int x);

private:
    QTimer * _timer;
    float xcam;
    float ycam;
    float zcam;

    /* Lumières */
    float _ambianteR;
    float _ambianteV;
    float _ambianteB;
};
