#include "circletickslider.h"
#include<QStyleOptionSlider>
#include<QPainter>
#include<QDebug>
#include<QToolTip>
#include<QMouseEvent>


CircleTickSlider::CircleTickSlider(QWidget *parent) : QSlider(parent)
{
    setMouseTracking(true);
    installEventFilter(this);
    setTickPosition(QSlider::TicksBelow);
}

CircleTickSlider::CircleTickSlider(Qt::Orientation orientation, QWidget *parent) : QSlider(orientation, parent)
{
    setMouseTracking(true);
    installEventFilter(this);
    setTickPosition(QSlider::TicksBelow);
}

void CircleTickSlider::setFloat(float base, float step)
{
    this->base = base;
    this->step = step;
}

void CircleTickSlider::paintEvent(QPaintEvent *event)
{
    QSlider::paintEvent(event);

    QStyleOptionSlider opt;
    initStyleOption(&opt);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    const int _tickInterval = tickInterval() > 0 ? tickInterval() : pageStep();
    const int _tickCount = (maximum() - minimum()) / _tickInterval + 1;



    for (int i = 0; i < _tickCount; ++i) {
        if (i == 0 || i == _tickCount - 1) {
            continue;
        }
        double ratio = i / double(_tickCount - 1);
        int x = opt.rect.left() + ratio * opt.rect.width();
        int y = opt.rect.center().y(); // Adjust y as needed for your tick position

        painter.setBrush(Qt::white);
        painter.setPen(Qt::black);
        painter.drawEllipse(QPointF(x, y), 4, 4); // Draw circles with radius 4
    }

}

bool CircleTickSlider::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == this && event->type() == QEvent::MouseMove) {

        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        int value = QStyle::sliderValueFromPosition(minimum(), maximum(), mouseEvent->pos().x(), width());
        QToolTip::showText(mouseEvent->globalPos(), QString::number(value * step + base), this);
    }
    return QSlider::eventFilter(watched, event);
}

void CircleTickSlider::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {

        int value = QStyle::sliderValueFromPosition(minimum(), maximum(), event->pos().x(), width());
        this->setValue(value);
    }

    QSlider::mousePressEvent(event);
}

void CircleTickSlider::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {

        int value = QStyle::sliderValueFromPosition(minimum(), maximum(), event->pos().x(), width());
        this->setValue(value);
    }

    QSlider::mouseReleaseEvent(event);
}
