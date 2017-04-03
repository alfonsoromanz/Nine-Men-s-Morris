#include "gamecontroller.h"
#include<QMetaMethod>

GameController::GameController(QObject *parent)
{
}


bool GameController::instanceFlag = false;
GameController *GameController::instance = NULL;
GameController *GameController::getInstance()
{
    if (! instanceFlag) {
        instance = new GameController();
        instanceFlag = true;
        return instance;
    } else {
        return instance;
    }
}

GameController::~GameController()
{
    delete instance;
}

void GameController::onVertexClick(int vertex)
{
    bool errorShow = false;
    int originalFrom;

    int fase = gameModel->calculateFase( currentPlayer );
    bool process = false;

    switch ( flagMovementState ) {
    case FASE_MOVEMENT_FINISHED:
        // First parts

        switch ( fase ) {
        case FASE_PLACE:
            // Always starts a new movement
            currentMovement.clear();

            // Pieces always come from sources in this fase
            currentMovement.from = (currentPlayer == GameController::PLAYER_BLACK) ? GameModel::SOURCE_BLACK : GameModel::SOURCE_WHITE;
            currentMovement.player = currentPlayer;
            currentMovement.to = vertex;

            if (!gameModel->validFreeMovements(currentMovement)) {
                errorShow = true;
                triggerViewError( "No se puede colocar una ficha en un vértice ocupado." );
            } else
                process = true;

            break;
        case FASE_MOVING_SELECT:
            // Always starts a new movement
            currentMovement.clear();
            currentMovement.from = vertex;
            currentMovement.player = currentPlayer;

            if (gameModel->validSamePlayer(currentMovement))
                flagMovementState = FASE_MOVEMENT_WAITING;
            else {
                errorShow = true;
                triggerViewError( "Debe seleccionar una ficha propia." );
            }
            break;
            // The last fase
        case FASE_FLYING:
            currentMovement.erase = 0;
            // Check if the clicked vertex can be a correction of the previous selection, else, is the destination vertex
            originalFrom = currentMovement.from;
            currentMovement.from = vertex;
            currentMovement.player = currentPlayer;
            if ( !gameModel->validSamePlayer( currentMovement ) ) {
                currentMovement.to = vertex;
                currentMovement.from = originalFrom;
                if (gameModel->validFlyingMovements(currentMovement))
                    process = true;
                else {
                    errorShow = true;
                    triggerViewError( "Ficha de destino no válida, debe estar vacía." );
                }
            }
            break;
        }
        break;

    case FASE_MOVEMENT_WAITING:
        // Second parts

        // Check if the clicked vertex can be a correction of the previous selection, else, is the destination vertex

        originalFrom = currentMovement.from;
        currentMovement.from = vertex;
        if ( !gameModel->validSamePlayer( currentMovement ) ) {
            currentMovement.from = originalFrom;

            // In this part set the destination vertex
            currentMovement.to = vertex;

            if ( gameModel->validSlidingMovements(currentMovement) )
                process = true;
            else {
                errorShow = true;
                triggerViewError( "Ficha de destino no válida, debe estar vacía y ser adyacente." );
            }
        }
        break;
    case FASE_MOVEMENT_ERASING:
        // Thirds or second parts

        currentMovement.erase = vertex;


        if ( !gameModel->existsEraseable(!currentPlayer) || gameModel->validErasingMovements(currentMovement))
            process = true;
        else {
            errorShow = true;
            triggerViewError( "Ficha a eliminar no válida." );
        }
        break;
    }

    if ( process ) {

        bool willBeMill = flagMovementState != FASE_MOVEMENT_ERASING && gameModel->checkForMill( currentMovement );
        // Fix
        currentMovement.flagShowed = true;


        if ( willBeMill ) {
            flagMovementState = FASE_MOVEMENT_ERASING;

            // Previsualization of the movement
            if ( fase == FASE_PLACE )
                triggerPopSourcePiece( currentPlayer );

            disconnectUi();
            triggerViewShowMovement( currentMovement );
        } else {

            // If it doesn't become from an erasing movement
            if ( fase == FASE_PLACE && flagMovementState != FASE_MOVEMENT_ERASING )
                triggerPopSourcePiece( currentPlayer );

            flagMovementState = FASE_MOVEMENT_FINISHED;
            gameModel->processMovement( currentMovement );

            disconnectUi();
            triggerViewShowMovement( currentMovement );
        }
    }
    if (!errorShow)
        triggerViewClearError();
}

