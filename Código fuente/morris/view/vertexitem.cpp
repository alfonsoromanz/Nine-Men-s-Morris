#include "vertexitem.h"
#include <QGraphicsSceneMouseEvent>

VertexItem::VertexItem(int id)
{
    vertexId = id;

    QPixmap button(":/vertex_area.png");
    this->setPixmap( button );
    this->setOffset(-16, -16);
}
