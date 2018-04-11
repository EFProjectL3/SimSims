#pragma once
#include <QtWidgets>

class PopUpLumiere:
        public QWidget
{
    Q_OBJECT

public:
    PopUpLumiere();
    ~PopUpLumiere();

    QPushButton * _create_lp;
    QPushButton * _cancel_lp;

public slots:
    void OnClicCreate();
    void OnClicCancel();

private:
    QGridLayout * _layoutPrincipal;
    QLabel * _name_lp;
        QLineEdit * _le_name_lp;

    QLabel * _posX_popup;
        QLineEdit * _le_posX;

    QLabel * _posY_popup;
        QLineEdit * _le_posY;

    QLabel * _posZ_popup;
        QLineEdit * _le_posZ;
};
