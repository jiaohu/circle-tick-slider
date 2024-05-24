#ifndef FLOATSLIDER_H
#define FLOATSLIDER_H

#include <QWidget>
#include<QSlider>
#include <QLabel>
#include "circletickslider.h"

class FloatSlider : public QWidget
{
    Q_OBJECT
public:
    explicit FloatSlider(QWidget *parent = nullptr);
    void setRange(float min, float max);
    void setStep(float step);

private:
    void updateLabel(int value);
public:
    CircleTickSlider *slider;
private:

    QLabel *label;
    float minFloat;
    float maxFloat;
    float stepFloat;
};

#endif // FLOATSLIDER_H
