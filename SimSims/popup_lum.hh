#pragma once
#include <QtWidgets>
#include "lumiereposdir.hh"

class PopUpLumiere:
        public QWidget
{
    Q_OBJECT

public:
    PopUpLumiere();
    ~PopUpLumiere();

    QPushButton * _create_lpd;
    QPushButton * _cancel_lpd;

public slots:
    void OnClicCreate();
    void OnClicCancel();

signals:
    void lumiereCreee(LumierePos lpd);

private:
    QGridLayout * _layoutPrincipal;

    QRadioButton * _typePos;
    QRadioButton * _typeDir;

    QLabel * _name_lpd;
        QLineEdit * _le_name_lpd;

    QLabel * _posDirX_popup;
        QLineEdit * _le_posDirX;

    QLabel * _posDirY_popup;
        QLineEdit * _le_posDirY;

    QLabel * _posDirZ_popup;
        QLineEdit * _le_posDirZ;
};
