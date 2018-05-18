#include "popup_lum.hh"

PopUpLumiere::PopUpLumiere()
{
    setFixedSize(250, 200);

    _layoutPrincipal = new QGridLayout(this);

    _typePos = new QRadioButton("Positionnelle", this);
    _typeDir = new QRadioButton("Directionnelle", this);

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

    _typePos->setChecked(true);

    _layoutPrincipal->addWidget(_typePos, 0, 0, 1, 1);
    _layoutPrincipal->addWidget(_typeDir, 1, 0, 1, 1);
    _layoutPrincipal->addWidget(_name_lp, 2, 0, 1, 1);
    _layoutPrincipal->addWidget(_le_name_lp, 2, 1, 1, 1);
    _layoutPrincipal->addWidget(_posX_popup, 3, 0, 1, 1);
    _layoutPrincipal->addWidget(_le_posX, 3, 1, 1, 1);
    _layoutPrincipal->addWidget(_posY_popup, 4, 0, 1, 1);
    _layoutPrincipal->addWidget(_le_posY, 4, 1, 1, 1);
    _layoutPrincipal->addWidget(_posZ_popup, 5, 0, 1, 1);
    _layoutPrincipal->addWidget(_le_posZ, 5, 1, 1, 1);
    _layoutPrincipal->addWidget(_create_lp, 6, 0, 1, 1);
    _layoutPrincipal->addWidget(_cancel_lp, 6, 1, 1, 1);

    QObject::connect(_cancel_lp, &QPushButton::clicked, this, &PopUpLumiere::OnClicCancel);
    QObject::connect(_create_lp, &QPushButton::clicked, this, &PopUpLumiere::OnClicCreate);
}

PopUpLumiere::~PopUpLumiere()
{}

void PopUpLumiere::OnClicCancel()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cancel", "Voulez-vous annuler la création de la nouvelle lumière positionnelle/directionnelle ?", (QMessageBox::No | QMessageBox::Yes));
    if (reply == QMessageBox::Yes)
        this->close();
}

void PopUpLumiere::OnClicCreate()
{
    bool okX;
    int X = _le_posX->text().toInt(&okX, 10);
    bool okY;
    int Y = _le_posY->text().toInt(&okY, 10);
    bool okZ;
    int Z = _le_posZ->text().toInt(&okZ, 10);

    if (okX && okY && okZ && X >= -10 && X <= 10 && Y >= -10 && Y <= 10 && Z >= -10 && Z <= 10 && !_le_name_lp->text().isEmpty() && !_le_posX->text().isEmpty() && !_le_posY->text().isEmpty() && !_le_posZ->text().isEmpty())
    {
        if (_typePos->isChecked())
        {
            LumierePos pos(true, _le_name_lp->text().toStdString(), X, Y, Z);
            emit lumiereCreee(pos);
            this->close();
        }
        else
        {
            LumierePos dir(false, _le_name_lp->text().toStdString(), X, Y, Z);
            emit lumiereCreee(dir);
            this->close();
        }
    }
    else
        QMessageBox::warning(this, "Error", "Une ou plusieurs des valeurs entrées n'est pas du bon type, mal renseignée ou excède les bornes autorisées. Veuillez recommencer.");
}
