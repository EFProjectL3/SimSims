#pragma once
#include <QtWidgets>

class LabelClic:
        public QLabel
{
    Q_OBJECT

public:
    LabelClic(QWidget * parent, unsigned int id);
    ~LabelClic();

    void mousePressEvent(QMouseEvent * event);

signals:
    void clicked(unsigned int val);

private:
    unsigned int _idLabel;
};
