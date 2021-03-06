#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "movement.h"
#include "player.h"
#include "../model/boardstate.h"
#include "../view/gameview.h"
#include "../model/gamemodel.h"
#include <QObject>

/*!
 * \class GameController
 *
 * Manage the game flow, respond to the user interactions
 * doing the according tasks, and control the rules of the game.
 *
 */
class GameController : public QObject {
    Q_OBJECT
private:

    static const int HEURISTIC_ONE = 0x01;
    static const int HEURISTIC_TWO = 0x02;
    static const int HEURISTIC_THREE = 0x03;

    // Human partial fases
    static const int FASE_MOVEMENT_WAITING = 0x03;
    static const int FASE_MOVEMENT_FINISHED = 0x05;
    static const int FASE_MOVEMENT_ERASING = 0x06;

    // Control states
    static const int PAUSE_PAUSING = 0x0;
    static const int PAUSE_PAUSED = 0x1;
    static const int PAUSE_PLAYING = 0x2;


    static bool instanceFlag; //!< Singleton instanciated object flag.
    static GameController *instance;  //!< Singleton instance.

    // Constructor
    explicit GameController( QObject *parent = 0 ); //!< Private constructor (Singleton).

    Player player[2]; //!< Players configuration.

    int flagPause; //!< Flag to stop the game before the next movement.

    Movement currentMovement; //!< Partial movement beeing generated by human players.
    int flagMovementState; //!< Partial state of the generation of a human movement.

    int currentPlayer;
    int turnNumber;

    void disconnectUi(); //!< Disable ui at animations or virtual player turns.
    void connectUi(); //!< Enable ui.

    int evalHeuristicOne( BoardState state );
    int evalHeuristicTwo( BoardState state );
    int evalHeuristicThree( BoardState state );

    int heuristicEvaluation (BoardState state, int heuristic);

    int deepSearch(BoardState state, int deep, int heuristic, int level, int colour, int alpha, int beta); //!< Negamax algorithm to choise the best movement desition.

    GameView *gameView;  //!< Reference to the unique game view.
    GameModel *gameModel;  //!< Reference to the unique game model.

    /*!
     * Calculate the possible movements to do by a virtual player
     * and eval each possible decision based in negamax algorithm
     * before plays.
     *
     * \return The best valid Movement including its deletion.
     */
    Movement playVirtual();

public slots:
    /*!
     * Receive the user clicks and manages the creation of a movement,
     * then, process it.
     *
     * \param vertex Vertex clicked by user.
     */
    void onVertexClick( int vertex );
    /*!
     * on Pause button click
     */
    void onPause();
    /*!
     * on Play button click
     */
    void onRestart();
    /*!
     * on Stop button clicked
     */
    void onQuit();
    void onAnimationEnd();

signals:
    void triggerEnd( int winner );
    void triggerViewError( std::string text );
    void triggerViewClearError( );
    void triggerViewSetPlayer( int player );
    void triggerViewShowMovement( Movement movement );
    void triggerPopSourcePiece( int playerColour );


public:
    // Types of players
    static const int PLAYER_NULL = 0x02;
    static const int PLAYER_WHITE = 0x00;
    static const int PLAYER_BLACK = 0x01;

    // Public fases of the game
    static const int FASE_PLACE = 0x01;
    static const int FASE_MOVING_SELECT = 0x02;
    static const int FASE_FLYING = 0x04;
    static const int FASE_SOLUTION = 0x07;

    /*!
     * Make the corresponding actions to execute the received movement
     * \param movement Full intelligent movement.
     */
    void processVirtualMovement(Movement movement);

    void setPlayers(Player whitePlayer, Player blackPlayer);

    /*!
     * Function called only once, to start the game flow.
     * \param starter Player selected to start the game.
     */
    void start(int starter = PLAYER_WHITE);

    /*!
     * Changes the player and does the necessary actions to continue the game flow.
     */
    void next();

    /*!
     * Getter of the gameView reference.
     * \return  The unique game view.
     */
    GameView *getView( );


    /*!
     * Singleton get instance
     */
    static GameController *getInstance();

    ~GameController();

};
#endif
