#include "popup_text.hh"

PopUpTexture::PopUpTexture(std::vector<std::string> i) : _textures(i)
{
    setFixedSize(700, 150);

    _layoutTextures = new QGridLayout(this);

    for (unsigned int i(0); i < _textures.size(); i++)
    {
        LabelClic * lImText = new LabelClic(this, i);
        QPixmap imageTX = QPixmap(QString::fromStdString(_textures[i]));
        imageTX = imageTX.scaled(90, 90, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        lImText->setPixmap(imageTX);
        lImText->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

        _imagesTX.push_back(lImText);
    }

    for (unsigned int i(0); i < _textures.size(); i++)
    {
        _layoutTextures->addWidget(_imagesTX[i], 0, i, 1, 1);
    }

        _cancel = new QPushButton("Annuler");
        _layoutTextures->addWidget(_cancel, 1, _textures.size()-1, 1, 1);

    for (unsigned int t(0); t<_imagesTX.size(); t++)
            QObject::connect(_imagesTX[t], &LabelClic::clicked, this, &PopUpTexture::OnClicApply);
    QObject::connect(_cancel, &QPushButton::clicked, this, &PopUpTexture::OnClicCancel);
}

PopUpTexture::~PopUpTexture()
{}

void PopUpTexture::OnClicCancel()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Cancel", "Voulez-vous annuler lapplication de la nouvelle texture ?", (QMessageBox::No | QMessageBox::Yes));
    if (reply == QMessageBox::Yes)
        this->close();
}

void PopUpTexture::OnClicApply(unsigned int idrecu)
{
    emit textureAppliquee(idrecu);
    this->close();
}