void GameController::processVirtualMovement(Movement movement)
{
    // By checking the current fase, show the animation to erase the source piece representation
    if ( turnNumber <= 18 )
        triggerPopSourcePiece( currentPlayer );

    gameModel->processMovement(movement);


    triggerViewShowMovement( movement );
}


void GameController::setPlayers(Player whitePlayer, Player blackPlayer)
{
    player[ GameController::PLAYER_WHITE ] = whitePlayer;
    player[ GameController::PLAYER_BLACK ] = blackPlayer;

}

void GameController::next()
{

    if ( flagPause == PAUSE_PLAYING ) {
        turnNumber++;

        currentPlayer = (currentPlayer == PLAYER_BLACK) ? currentPlayer = PLAYER_WHITE : currentPlayer = PLAYER_BLACK;

        // Show the new player
        triggerViewSetPlayer( currentPlayer );

        // Do the according action to the virtuality of the current player
        if ( player[currentPlayer].getVirtuality() == Player::PLAYER_HUMAN )
            connectUi();
        else
            processVirtualMovement(playVirtual());
    } else if (flagPause == PAUSE_PAUSING)
        flagPause = PAUSE_PAUSED;

}


void GameController::onPause()
{
    flagPause = PAUSE_PAUSING;
}

void GameController::onRestart()
{
    if ( flagPause == PAUSE_PAUSED ) {
        flagPause = PAUSE_PLAYING;
        next();
    } else {
        flagPause = PAUSE_PLAYING;
    }

}

void GameController::onAnimationEnd()
{
    // Before the next movement, check if the game is over
    // A game can't end in a erasing fase, it ends after the deletion is made
    // There's not animation in moving_select fase, so this case isn't considerated

    int opponentFase = gameModel->calculateFase( currentPlayer );

    if ( flagMovementState != FASE_MOVEMENT_ERASING )
        if ( gameModel->isGameOver( opponentFase, currentPlayer)) {
            triggerEnd( currentPlayer );
            return;
        }

    // According to the fase, call to next or wait for another user interaction
    if ( flagMovementState != FASE_MOVEMENT_ERASING )
        next();
    else
        // Here the player is always human
        connectUi();
}

void GameController::onQuit()
{
    triggerEnd(3);
}


void GameController::start(int starter)
{

    gameModel = GameModel::getInstance();
    gameModel->clear();

    flagMovementState = FASE_MOVEMENT_FINISHED;
    flagPause = PAUSE_PLAYING;

    turnNumber = 1;
    currentMovement.clear();

    gameView = new GameView();
    // Connect the view's signals with the controller slots (view's events)
    connect( gameView, SIGNAL(triggerAnimationEnd()), this, SLOT(onAnimationEnd()) );
    connect( this, SIGNAL(triggerViewError(std::string)), gameView, SLOT(showError(std::string)) );
    connect( this, SIGNAL(triggerViewClearError()), gameView, SLOT(clearError()) );
    connect( this, SIGNAL(triggerViewSetPlayer(int)), gameView, SLOT(onSetPlayer(int)) );
    connect( this, SIGNAL(triggerViewShowMovement(Movement)), gameView, SLOT(showMovement(Movement)) );
    connect( this, SIGNAL(triggerPopSourcePiece(int)), gameView, SLOT(popSourcePiece(int)) );
    connect(gameView->playButton, SIGNAL(clicked()), this, SLOT(onRestart()));
    connect(gameView->pauseButton, SIGNAL(clicked()), this, SLOT(onPause()));
    connect(gameView->stopButton, SIGNAL(clicked()), this, SLOT(onQuit()));

    // Set the starter player
    currentPlayer = starter;
    gameView->onSetPlayer( currentPlayer );

    // Do the corresponding action according the virtuality of the current player
    if ( player[currentPlayer].getVirtuality() == Player::PLAYER_HUMAN ) {
        // Activate UI
        connectUi();
    } else
        processVirtualMovement(playVirtual());
}

