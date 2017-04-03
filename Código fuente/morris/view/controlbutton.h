#ifndef CONTROLBUTTON_H
#define CONTROLBUTTON_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QPropertyAnimation>

/*!
 * \class ControlButton
 *
 *  Allow to put buttons on the screen which responds to click events.
 *
 */
class ControlButton : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
    Q_PROPERTY(qreal scale READ scale WRITE setScale)
public:
    ControlButton( QPixmap image );

private:
    QPropertyAnimation * animator;

signals:
    /*!
     * Notify of a click event over the button
     */
    void clicked();

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent  *event);


};

#endif // CONTROLBUTTON_H
