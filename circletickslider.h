#ifndef CIRCLETICKSLIDER_H
#define CIRCLETICKSLIDER_H

#include<QSlider>
#include<QEvent>

class CircleTickSlider : public QSlider
{
public:
    CircleTickSlider(QWidget *parent = nullptr);
    CircleTickSlider(Qt::Orientation orientation, QWidget *parent = nullptr);
    /**
     * @brief setBase used for float slider to set base value(min value)
     * @param base
     */
    void setBase(float base);
    /**
     * @brief setStep used for float slider to set step
     * @param step
     */
    void setStep(float step);

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);

    // QObject interface
public:
    bool eventFilter(QObject *watched, QEvent *event);

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    float base;
    float step;
};

#endif // CIRCLETICKSLIDER_H
