#pragma once
#include <QtWidgets>
#include "labelClic.hh"

class PopUpTexture:
        public QWidget
{
    Q_OBJECT

public:
    PopUpTexture(std::vector<std::string> i);
    ~PopUpTexture();

public slots:
    void OnClicApply(unsigned int idrecu);
    void OnClicCancel();

signals:
    void textureAppliquee(unsigned int idrecu);

private:
    QGridLayout * _layoutTextures;
        QPushButton * _cancel;

    std::vector<std::string> _textures;
    std::vector<LabelClic*> _imagesTX;
};
