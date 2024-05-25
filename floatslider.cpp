#include "floatslider.h"
#include <QVBoxLayout>
#include<QDebug>
#include<QStyleOptionSlider>
#include<QDebug>
#include<QToolTip>
#include<QMouseEvent>
#include<QSlider>

FloatSlider::FloatSlider(QWidget *parent) : QWidget(parent)
{
    slider = new CircleTickSlider(Qt::Horizontal, this);
    slider->setTickPosition(QSlider::TicksBelow);
    slider->setStyleSheet(R"(QSlider::groove:horizontal {
                          height: 8px;
                          background: #FFFFFF;
                          border: 1px solid #999;
                          border-radius: 2px;
                      }
                      QSlider::handle:horizontal {
                          background: #F8F8FF;
                          border: 1px solid #999;
                          width: 10px;
                          height: 10px;
                          margin: -3px 0;
                          border-radius: 5px;
                      }
                      QSlider::handle:horizontal:hover {
                          background: #4a90e2;
                      }
                      QSlider::handle:horizontal:pressed {
                          background: #007bff;
                      }
                      QSlider::sub-page:horizontal {
                          background: #007bff;
                          border-radius: 4px;
                      })");


    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(slider);
    connect(slider, &CircleTickSlider::valueChanged, this, &FloatSlider::updateValue);
}

void FloatSlider::setRange(float min, float max)
{
    slider->setRange(0, 100);
    this->minFloat = min;
    this->maxFloat = max;
    this->slider->setBase(min);
}

void FloatSlider::setStep(float step)
{
    this->stepFloat = step;
    this->slider->setStep(step);
}


void FloatSlider::setValue(float value)
{
    this->slider->setValue((value - minFloat) * 10);
}

void FloatSlider::updateValue(int value)
{
    emit changeValue(minFloat + value * stepFloat);
}
