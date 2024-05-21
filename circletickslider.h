#ifndef CIRCLETICKSLIDER_H
#define CIRCLETICKSLIDER_H

#include<QSlider>
#include<QEvent>

class CircleTickSlider : public QSlider
{
public:
    CircleTickSlider(QWidget *parent = nullptr);
    CircleTickSlider(Qt::Orientation orientation, QWidget *parent = nullptr);

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
};

#endif // CIRCLETICKSLIDER_H
