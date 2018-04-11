#include "popup_obj.hh"
#include <memory>
#include <fstream>
#include <iostream>
#include "forme.h"


extern std::vector<std::shared_ptr<forme>> TOUTES_LES_FORMES;
extern std::vector<QOpenGLTexture *> TOUTES_LES_TEXTURES;
extern std::vector<std::string> NOM_DES_FORMES;

PopUpObjet::PopUpObjet()
{
    _idFormePopup = 75000;

    setFixedSize(600, 250);

    _layoutPrincipal = new QGridLayout(this);

    _layoutObjetPopup = new QGridLayout();
    _affichage_popup = new WidgetOGL(60,this,"popup");
    _affichage_popup->ajouterForme(TOUTES_LES_FORMES[0]);
    _affichage_popup->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    _selectForm = new QComboBox(this);
    for (unsigned int i(0); i<NOM_DES_FORMES.size(); i++)
        _selectForm->addItem(QString::fromStdString(NOM_DES_FORMES[i]));
    _selectForm->setMaximumWidth(150);

    _name_obj = new QLabel("Nom : ", this);
    _le_name_obj = new QLineEdit(this);
    _le_name_obj->setMaximumWidth(150);

    _taille_obj_popup = new QLabel("Taille", this);
    _taille_obj_popup->setMaximumSize(150, 26);
    _attribut1 = new QLabel("Attribut 1 : ", this);
    _le_attribut1 = new QLineEdit("1", this);
    _le_attribut1->setMaximumWidth(150);

    _attribut2 = new QLabel("Attribut 2 : ", this);
    _le_attribut2 = new QLineEdit("1", this);
    _le_attribut2->setMaximumWidth(150);

    _attribut3 = new QLabel("Attribut 3 : ", this);
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
    QObject::connect(_selectForm, &QComboBox::currentTextChanged, this, &PopUpObjet::EcritureAffichagePopup);
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

void PopUpObjet::EcritureAffichagePopup(QString text)
{
    std::cout << "TEST ICI" << std::endl;
    unsigned int j(0);
    //bool trouve = false;
    while (j<NOM_DES_FORMES.size())
    {
        if (text == QString::fromStdString(NOM_DES_FORMES[j]))
        {
            std::cout << "Test là" << std::endl;
            _affichage_popup->toutEffacer();
            if (text.toStdString() == "CUBE")
            {
                std::cout << "Je suis là" << std::endl;
                /* Copie de la forme de base, afin de ne pas juste faire pointer les pointeurs vers les tableaux initiaux */
                int ** facesCons = new int*[100];  //correspond au tableau de construction des faces
                for(int i(0); i < 100; i++)
                { facesCons[i] = new int[3]; }
                std::cout << "Je suis là0" << std::endl;
                for (int i(0); i<100; i++)
                {
                    for (int k(0); k<3; k++)
                    {
                        if (i<TOUTES_LES_FORMES[j]->getNbrFace())
                            facesCons[i][k] = TOUTES_LES_FORMES[j]->getFaceConstruction()[i][k];
                        else
                            facesCons[i][k] = 0;
                        std::cout << "Initiale[" << i << "][" << k << "] : " << TOUTES_LES_FORMES[j]->getFaceConstruction()[i][k] << std::endl;
                        std::cout << "FaceCons[" << i << "][" << k << "] : " << facesCons[i][k] << std::endl;
                    }
                }
                std::cout << "Je suis là1" << std::endl;
                sommet * somTmp = new sommet [50];
                for (int i(0); i<TOUTES_LES_FORMES[j]->getNbrSommet(); i++)
                    somTmp[i] = TOUTES_LES_FORMES[j]->getSommets()[i];
                std::cout << "Je suis là2" << std::endl;
                face * facTmp = new face [50];     //tableau de faces
                for (int i(0); i<TOUTES_LES_FORMES[j]->getNbrFace(); i++)
                    facTmp[i] = TOUTES_LES_FORMES[j]->getFaces()[i];
                /******************************************************************************/
                std::cout << "Je suis là3" << std::endl;
                auto formePtr = std::make_shared<forme>(
                            _idFormePopup,
                            TOUTES_LES_FORMES[j]->getNbrFace(),
                            TOUTES_LES_FORMES[j]->getNbrSommet(),
                            TOUTES_LES_FORMES[j]->getNbrAtt(),
                            TOUTES_LES_FORMES[j]->getnbrSommetsParFaceMax(),
                            facesCons,
                            somTmp,
                            facTmp,
                            TOUTES_LES_FORMES[j]->getAttributs());
                std::cout << "Je suis là4" << std::endl;
                std::vector<float> test;
                test.push_back(4);
                test.push_back(2);
                std::cout << "Je suis là5" << std::endl;
                formePtr->setAttribut(test);
                std::cout << "Je suis là6" << std::endl;
                formePtr->infoForme();

                std::cout << "FINI0?" << std::endl;
                _affichage_popup->ajouterForme(formePtr);
                std::cout << "FINI?" << std::endl;
            }
            //_affichage_popup->
            /*
            std::cout << "COMBO: " << text.toStdString() << std::endl;
            std::cout << "NOM FORME: " << NOM_DES_FORMES[j] << std::endl;
            std::ifstream fichier("../SimSims/affichage.cpp",std::ios::in);  // Flux de lecture
            std::ofstream flux("../SimSims/affichageTmp.cpp", std::ios::out); // Flux d'ecriture

            if(fichier) // Si le fichier existe bien
            {
                std::string ligne;
                while(getline(fichier, ligne)) // On le lis ligne par ligne
                {

                    if(flux) // Si le lieu de destination existe
                    {
                        if (trouve == false)
                            flux << ligne << std::endl; // On ecrit dans le fichier de destination
                        if (trouve == true)
                        {
                            trouve = false;
                            std::cout << "ICI J EST EGAL A " << j << std::endl;
                            flux << "TOUTES_LES_FORMES[" << j <<"]->afficher_forme(); \n";
                        }
                        if (ligne == "//DebutAffichagePopup")
                            trouve=true;
                    }
                    else
                    {
                        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
                    }

                }
                remove("../SimSims/affichage.cpp");
                rename("../SimSims/affichageTmp.cpp", "../SimSims/affichage.cpp");
                *
                 *
                 *
                 *
                 *
                 *
                 *
                 *      ICI
                 *
                 *
                 *
                 *
                 *
                 *
                 *
                 * */
            /* Test pour réinitialiser le popup *
                delete _affichage_popup;
                _affichage_popup = new WidgetOGL(60,this,"popup");
                _affichage_popup->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                _layoutPrincipal->addWidget(_affichage_popup, 0, 1, 1, 1);

                emit pretPourUpdate();
            }
            else
            {
                std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
            }*/
        }
        j++;
    }
}

void PopUpObjet::OnClicCreate()
{
    /* A compléter avec la partie de Bastien */
    this->close();
}
