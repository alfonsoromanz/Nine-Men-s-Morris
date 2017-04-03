#ifndef PIECEITEM_H
#define PIECEITEM_H

#include <QGraphicsItem>
#include <QPropertyAnimation>

/*!
 * Displayable piece.
 */
class PieceItem : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(qreal scale READ scale WRITE setScale)
private:
    int color;
    QPixmap image;

public:
    explicit PieceItem( int color );
    void animateMove( QPropertyAnimation *pieceAnimation ,  int fromX, int fromY, int toX, int toY);
    void animateAppear( QPropertyAnimation *pieceAnimation );
    void animateDelete( QPropertyAnimation *pieceAnimation );

public slots:
    void onUpdateSelected( int id );
    void onDeleteEnd();

private:
    /*!
     * Mark the piece as selected.
     */
    void select();
    /*!
     * Unmark the piece as selected.
     */
    void unselect();
};

#endif // PIECEITEM_H
