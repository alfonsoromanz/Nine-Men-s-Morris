#include "gamemodel.h"
#include "../controller/gamecontroller.h"
GameModel::GameModel()
{
}

bool GameModel::instanceFlag = false;
GameModel* GameModel::instance = NULL;
GameModel* GameModel::getInstance()
{
    if(! instanceFlag) {
        instance = new GameModel();
        instanceFlag = true;
        return instance;
    } else {
        return instance;
    }
}
void GameModel::saveMovement(Movement movement)
{
    stackMovements.push(movement);
}

void GameModel::popMovement()
{
    stackMovements.pop();
}


void GameModel::processMovement(Movement movement)
{
    currentState = simulateMovement(movement, currentState);

    if( movement.erase != 0 )
        listVisited.clear();

    visit(currentState);
    saveMovement(movement);

}

BoardState GameModel::simulateMovement( Movement movement, BoardState state)
{
    // Even if the from vertex is a source
    state.extractPieceAtVertex(movement.from);

    if (movement.erase != 0)
        state.extractPieceAtVertex(movement.erase);

    state.insertPieceAtVertex(movement.to, movement.player);

    return state;
}


BoardState GameModel::simulateMovement(Movement movement)
{
    return simulateMovement(movement, currentState);
}


bool GameModel::validFreeMovements(Movement movement, BoardState state)
{
    int vertexState = state.getVertexState(movement.to);

    if (vertexState == GameController::PLAYER_NULL)
        return true;
    return false;
}

bool GameModel::validFreeMovements(Movement movement)
{
    return validFreeMovements(movement, currentState);
}

bool GameModel::validFlyingMovements(Movement movement, BoardState state)
{
    return (state.getVertexState( movement.from ) == movement.player) && validFreeMovements(movement, state);
}

bool GameModel::validFlyingMovements(Movement movement)
{
    return validFlyingMovements(movement, currentState);
}

bool GameModel::validSlidingMovements(Movement movement, BoardState state)
{
    // If the destination vertex is not empty then return false
    int vertexState = state.getVertexState(movement.to);
    if (vertexState != GameController::PLAYER_NULL)
        return false;

    // Check if this empty vertex is adyacent to the origin
    // Not necesary in virtual movements
    bool areAdyacents = false;

    std::list <int> adyacents = state.getAdyacents(movement.to);
    std::list <int>::iterator it = adyacents.begin();
    while (it != adyacents.end() && !areAdyacents) {
        if (*it == movement.from)
            areAdyacents = true;
        it++;
    }

    return areAdyacents;
}

bool GameModel::validSlidingMovements(Movement movement)
{
    return validSlidingMovements(movement, currentState);
}

bool GameModel::validErasingMovements(Movement movement, BoardState state)
{
    int toErase = movement.erase;
    int vertexState = state.getVertexState(toErase);
    if ( (movement.player != vertexState) && isEraseable(toErase) ) {
        return true;
    }
    return false;
}

bool GameModel::validErasingMovements(Movement movement)
{
    return validErasingMovements(movement, currentState);
}

std::list<Movement> GameModel::getPossibleFreeMovements(int colour)
{
    return getPossibleFreeMovements( colour, currentState );
}

std::list<Movement> GameModel::getPossibleFreeMovements(int colour, BoardState state)
{
    // Returns the movements related to empties vertex and his deletions.

    // The lists of plays to return
    std::list<Movement> plays;
    // The auxiliar lists of opponent pieces (to erase)
    std::list<int> opponent;
    // The auxiliar current play
    Movement play;
    // The list of empties vertexes
    std::list<int> empties;

    // Get the empties vertexes
    empties = state.getPiecesByColour( GameController::PLAYER_NULL );

    // For each possible mill
    for ( std::list<int>::iterator it = empties.begin(); it != empties.end(); it++ ) {
        play.clear();
        play.from = (colour == GameController::PLAYER_BLACK) ? SOURCE_BLACK : SOURCE_WHITE;
        play.to = *it;
        play.player = colour;

        // If the movement generates sub-movements...
        if ( checkForMill( play, state ) ) {

            // Get the oponent pieces (possible to erase)
            opponent = state.getPiecesByColour( !colour );


            if (existsEraseable(!colour)) {
                // In this case, we can erase only non mill pieces
                for ( std::list<int>::iterator sit = opponent.begin(); sit != opponent.end(); sit++ ) {
                    // For each eraseable opponent piece generate a new child
                    if ( isEraseable(*sit) ) {
                        play.erase = *sit;
                        plays.push_back( play );
                    }
                }
            } else {
                //We can erase any opponent's piece
                for ( std::list<int>::iterator sit = opponent.begin(); sit != opponent.end(); sit++ ) {
                    // For each opponent piece generate a new child
                    play.erase = *sit;
                    plays.push_back( play );
                }
            }
        } else
            plays.push_back( play );
    }
    return plays;
}


