#include "popup_obj.hh"

PopUpObjet::PopUpObjet()
{
    setFixedSize(600, 250);

    _layoutPrincipal = new QGridLayout(this);

    _layoutObjetPopup = new QGridLayout();
    _affichage_popup = new WidgetOGL();
    _affichage_popup->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


        _selectForm = new QComboBox(this);
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
}

PopUpObjet::~PopUpObjet()
{}

void PopUpObjet::OnClicCancel()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cancel", "Voulez-vous annuler la création de la nouvelle lumière positionnelle ?", (QMessageBox::No | QMessageBox::Yes));
    if (reply == QMessageBox::Yes)
        this->close();
}

void PopUpObjet::OnClicCreate()
{
    /* A compléter avec la partie de Bastien */
    this->close();
}
