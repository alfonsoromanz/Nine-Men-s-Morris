#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "player.h"

/*!
 * \class Movement
 *
 * ADT of a movement to play.
 *
 */
class Movement {
public:

	Movement();

    int from;

    int to;

    int player;

    int erase;

    bool flagShowed;//!< Flag to tell the view that the movement was shown before the deletion, in case that this exists.

    void clear();

};
#endif
