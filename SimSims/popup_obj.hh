#pragma once
#include <QtWidgets>
#include <widgetOGL.h>

class PopUpObjet:
        public QWidget
{
    Q_OBJECT

public:
    PopUpObjet();
    ~PopUpObjet();

    QPushButton * _create_obj;
    QPushButton * _cancel_obj;

public slots:
    void OnClicCancel();
    void OnClicCreate();

private:
    QGridLayout * _layoutPrincipal;
        QGridLayout * _layoutObjetPopup;
                QComboBox * _selectForm;

            QLabel * _name_obj;
                QLineEdit * _le_name_obj;

            QLabel * _taille_obj_popup;
                QLabel * _attribut1;
                    QLineEdit * _le_attribut1;

                QLabel * _attribut2;
                    QLineEdit * _le_attribut2;

                QLabel * _attribut3;
                    QLineEdit * _le_attribut3;

        WidgetOGL * _affichage_popup;
};
