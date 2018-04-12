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
    float taillecube = 1;
    std::vector<float> attribut;
    attribut.push_back(taillecube);
    attribut.push_back(0.5*taillecube);
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
            if (j == 0)
            {
                attributs.push_back(_le_attribut1->text().toFloat());
                attributs.push_back(0.5*_le_attribut1->text().toFloat());
            }
            if (j == 1)
            {
                attributs.push_back(_le_attribut1->text().toFloat());
                attributs.push_back(_le_attribut2->text().toFloat());
                attributs.push_back(_le_attribut3->text().toFloat());
                attributs.push_back(0.5*_le_attribut1->text().toFloat());
                attributs.push_back(0.5*_le_attribut2->text().toFloat());
                attributs.push_back(0.5*_le_attribut3->text().toFloat());
                attributs.push_back(1.33*_le_attribut1->text().toFloat());
                attributs.push_back(1.33*_le_attribut2->text().toFloat());
                attributs.push_back(1.33*_le_attribut3->text().toFloat());
                attributs.push_back(1.4*_le_attribut1->text().toFloat());
                attributs.push_back(1.4*_le_attribut2->text().toFloat());
                attributs.push_back(1.4*_le_attribut3->text().toFloat());
                attributs.push_back(1.5*_le_attribut1->text().toFloat());
                attributs.push_back(1.5*_le_attribut2->text().toFloat());
                attributs.push_back(1.5*_le_attribut3->text().toFloat());
                attributs.push_back(1.75*_le_attribut1->text().toFloat());
                attributs.push_back(1.75*_le_attribut2->text().toFloat());
                attributs.push_back(1.75*_le_attribut3->text().toFloat());
                attributs.push_back(2.15*_le_attribut1->text().toFloat());
                attributs.push_back(2.15*_le_attribut2->text().toFloat());
                attributs.push_back(2.15*_le_attribut3->text().toFloat());
                attributs.push_back(2.5*_le_attribut1->text().toFloat());
                attributs.push_back(2.5*_le_attribut2->text().toFloat());
                attributs.push_back(2.5*_le_attribut3->text().toFloat());
            }

            char * fichierDonnees = "./FICHIER_DE_DONNEES";
            std::shared_ptr<forme> ptrForme;
            ptrForme = creerFormesLecture(fichierDonnees,j+1,attributs);
            _affichage_popup->ajouterForme(ptrForme);
        }
        j++;
    }
}

void PopUpObjet::OnClicCreate()
{
    bool ok1;
    int at1 = _le_attribut1->text().toInt(&ok1, 10);
    bool ok2;
    int at2 = _le_attribut2->text().toInt(&ok2, 10);
    bool ok3;
    int at3 = _le_attribut3->text().toInt(&ok3, 10);

    if (ok1 && ok2 && ok3)
    {
        Objet o(_le_name_obj->text().toStdString(), at1, at2, at3);
        emit objetCree(o);
        this->close();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Une ou plusieurs des valeurs entrées n'est pas du bon type. Veuillez recommencer.");
    }
}
