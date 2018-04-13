#pragma once
#include <QtWidgets>
#include <widgetOGL.h>

class PopUpObjet:
        public QWidget
{
    Q_OBJECT

public:
    PopUpObjet(std::vector<std::string> noms);
    ~PopUpObjet();

    QPushButton * _create_obj;
    QPushButton * _cancel_obj;

public slots:
    void OnClicCancel();
    void OnClicCreate();
    void AffichagePopup(QString text);

signals:
    void pretPourUpdate();

    void creationObjet(std::string nomObj, std::shared_ptr<forme> ptr);

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

        unsigned int _idFormePopup;

        std::vector<std::string> NOM_DES_FORMES_POPUP;
};
