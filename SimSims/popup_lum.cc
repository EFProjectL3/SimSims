#include "popup_lum.hh"

PopUpLumiere::PopUpLumiere()
{
    setFixedSize(350, 225);

    _layoutPrincipal = new QGridLayout(this);

    _typePos = new QRadioButton("Positionnelle", this);
    _typeDir = new QRadioButton("Directionnelle", this);

    _name_lpd = new QLabel("Nom : ", this);
    _le_name_lpd = new QLineEdit(this);
    _le_name_lpd->setMaximumWidth(150);

    _posDirX_popup = new QLabel("PosX ou DirX : ", this);
    _le_posDirX = new QLineEdit(this);
    _le_posDirX->setMaximumWidth(150);

    _posDirY_popup = new QLabel("PosY ou DirY : ", this);
    _le_posDirY = new QLineEdit(this);
    _le_posDirY->setMaximumWidth(150);

    _posDirZ_popup = new QLabel("PosZ ou DirZ : ", this);
    _le_posDirZ = new QLineEdit(this);
    _le_posDirZ->setMaximumWidth(150);

    _create_lpd = new QPushButton("Créer", this);
    _cancel_lpd = new QPushButton("Annuler", this);

    _typePos->setChecked(true);

    _layoutPrincipal->addWidget(_typePos, 0, 0, 1, 1);
    _layoutPrincipal->addWidget(_typeDir, 1, 0, 1, 1);
    _layoutPrincipal->addWidget(_name_lpd, 2, 0, 1, 1);
    _layoutPrincipal->addWidget(_le_name_lpd, 2, 1, 1, 1);
    _layoutPrincipal->addWidget(_posDirX_popup, 3, 0, 1, 1);
    _layoutPrincipal->addWidget(_le_posDirX, 3, 1, 1, 1);
    _layoutPrincipal->addWidget(_posDirY_popup, 4, 0, 1, 1);
    _layoutPrincipal->addWidget(_le_posDirY, 4, 1, 1, 1);
    _layoutPrincipal->addWidget(_posDirZ_popup, 5, 0, 1, 1);
    _layoutPrincipal->addWidget(_le_posDirZ, 5, 1, 1, 1);
    _layoutPrincipal->addWidget(_create_lpd, 6, 0, 1, 1);
    _layoutPrincipal->addWidget(_cancel_lpd, 6, 1, 1, 1);

    QObject::connect(_cancel_lpd, &QPushButton::clicked, this, &PopUpLumiere::OnClicCancel);
    QObject::connect(_create_lpd, &QPushButton::clicked, this, &PopUpLumiere::OnClicCreate);
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
    int X = _le_posDirX->text().toInt(&okX, 10);
    bool okY;
    int Y = _le_posDirY->text().toInt(&okY, 10);
    bool okZ;
    int Z = _le_posDirZ->text().toInt(&okZ, 10);

    if (okX && okY && okZ && X >= -10 && X <= 10 && Y >= -10 && Y <= 10 && Z >= -10 && Z <= 10 && !_le_name_lpd->text().isEmpty() && !_le_posDirX->text().isEmpty() && !_le_posDirY->text().isEmpty() && !_le_posDirZ->text().isEmpty())
    {
        if (_typePos->isChecked())
        {
            LumierePos pos(true, _le_name_lpd->text().toStdString(), X, Y, Z);
            emit lumiereCreee(pos);
            this->close();
        }
        else
        {
            LumierePos dir(false, _le_name_lpd->text().toStdString(), X, Y, Z);
            emit lumiereCreee(dir);
            this->close();
        }
    }
    else
        QMessageBox::warning(this, "Error", "Une ou plusieurs des valeurs entrées n'est pas du bon type, mal renseignée ou excède les bornes autorisées. Veuillez recommencer.");
}
