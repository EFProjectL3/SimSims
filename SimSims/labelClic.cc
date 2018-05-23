#include "labelClic.hh"

//Debug
#include <iostream>

LabelClic::LabelClic(QWidget *parent, unsigned int id) : QLabel(parent), _idLabel(id)
{}

LabelClic::~LabelClic()
{}

void LabelClic::mousePressEvent(QMouseEvent *event)
{
    emit clicked(_idLabel);
}
