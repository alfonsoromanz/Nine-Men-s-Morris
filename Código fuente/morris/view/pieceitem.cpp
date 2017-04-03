#include "pieceitem.h"
#include <QGraphicsSceneMouseEvent>
#include "../controller/gamecontroller.h"

PieceItem::PieceItem(int color)
{
    this->color = color;
    if ( color == GameController::PLAYER_BLACK )
        image.load(":/pieces/black_piece.png");
    else
        image.load(":/pieces/white_piece.png");

    this->setPixmap( image );
    this->setOffset(-0.5 * QPoint(image.width(), image.height()) );
    this->setTransformationMode(Qt::SmoothTransformation);
}

void PieceItem::animateMove(QPropertyAnimation *pieceAnimation, int fromX, int fromY, int toX, int toY)
{
    pieceAnimation->setPropertyName("pos");
    pieceAnimation->setTargetObject(this);
    pieceAnimation->setDuration( 250 );
    pieceAnimation->setStartValue( QPointF(fromX, fromY) );
    pieceAnimation->setEndValue( QPointF(toX, toY) );
    pieceAnimation->setEasingCurve( QEasingCurve::InOutBack );
    pieceAnimation->start( );
}


void PieceItem::animateAppear(QPropertyAnimation *pieceAnimation)
{
    pieceAnimation->setTargetObject(this);
    pieceAnimation->setPropertyName("scale");
    pieceAnimation->setDuration( 500 );
    pieceAnimation->setStartValue( qreal(0) );
    pieceAnimation->setEndValue( qreal(1) );
    pieceAnimation->setEasingCurve( QEasingCurve::OutElastic );
    pieceAnimation->start( );
}

void PieceItem::animateDelete(QPropertyAnimation *pieceAnimation)
{

    pieceAnimation->setTargetObject(this);
    pieceAnimation->setPropertyName("scale");
    pieceAnimation->setDuration( 250 );
    pieceAnimation->setStartValue( qreal(1) );
    pieceAnimation->setEndValue( qreal(0) );
    pieceAnimation->setEasingCurve( QEasingCurve::InBack );
    pieceAnimation->start();
}

void PieceItem::onUpdateSelected( int id )
{
    if ( id == this->data(GameView::KEY_VERTEX_ID).value<int>() )
        select();
    else
        unselect();
}

void PieceItem::onDeleteEnd()
{
    this->~PieceItem();
}

void PieceItem::select( )
{
    if ( color == GameController::PLAYER_BLACK )
        image.load(":/pieces/black_piece_selected.png");
    else
        image.load(":/pieces/white_piece_selected.png");

    this->setPixmap( image );
}
void PieceItem::unselect()
{
    if ( color == GameController::PLAYER_BLACK )
        image.load(":/pieces/black_piece.png");
    else
        image.load(":/pieces/white_piece.png");

    this->setPixmap( image );
}
