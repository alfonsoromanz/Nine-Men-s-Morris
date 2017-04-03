#include "controlbutton.h"


ControlButton::ControlButton(QPixmap image)
{
    this->setPixmap( image );
    this->setOffset(-0.5 * QPoint(image.width(), image.height()) );
    this->setTransformationMode(Qt::SmoothTransformation);
}

void ControlButton::mousePressEvent(QGraphicsSceneMouseEvent  *event)
{
    animator = new QPropertyAnimation(this, "scale" );
    animator->setDuration( 250 );
    animator->setStartValue( 0.8 );
    animator->setEndValue( 1 );
    animator->setEasingCurve( QEasingCurve::OutElastic );
    animator->start( QPropertyAnimation::DeleteWhenStopped );
    clicked();
}