std::list<Movement> GameModel::getPossibleFlyingMovements(int colour)
{
    return getPossibleFlyingMovements( colour, currentState );
}

std::list<Movement> GameModel::getPossibleFlyingMovements(int colour, BoardState state)
{
    // All the free-movements for each possible origin.

    // Return value
    std::list<Movement> plays;
    // Empty places
    std::list<int> emptyPlaces = state.getPiecesByColour(GameController::PLAYER_NULL);
    // origins
    std::list<int> origins = state.getPiecesByColour( colour );
    // in case of deleting opponent pieces
    std::list<int> opponent;
    // The auxiliar current play
    Movement play;

    // For each origin
    for ( std::list<int>::iterator it = origins.begin(); it != origins.end(); it++ ) {
        // For each empty place
        for ( std::list<int>::iterator sit = emptyPlaces.begin(); sit != emptyPlaces.end(); sit++ ) {
            //Generate the movement
            play.clear();
            play.from = *it;
            play.to = *sit;
            play.player = colour;

            // If this movement will generate a deletion, then generate the possible submovements
            if ( checkForMill(play, state) ) {

                // Get the oponent pieces (possible to erase)
                opponent = state.getPiecesByColour( !colour );


                if (existsEraseable(!colour)) {
                    // In this case, we can erase only non mill pieces
                    for ( std::list<int>::iterator ssit = opponent.begin(); ssit != opponent.end(); ssit++ ) {
                        // For each eraseable opponent piece generate a new child
                        if ( isEraseable(*ssit) ) {
                            play.erase = *ssit;
                            plays.push_back( play );
                        }
                    }
                } else {
                    //We can erase any opponent's piece
                    for ( std::list<int>::iterator ssit = opponent.begin(); ssit != opponent.end(); ssit++ ) {
                        // For each opponent piece generate a new child
                        play.erase = *ssit;
                        plays.push_back( play );
                    }
                }

            } else
                // return the movement
                plays.push_back( play );
        }
    }


    return plays;
}


std::list<Movement> GameModel::getPossibleSlidingMovements(int colour)
{
    return getPossibleSlidingMovements( colour, currentState );
}

std::list<Movement> GameModel::getPossibleSlidingMovements(int colour, BoardState state)
{

    // The lists of plays to return
    std::list<Movement> plays;
    // The pieces that can generate a new movement
    std::list<int> origins;
    std::list<int> adyacents;
    std::list<int> opponent;
    // The auxiliar current play
    Movement play;

    // The list of possible start vertex
    origins = state.getPiecesByColour( colour );

    // For each one
    for ( std::list<int>::iterator it = origins.begin(); it != origins.end(); it++ ) {
        // Obtain the adyacent vertex
        adyacents.clear();
        adyacents = state.getAdyacents( *it );

        // For each adyacent
        for ( std::list<int>::iterator sit = adyacents.begin(); sit != adyacents.end(); sit++ ) {
            // Generate the movement
            play.clear();
            play.from = *it;
            play.to = *sit;
            play.player = colour;
            // Check if valid knowing that the destination is adjacent (less complexity that the validateSlidingMoves function)
            if ( state.getVertexState(play.to) == GameController::PLAYER_NULL ) {

                // If this movement will generate a deletion, then generate the possible submovements
                if ( checkForMill(play, state) ) {

                    // Get the oponent pieces (possible to erase)
                    opponent = state.getPiecesByColour( !colour );

                    if (existsEraseable(!colour)) {
                        // In this case, we can erase only non mill pieces
                        for ( std::list<int>::iterator ssit = opponent.begin(); ssit != opponent.end(); ssit++ ) {
                            // For each eraseable opponent piece generate a new child
                            if ( isEraseable(*ssit) ) {
                                play.erase = *ssit;
                                plays.push_back( play );
                            }
                        }
                    } else {
                        //We can erase any opponent's piece
                        for ( std::list<int>::iterator ssit = opponent.begin(); ssit != opponent.end(); ssit++ ) {
                            // For each opponent piece generate a new child
                            play.erase = *ssit;
                            plays.push_back( play );
                        }
                    }
                } else
                    // return the movement
                    plays.push_back( play );
            }
        }
    }
    return plays;
}

int GameModel::getTotalByColour(int colour, BoardState state)
{
    return state.getTotalByColour( colour );
}
int GameModel::getTotalByColour(int colour)
{
    return getTotalByColour(colour, currentState);
}

int GameModel::getTotalBoardByColour(int colour, BoardState state)
{
    return state.getTotalByColour( colour ) - state.getSourceByColour( colour );
}
int GameModel::getTotalBoardByColour(int colour)
{
    return getTotalBoardByColour(colour, currentState);
}

bool GameModel::validSamePlayer(Movement movement)
{
    int vertexState = currentState.getVertexState(movement.from);
    if (vertexState == movement.player)
        return true;
    return false;

}

