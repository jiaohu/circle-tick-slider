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
    void setValue(float value);

public slots:
    void updateValue(int value);
signals:
    void changeValue(float);

public:
    CircleTickSlider *slider;
private:
    float minFloat;
    float maxFloat;
    float stepFloat;
};

#endif // FLOATSLIDER_H
