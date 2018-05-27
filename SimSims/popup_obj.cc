#include "popup_obj.hh"
#include <memory>
#include <fstream>
#include <iostream>
#include "forme.h"
#include "lectureDoc.h"
#include "mainwindow.h"

unsigned int PopUpObjet::idFormePopup = 0;

PopUpObjet::PopUpObjet(std::vector<std::string> noms, std::vector<std::shared_ptr<forme>> objets) : NOM_DES_FORMES_POPUP(noms), TOUS_LES_OBJETS_POPUP(objets)
{
    _idFPopup = idFormePopup++;

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

    _name_parent = new QLabel("Parent : ",this);
    _selectParent = new QComboBox(this);
    _selectParent->addItem("Aucun");
    for (unsigned int i(0); i<TOUS_LES_OBJETS_POPUP.size(); i++)
        _selectParent->addItem(QString::fromStdString(TOUS_LES_OBJETS_POPUP[i]->getNomForme()));
    _selectParent->setMaximumWidth(150);


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
    _layoutObjetPopup->addWidget(_name_parent, 1, 0, 1, 1);
    _layoutObjetPopup->addWidget(_selectParent, 1, 1, 1, 2);
    _layoutObjetPopup->addWidget(_name_obj, 2, 0, 1, 1);
    _layoutObjetPopup->addWidget(_le_name_obj, 2, 1, 1, 2);
    _layoutObjetPopup->addWidget(_taille_obj_popup, 3, 0, 1, 1);
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
    _layoutObjetPopup->addWidget(_attribut1, 4, 1, 1, 1);
    _layoutObjetPopup->addWidget(_le_attribut1, 4, 2, 1, 1);
    _layoutObjetPopup->addWidget(_attribut2, 5, 1, 1, 1);
    _layoutObjetPopup->addWidget(_le_attribut2, 5, 2, 1, 1);
    _layoutObjetPopup->addWidget(_attribut3, 6, 1, 1, 1);
    _layoutObjetPopup->addWidget(_le_attribut3, 6, 2, 1, 1);


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
}

PopUpObjet::~PopUpObjet()
{}

void PopUpObjet::OnClicCancel()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cancel", "Voulez-vous annuler la création du nouvel objet ?"
                                                  "(Tous les descendants seront aussi supprimés.)", (QMessageBox::No | QMessageBox::Yes));
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
    bool okX;
    int X = _le_attribut1->text().toFloat(&okX);
    bool okY;
    int Y = _le_attribut2->text().toFloat(&okY);
    bool okZ;
    int Z = _le_attribut3->text().toFloat(&okZ);
    bool okNom = true;
    unsigned int i(0);
    if (_le_name_obj->text().isEmpty()) //en premier on vérifier que le nom n'est pas vide
        okNom = false;
    while (okNom == true && i<TOUS_LES_OBJETS_POPUP.size())  //Si ce n'est pas le cas, on vérifie que le nom n'est pas déjà pris
    {
        if (TOUS_LES_OBJETS_POPUP[i]->getNomForme() ==  _le_name_obj->text().toStdString())
            okNom = false;
        i++;
    }

    if (okX && okY && okZ && okNom && X >= 0 && Y >= 0 && Z >= 0 && Z <= 10 && !_le_attribut1->text().isEmpty() && !_le_attribut2->text().isEmpty() && !_le_attribut3->text().isEmpty())
    {
        unsigned int j(0);
        bool fini = false;
        std::string nomObjet;
        QString parent = "Aucun";
        std::vector<float> attributs;
        std::shared_ptr<forme> ptrForme;
        while (fini == false)
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
                ptrForme->setNomForme(nomObjet);
                ptrForme->setId(_idFPopup);
                parent = _selectParent->currentText();
                fini = true;
            }
            j++;
        }
        emit creationObjet(ptrForme, parent);

        this->close();
    }
    else
        QMessageBox::warning(this, "Error", "Une ou plusieurs des valeurs entrées n'est pas du bon type, mal renseignée ou excède les bornes autorisées. Veuillez recommencer.");
}