bool GameModel::isEraseable(int vertex)
{
    // If is not part of a mill
    int color = currentState.getVertexState(vertex);

    // An empty vertex is never eraseable
    if (color == GameController::PLAYER_NULL)
        return false;

    // Get the adyacentes vertex which can construct a mill
    std::list <std::pair <int, int> > millAdyacents = currentState.getMillsAdyacents(vertex);
    // For each pair of this
    for ( std::list <std::pair <int, int> >::iterator it = millAdyacents.begin(); it != millAdyacents.end(); it++) {
        // If the other two vertex ar of the same colour then return false
        if ((currentState.getVertexState(it->first) == color) && (currentState.getVertexState(it->second) == color))
            return false;
    }

    return true;
}

bool GameModel::checkForMill(Movement movement)
{
    return checkForMill(movement, currentState);
}

bool GameModel::checkForMill(Movement movement, BoardState state)
{
    // Iterate in the list of mill adyacents
    std::list <std::pair <int, int> > millAdyacents = state.getMillsAdyacents(movement.to);
    for ( std::list <std::pair <int, int> >::iterator it = millAdyacents.begin(); it != millAdyacents.end(); it++) {
        // If the from piece is part of the mill, wouldn't be in other vertex at the same time
        if ( (movement.from < 0 ) || (it->first != movement.from && it->second != movement.from ) )
            // else, if the two vertex are of the same colour, that is a mill
            if ((state.getVertexState(it->first) == movement.player) && (state.getVertexState(it->second) == movement.player))
                return true;
    }
    return false;
}


bool GameModel::isGameOver(int nextFase, int lastPlayer)
{
    return isGameOver( nextFase, lastPlayer, currentState );
}

bool GameModel::isGameOver(int nextFase, int lastPlayer, BoardState state )
{
    // Check if the game is over knowing who was the last player that move

    if (nextFase == GameController::FASE_SOLUTION)
        return true;

    // The total pieces of the opposite player
    int total;
    // the source pieces of the opposite player
    int source;
    total = state.getTotalByColour( !lastPlayer );
    source = state.getSourceByColour( !lastPlayer );

    if ( total < 3)
        return true;
    else

        // If there are pieces in the board
        if ( total - source > 0 ) {
            // Check if the opponent has possible movements remaining
            // In this case the fases are equal for both players
            if ( nextFase == GameController::FASE_PLACE) {
                if ( getPossibleFreeMovements(!lastPlayer, state).empty() )
                    return true;
            } else if (nextFase == GameController::FASE_FLYING ) {
                if ( getPossibleFlyingMovements(!lastPlayer, state).empty() )
                    return true;
            } else if ( getPossibleSlidingMovements(!lastPlayer, state).empty() )
                return true;
        }

    return false;
}

bool GameModel::existsEraseable(int colour, BoardState state)
{
    bool eraseable = false;
    std::list<int> pieces = state.getPiecesByColour(colour);
    std::list<int>::iterator it = pieces.begin();
    while ( it != pieces.end() && !eraseable ) {
        Movement aux;
        aux.from = *it;
        aux.to = *it;
        aux.player = colour;
        if ( !checkForMill( aux ) )
            eraseable = true;
        it++;
    }
    return eraseable;
}

bool GameModel::existsEraseable( int colour)
{
    return existsEraseable( colour, currentState );

}


int GameModel::calculateFase( int colour )
{
    return calculateFase( colour, currentState );
}

void GameModel::visit(BoardState state)
{
    listVisited.push_back( state );
}


bool GameModel::visited(BoardState state)
{
    // Same pieces at sources
    bool sources;
    // Same distribution at board
    bool board;

    for ( std::list<BoardState>::reverse_iterator otherState = listVisited.rbegin(); otherState != listVisited.rend(); ++otherState ) {

        board = true;
        sources = true;

        sources = state.getSourceByColour(GameController::PLAYER_BLACK) == otherState->getSourceByColour(GameController::PLAYER_BLACK);
        sources &= state.getSourceByColour(GameController::PLAYER_WHITE) == otherState->getSourceByColour(GameController::PLAYER_WHITE);

        if (sources) {
            for ( int i = 1; i <= 24; i++)
                board &= state.getVertexState(i) == otherState->getVertexState(i);

            if ( board )
                return true;
        }
    }

    return false;
}


int GameModel::calculateFase( int colour, BoardState state )
{
    int pieces = state.getTotalByColour( colour );
    int source = state.getSourceByColour( colour );
    if ( pieces == 3 )
        return GameController::FASE_FLYING;
    if ( source > 0 )
        return GameController::FASE_PLACE;
    if (pieces < 3)
        return GameController::FASE_SOLUTION;

    return GameController::FASE_MOVING_SELECT;
}


void GameModel::unvisit()
{
    listVisited.pop_back();
}

void GameModel::clear()
{
    listVisited.clear();
    while(!stackMovements.empty())
        stackMovements.pop();

    currentState.clear();

}
