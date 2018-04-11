#include "popup_lum.hh"

PopUpLumiere::PopUpLumiere()
{
    setFixedSize(250, 175);

    _layoutPrincipal = new QGridLayout(this);

        _name_lp = new QLabel("Nom : ", this);
            _le_name_lp = new QLineEdit(this);
            _le_name_lp->setMaximumWidth(150);

        _posX_popup = new QLabel(" PosX : ", this);
            _le_posX = new QLineEdit(this);
            _le_posX->setMaximumWidth(150);

        _posY_popup = new QLabel(" PosY : ", this);
            _le_posY = new QLineEdit(this);
            _le_posY->setMaximumWidth(150);

        _posZ_popup = new QLabel(" PosZ : ", this);
            _le_posZ = new QLineEdit(this);
            _le_posZ->setMaximumWidth(150);

        _create_lp = new QPushButton("Créer", this);
        _cancel_lp = new QPushButton("Annuler", this);


    _layoutPrincipal->addWidget(_name_lp, 0, 0, 1, 1);
    _layoutPrincipal->addWidget(_le_name_lp, 0, 1, 1, 1);
    _layoutPrincipal->addWidget(_posX_popup, 1, 0, 1, 1);
    _layoutPrincipal->addWidget(_le_posX, 1, 1, 1, 1);
    _layoutPrincipal->addWidget(_posY_popup, 2, 0, 1, 1);
    _layoutPrincipal->addWidget(_le_posY, 2, 1, 1, 1);
    _layoutPrincipal->addWidget(_posZ_popup, 3, 0, 1, 1);
    _layoutPrincipal->addWidget(_le_posZ, 3, 1, 1, 1);
    _layoutPrincipal->addWidget(_create_lp, 4, 0, 1, 1);
    _layoutPrincipal->addWidget(_cancel_lp, 4, 1, 1, 1);

    QObject::connect(_cancel_lp, &QPushButton::clicked, this, &PopUpLumiere::OnClicCancel);
    QObject::connect(_create_lp, &QPushButton::clicked, this, &PopUpLumiere::OnClicCreate);
}

PopUpLumiere::~PopUpLumiere()
{}

void PopUpLumiere::OnClicCancel()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cancel", "Voulez-vous annuler la création de la nouvelle lumière positionnelle ?", (QMessageBox::No | QMessageBox::Yes));
    if (reply == QMessageBox::Yes)
        this->close();
}

void PopUpLumiere::OnClicCreate()
{
    /* A compléter avec la partie de Bastien */
    this->close();

}
