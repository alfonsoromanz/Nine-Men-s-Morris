#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include "boardstate.h"
#include "../controller/movement.h"
#include "stack"

/*!
 * \class GameModel
 *
 * The model of the game system.
 *
 * This class doesn't represent a board or a state. This is an "Abstract class"
 * (don't confuse with the poo term "abstract") which has the necessary
 * functionality to manage states, maintain the current game state, remember 
 * previous movements, generate possible plays and validate them.
 *
 */
class GameModel {
private:

    /*!
     * Private constructor
     */
    GameModel();

    std::stack<Movement> stackMovements; //!< Not implemented, stack to undo movements.

    BoardState currentState; //!< The real state of the game at the moment.

    /*!
     * Save the specified movement in the stack of movements.
     * \param movement A played movement.
     */
    void saveMovement(Movement movement);

    /*!
     * Eliminates the last movement from the stack of movements.
     */
    void popMovement();

    std::list<BoardState> listVisited; //!< Previous played movements to prevent cycles in the negamax algorithm


    static bool instanceFlag; //!< Singleton instanciated object flag.
    static GameModel * instance; //!< Singleton instance.

public:

    /*!
     * Singleton get instance.
     */
    static GameModel * getInstance();

    static const int SOURCE_WHITE = -0x01;
    static const int SOURCE_BLACK = -0x02;

    /*!
     * Do the necessary actions to update the model when a movement is executed
     *
     * Calls to simulateMovement, save the movement in the stack and updates
     * the current board state.
     */
    void processMovement(Movement movement);

    /*!
     * Take a board and execute the movement on this.
     * \param state Optional, if not state is given, takes the currentState.
     * \return A new board state with the movement executed therein.
     */
    BoardState simulateMovement( Movement movement, BoardState state);
    BoardState simulateMovement( Movement movement);

    /*!
     * Validation of a movement at place fase. Used in Flying validation
     * \param state Optional, if not state is given, takes the currentState.
     */
    bool validFreeMovements(Movement movement, BoardState state);
    bool validFreeMovements (Movement movement);

    /*!
     * Validation of a movement at flying fase. Uses validFreeMovements function.
     * \param state Optional, if not state is given, takes the currentState.
     */
    bool validFlyingMovements(Movement movement, BoardState state);
    bool validFlyingMovements (Movement movement);

    /*!
     * Validation of a movement at the sliding fase.
     * \param state Optional, if not state is given, takes the currentState.
     */
    bool validSlidingMovements(Movement movement, BoardState state);
    bool validSlidingMovements(Movement movement);

    /*!
     * Validation of a movement at erasing fase.
     * \param state Optional, if not state is given, takes the currentState.
     */
    bool validErasingMovements(Movement movement, BoardState state);
    bool validErasingMovements(Movement movement);


    /*!
     * Checks if the from piece is an own piece.
     * \param movement
     * \return
     */
    bool validSamePlayer(Movement movement);

    /*!
     * Get the possible movements of a player at placing fase.
     * \param state Optional, if not state is given, takes the currentState.
     * \param colour The colour of the player that is querying movements.
     * \return
     */
    std::list<Movement> getPossibleFreeMovements( int colour, BoardState state );
    std::list<Movement> getPossibleFreeMovements( int colour );

    /*!
     * Get the possible movements of a player at flying fase.
     * \param state Optional, if not state is given, takes the currentState.
     * \param colour The colour of the player that is querying movements.
     * \return
     */
    std::list<Movement> getPossibleFlyingMovements( int colour, BoardState state );
    std::list<Movement> getPossibleFlyingMovements( int colour );

    /*!
     * Get the possible movements of a player at sliding fase.
     * \param state Optional, if not state is given, takes the currentState.
     * \param colour The colour of the player that is querying movements.
     * \return
     */
    std::list<Movement> getPossibleSlidingMovements( int colour, BoardState state );
    //DEBUG BORRAR
    std::list<Movement> getPossibleSlidingMovements( int colour );

    /*!
     * Get the number of pieces by colour INCLUDING the pieces in sources
     * \param state Optional, if not state is given, takes the currentState.
     */
    int getTotalByColour(int colour, BoardState state);
    int getTotalByColour(int colour);


    /*!
     * Get the number of pieces by colour IGNORING the pieces in sources
     * \param state Optional, if not state is given, takes the currentState.
     */
    int getTotalBoardByColour(int colour, BoardState state);
    int getTotalBoardByColour(int colour);

    /*!
     * Check if a piece can be erased
     * \param vertex Vertex where the piece is
     */
    bool isEraseable(int vertex);

    /*!
     * Check if a movement will generate or not a mill. (After executing it)
     * \param state Optional, if not state is given, takes the currentState.
     * \return True if the player will make a mill putting the piece on the specified "to" vertex
     */
    bool checkForMill(Movement movement, BoardState state);
    bool checkForMill(Movement movement);

    //
    /*!
     * Checks if the game is over.
     * \param nextFase Fase in which game continues, to check for the impossibility to make moves.
     * \param lastPlayer The last player that moves.
     * \param state Optional, if not state is given, takes the currentState.
     * \return True if the game is over, assuming by rules of game that the winner is always the last player that moves.
     */
    bool isGameOver(int nextFase, int lastPlayer, BoardState state);
    bool isGameOver(int nextFase, int lastPlayer);

    /*!
     * Checks if exists any piece to erase
     * \param state Optional, if not state is given, takes the currentState.
     * \param colour The opponent's colour, from whom a piece should be deleted
     */
    bool existsEraseable(int colour, BoardState state);
    bool existsEraseable(int colour);

    /*!
     * Calculate the current game fase of a player according to a board state
     * \param state Optional, if not state is given, takes the currentState.
     * \param colour The opponent's colour, from whom a piece should be deleted
     */
    int calculateFase(int colour, BoardState state);
    int calculateFase(int colour);

    /*!
     * Mark a state as visited
     */
    void visit( BoardState state );

    /*!
     * Checks if a state was visited
     */
    bool visited( BoardState state );

    /*!
     * Forget that a state was visited
     */
    void unvisit();

    /*!
     * Restart the model
     */
    void clear();

};
#endif
