#ifndef VERTEXITEM_H
#define VERTEXITEM_H

#include <QGraphicsItem>

/*!
 * Displayable vertex
 *
 * Represents a clickeable area on the screen, invisible for players.
 */
class VertexItem : public QGraphicsPixmapItem, public QObject {

public:
    explicit VertexItem( int id );
    int vertexId;
};

#endif // VERTEXITEM_H