Movement GameController::playVirtual()
{
    // Alpha beta pruning
    int alpha = -10000;
    int beta = -10000;

    // When there is any movement to do
    bool someMovement = false;

    // Returnable movement
    Movement movement;

    // First-level childs
    std::list<Movement> plays;

    // Current board simulation
    BoardState simulation;

    // Get the possible movements in relation to the fase
    int currentFase = gameModel->calculateFase( currentPlayer );

    if ( currentFase == FASE_PLACE ) {
        plays = gameModel->getPossibleFreeMovements( currentPlayer );
    } else if ( currentFase == FASE_FLYING ) {
        plays = gameModel->getPossibleFlyingMovements( currentPlayer );
    } else {
        plays = gameModel->getPossibleSlidingMovements( currentPlayer );
    }


    // For each possible movement (childs)
    for ( std::list<Movement>::iterator it = plays.begin(); it != plays.end(); it++ ) {

        // Simulate the movement
        simulation = gameModel->simulateMovement( *it );

        // If is not visited yet
        if (!gameModel->visited(simulation)) {
            someMovement = true;
            // Save as visit
            gameModel->visit(simulation);


            // Calculate max/min in deep search
            int val = -deepSearch( simulation, player[currentPlayer].getDeep() - 1, player[currentPlayer].getHeuristic(), ((currentPlayer != PLAYER_WHITE) ? 1 : -1 ), !currentPlayer, alpha, -beta );

            // Marking as unvisited
            gameModel->unvisit();

            if ( val > beta ) {
                beta = val;
                movement = *it;
            }
        }
    }

    // When there isn't any movements to make (Only by pruning) return the first
    // movement
    if ( !someMovement )
        return plays.front();
    return movement;
}


int GameController::deepSearch(BoardState state, int deep, int heuristic, int signPlayer, int player, int alpha, int beta)
{
    // Calculate the fase of each player
    int fase = gameModel->calculateFase( player, state );

    if ( gameModel->isGameOver( fase, !player, state ) ) {
        // Assuming that the winner is the last player
        return -1000 - deep;
    }
    // If it is a frontier vertex
    if ( deep == 0 ) {
        // Eval in the selected heuristic
        return signPlayer * heuristicEvaluation(state, heuristic );
    } else {

        // Child simulation
        BoardState simulation;

        // Children
        std::list<Movement> plays;
        bool someUnVisited = false;

        if ( fase == FASE_PLACE )
            plays = gameModel->getPossibleFreeMovements( player, state );
        else if ( fase == FASE_FLYING )
            plays = gameModel->getPossibleFlyingMovements( player, state );
        else
            plays = gameModel->getPossibleSlidingMovements( player, state );

        for ( std::list<Movement>::iterator it = plays.begin(); it != plays.end(); it++ ) {
            simulation = gameModel->simulateMovement( *it,  state );
            if (!gameModel->visited(simulation)) {
                someUnVisited = true;

                gameModel->visit(simulation);

                int val = -deepSearch( simulation, deep - 1, heuristic, -signPlayer, !player, -beta, -alpha );


                gameModel->unvisit();

                if ( val >= alpha ) {
                    alpha = val;
                }

                if ( alpha >= beta ) {
                    return alpha;
                }
            }
        }

        // Returns a value in case that all the children have been already visited
        if (!someUnVisited) {
            simulation = gameModel->simulateMovement( plays.front(),  state );
            return signPlayer * heuristicEvaluation(simulation, heuristic );

        }


    }
    return alpha;
}


void GameController::disconnectUi()
{
    disconnect( gameView, SIGNAL(triggerVertexClick( int )), this, SLOT(onVertexClick(int)) );
}
void GameController::connectUi()
{
    connect( gameView, SIGNAL(triggerVertexClick( int )), this, SLOT(onVertexClick(int)) );
}

int GameController::evalHeuristicOne( BoardState state )
{
    int tW = state.getTotalByColour(GameController::PLAYER_WHITE);
    int tB = state.getTotalByColour(GameController::PLAYER_BLACK);

    return tW - tB;
}

