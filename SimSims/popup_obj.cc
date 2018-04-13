#include "popup_obj.hh"
#include <memory>
#include <fstream>
#include <iostream>
#include "forme.h"
#include "lectureDoc.h"
#include "mainwindow.h"


PopUpObjet::PopUpObjet(std::vector<std::string> noms) : NOM_DES_FORMES_POPUP(noms)
{
    _idFormePopup = 75000;

    setFixedSize(600, 250);

    _layoutPrincipal = new QGridLayout(this);

    _layoutObjetPopup = new QGridLayout();
    _affichage_popup = new WidgetOGL(60,this,"popup");
    /* Creation forme initiale */
    char * fichierDonnees = "./FICHIER_DE_DONNEES";
    float longueur = 1;
    float largeur = 1;
    float hauteur = 1;
    std::vector<float> attribut;
    for (unsigned int i(0); i<24; i++)
    {
        attribut.push_back(longueur);
        attribut.push_back(hauteur);
        attribut.push_back(largeur);

        i++;
        i++;
    }
    std::shared_ptr<forme> ptrForme;
    ptrForme = creerFormesLecture(fichierDonnees,1,attribut);
    _affichage_popup->ajouterForme(ptrForme);
    /**************************/
    _affichage_popup->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    _selectForm = new QComboBox(this);
    for (unsigned int i(0); i<NOM_DES_FORMES_POPUP.size(); i++)
        _selectForm->addItem(QString::fromStdString(NOM_DES_FORMES_POPUP[i]));
    _selectForm->setMaximumWidth(150);

    _name_obj = new QLabel("Nom : ", this);
    _le_name_obj = new QLineEdit(this);
    _le_name_obj->setMaximumWidth(150);

    _taille_obj_popup = new QLabel("Taille", this);
    _taille_obj_popup->setMaximumSize(150, 26);
    _attribut1 = new QLabel("Taille X : ", this);
    _le_attribut1 = new QLineEdit("1", this);
    _le_attribut1->setMaximumWidth(150);

    _attribut2 = new QLabel("Taille Y : ", this);
    _le_attribut2 = new QLineEdit("1", this);
    _le_attribut2->setMaximumWidth(150);

    _attribut3 = new QLabel("Taille Z : ", this);
    _le_attribut3 = new QLineEdit("1", this);
    _le_attribut3->setMaximumWidth(150);

    _create_obj = new QPushButton("Créer", this);
    _cancel_obj = new QPushButton("Annuler", this);


    _layoutObjetPopup->addWidget(_selectForm, 0, 1, 1, 3);
    _layoutObjetPopup->addWidget(_name_obj, 1, 0, 1, 1);
    _layoutObjetPopup->addWidget(_le_name_obj, 1, 1, 1, 2);
    _layoutObjetPopup->addWidget(_taille_obj_popup, 2, 0, 1, 1);

    /*
         *
         *
         *
         * A REBOSSER !!!!!!!!!
         *
         *
         *
         *
         * */
    _layoutObjetPopup->addWidget(_attribut1, 3, 1, 1, 1);
    _layoutObjetPopup->addWidget(_le_attribut1, 3, 2, 1, 1);
    _layoutObjetPopup->addWidget(_attribut2, 4, 1, 1, 1);
    _layoutObjetPopup->addWidget(_le_attribut2, 4, 2, 1, 1);
    _layoutObjetPopup->addWidget(_attribut3, 5, 1, 1, 1);
    _layoutObjetPopup->addWidget(_le_attribut3, 5, 2, 1, 1);


    _layoutPrincipal->addWidget(_create_obj, 1, 0, 1, 1);
    _layoutPrincipal->addWidget(_cancel_obj, 1, 1, 1, 1);

    _layoutPrincipal->addLayout(_layoutObjetPopup, 0, 0, 1, 1);
    _layoutPrincipal->addWidget(_affichage_popup, 0, 1, 1, 1);

    QObject::connect(_cancel_obj, &QPushButton::clicked, this, &PopUpObjet::OnClicCancel);
    QObject::connect(_create_obj, &QPushButton::clicked, this, &PopUpObjet::OnClicCreate);
    QObject::connect(_selectForm, &QComboBox::currentTextChanged, this, &PopUpObjet::AffichagePopup);
    QObject::connect(_le_attribut1, &QLineEdit::textChanged, this, &PopUpObjet::AffichagePopup);
    QObject::connect(_le_attribut2, &QLineEdit::textChanged, this, &PopUpObjet::AffichagePopup);
    QObject::connect(_le_attribut3, &QLineEdit::textChanged, this, &PopUpObjet::AffichagePopup);
    QObject::connect(this,&PopUpObjet::pretPourUpdate,_affichage_popup,&WidgetOGL::slotUpdate);
}

PopUpObjet::~PopUpObjet()
{}

void PopUpObjet::OnClicCancel()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cancel", "Voulez-vous annuler la création du nouvel objet ?", (QMessageBox::No | QMessageBox::Yes));
    if (reply == QMessageBox::Yes)
        this->close();
}

void PopUpObjet::AffichagePopup(QString text)
{
    unsigned int j(0);
    while (j<NOM_DES_FORMES_POPUP.size())
    {
        if (_selectForm->currentText() == QString::fromStdString(NOM_DES_FORMES_POPUP[j]))
        {
            _affichage_popup->toutEffacer();
            std::vector<float> attributs;
            attributs.clear();

            char * fichierDonnees = "./FICHIER_DE_DONNEES";

            for (int i(0); i<nombreAttributForme(fichierDonnees,j+1); i+=3)
            {
                float longueur = _le_attribut1->text().toFloat();
                float largeur = _le_attribut2->text().toFloat();
                float hauteur = _le_attribut3->text().toFloat();
                attributs.push_back(longueur);
                attributs.push_back(hauteur);
                attributs.push_back(largeur);
            }

            std::shared_ptr<forme> ptrForme;
            ptrForme = creerFormesLecture(fichierDonnees,j+1,attributs);

            _affichage_popup->ajouterForme(ptrForme);
        }
        j++;
    }
}

void PopUpObjet::OnClicCreate()
{
    unsigned int j(0);
    bool fini = false;
    std::string nomObjet;
    std::vector<float> attributs;
    std::shared_ptr<forme> ptrForme;
    while ((j<NOM_DES_FORMES_POPUP.size()) && (fini == false))
    {
        if (_selectForm->currentText() == QString::fromStdString(NOM_DES_FORMES_POPUP[j]))
        {
            char * fichierDonnees = "./FICHIER_DE_DONNEES";

            for (int i(0); i<nombreAttributForme(fichierDonnees,j+1); i+=3)
            {
                float longueur = _le_attribut1->text().toFloat();
                float largeur = _le_attribut2->text().toFloat();
                float hauteur = _le_attribut3->text().toFloat();
                attributs.push_back(longueur);
                attributs.push_back(hauteur);
                attributs.push_back(largeur);
            }

            nomObjet = _le_name_obj->text().toStdString();
            ptrForme = creerFormesLecture(fichierDonnees,j+1,attributs);
            fini = true;
        }
    }
    emit creationObjet(nomObjet, ptrForme);
    this->close();
}
