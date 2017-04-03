#include "movement.h"
#include "gamecontroller.h"


Movement::Movement(){
	clear();
}

void Movement::clear()
{
    from = 0;
    to = 0;
    erase = 0;
    player = GameController::PLAYER_NULL;
    flagShowed = false;
}