int GameController::evalHeuristicTwo( BoardState state )
{
    int whiteFase = gameModel->calculateFase(PLAYER_WHITE, state);
    int blackFase = gameModel->calculateFase(PLAYER_BLACK, state);

    //Calculates the number of white player's movement
    int whiteMoves;
    if (whiteFase == FASE_PLACE) {
        whiteMoves = gameModel->getPossibleFreeMovements(PLAYER_WHITE, state).size();
    } else if (whiteFase == FASE_FLYING) {
        whiteMoves = gameModel->getPossibleFlyingMovements(PLAYER_WHITE, state).size();
    } else {
        whiteMoves = gameModel->getPossibleSlidingMovements(PLAYER_WHITE, state).size();
    }

    //Calculates the number of black player's movement

    int blackMoves;
    if (blackFase == FASE_PLACE) {
        blackMoves = gameModel->getPossibleFreeMovements(PLAYER_BLACK, state).size();
    } else if (blackFase == FASE_FLYING) {
        blackMoves = gameModel->getPossibleFlyingMovements(PLAYER_BLACK, state).size();
    } else {
        blackMoves = gameModel->getPossibleSlidingMovements(PLAYER_BLACK, state).size();
    }

    return (38 * evalHeuristicOne(state) + (whiteMoves - blackMoves));
}

int GameController::evalHeuristicThree( BoardState state )
{
    //Calculates the difference between white and black pieces number

    int piecesDifference = evalHeuristicOne(state);

    //Calculates the difference between white and black freedom on the board

    int whiteFreedom = 0;
    int blackFreedom = 0;
    std::list<int> blackPieces, whitePieces, adyacents;

    whitePieces = state.getPiecesByColour(PLAYER_WHITE);
    for (std::list<int>::iterator it = whitePieces.begin(); it != whitePieces.end(); it++) {
        adyacents = state.getAdyacents( *it );
        for (std::list<int>::iterator sit = adyacents.begin(); sit != adyacents.end(); sit++)
            if ((*sit) == PLAYER_NULL)
                whiteFreedom++;
    }

    blackPieces = state.getPiecesByColour(PLAYER_BLACK);
    for (std::list<int>::iterator it = blackPieces.begin(); it != blackPieces.end(); it++) {
        adyacents = state.getAdyacents( *it );
        for (std::list<int>::iterator sit = adyacents.begin(); sit != adyacents.end(); sit++)
            if ((*sit) == PLAYER_NULL)
                blackFreedom++;
    }

    int freedomDifference = (whiteFreedom - blackFreedom);

    //Calculates the difference between white and black mill's pieces number

    int inMillBlack = 0;
    int inMillWhite = 0;
    std::list<int> piecesBlack = state.getPiecesByColour( PLAYER_BLACK );
    std::list<int> piecesWhite = state.getPiecesByColour( PLAYER_WHITE );

    for (std::list<int>::iterator it = piecesBlack.begin(); it != piecesBlack.end(); it ++) {
        std::list<std::pair<int, int> > ady = state.getMillsAdyacents( *it );
        for ( std::list <std::pair <int, int> >::iterator sit = ady.begin(); sit != ady.end(); sit++) {
            if ((state.getVertexState(sit->first) == PLAYER_BLACK) && (state.getVertexState(sit->second) == PLAYER_BLACK))
                inMillBlack++;
        }
    }
    for (std::list<int>::iterator it = piecesWhite.begin(); it != piecesWhite.end(); it ++) {
        std::list<std::pair<int, int> > ady = state.getMillsAdyacents( *it );
        for ( std::list <std::pair <int, int> >::iterator sit = ady.begin(); sit != ady.end(); sit++) {
            if ((state.getVertexState(sit->first) == PLAYER_WHITE) && (state.getVertexState(sit->second) == PLAYER_WHITE))
                inMillWhite++;
        }
    }

    int millDifference = (inMillWhite - inMillBlack);


    // Returns the linear combination

    return ( (10 * piecesDifference) + (2 * freedomDifference) + (2 * millDifference) );

}


int GameController::heuristicEvaluation( BoardState state, int heuristic )
{
    switch ( heuristic ) {
    case HEURISTIC_ONE:
        return evalHeuristicOne( state );
        break;
    case HEURISTIC_TWO:
        return evalHeuristicTwo( state );
        break;
    case HEURISTIC_THREE:
        return evalHeuristicThree( state );
        break;
    default:
        return evalHeuristicOne( state );
        break;
    }
}


GameView *GameController::getView()
{
    return gameView;
}
