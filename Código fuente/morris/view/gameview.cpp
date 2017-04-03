#include "gameview.h"
#include "../model/gamemodel.h"
#include "../controller/gamecontroller.h"
GameView::GameView(QWidget *parent) :
    QWidget(parent)
{

    // Define the relative/theoric position of the vertexes on the screen (first = width, second = height)
    staticVertexPositions[ 7 ].first =  256 ;
    staticVertexPositions[ 7 ].second =  156 ;
    staticVertexPositions[ 0 ].first =  400 ;
    staticVertexPositions[ 0 ].second =  156 ;
    staticVertexPositions[ 1 ].first =  544 ;
    staticVertexPositions[ 1 ].second =  156 ;
    staticVertexPositions[ 15 ].first =  304 ;
    staticVertexPositions[ 15 ].second =  204 ;
    staticVertexPositions[ 8 ].first =  400 ;
    staticVertexPositions[ 8 ].second =  204 ;
    staticVertexPositions[ 9 ].first =  496 ;
    staticVertexPositions[ 9 ].second =  204 ;
    staticVertexPositions[ 23 ].first =  352 ;
    staticVertexPositions[ 23 ].second =  252 ;
    staticVertexPositions[ 16 ].first =  400 ;
    staticVertexPositions[ 16 ].second =  252 ;
    staticVertexPositions[ 17 ].first =  448 ;
    staticVertexPositions[ 17 ].second =  252 ;
    staticVertexPositions[ 6 ].first =  256 ;
    staticVertexPositions[ 6 ].second =  300 ;
    staticVertexPositions[ 14 ].first =  304 ;
    staticVertexPositions[ 14 ].second =  300 ;
    staticVertexPositions[ 22 ].first =  352 ;
    staticVertexPositions[ 22 ].second =  300 ;
    staticVertexPositions[ 18 ].first =  448 ;
    staticVertexPositions[ 18 ].second =  300 ;
    staticVertexPositions[ 10 ].first =  496 ;
    staticVertexPositions[ 10 ].second =  300 ;
    staticVertexPositions[ 2 ].first =  544 ;
    staticVertexPositions[ 2 ].second =  300 ;
    staticVertexPositions[ 21 ].first =  352 ;
    staticVertexPositions[ 21 ].second =  348 ;
    staticVertexPositions[ 20 ].first =  400 ;
    staticVertexPositions[ 20 ].second =  348 ;
    staticVertexPositions[ 19 ].first =  448 ;
    staticVertexPositions[ 19 ].second =  348 ;
    staticVertexPositions[ 13 ].first =  304 ;
    staticVertexPositions[ 13 ].second =  396 ;
    staticVertexPositions[ 12 ].first =  400 ;
    staticVertexPositions[ 12 ].second =  396 ;
    staticVertexPositions[ 11 ].first =  496 ;
    staticVertexPositions[ 11 ].second =  396 ;
    staticVertexPositions[ 5 ].first =  256 ;
    staticVertexPositions[ 5 ].second =  444 ;
    staticVertexPositions[ 4 ].first =  400 ;
    staticVertexPositions[ 4 ].second =  444 ;
    staticVertexPositions[ 3 ].first =  544 ;
    staticVertexPositions[ 3 ].second =  444 ;


    // Initialize arrays
    for ( int i = 0; i < 24; i++) {
        vertexPiece[i] = NULL;
        vertexItems[i] = NULL;
    }

    // Initialize the view and scene objects
    view = new QGraphicsView(this);
    view->setFrameStyle(QFrame::NoFrame);
    board = new QGraphicsScene(view);
    board->setSceneRect(0, 0, 800, 600);

    view->setFixedWidth(800);
    view->setFixedHeight(600);
    view->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    view->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    view->setStyleSheet("background:url(\":/game_background.jpg\");");
    view->setScene( board );
    view->setRenderHint(QPainter::HighQualityAntialiasing, true);
    view->setRenderHint(QPainter::SmoothPixmapTransform, true);

    // Create and display the graphic and logical vertexes on the screen
    for (int i = 0; i < 24; i++) {
        // Create the vertex and assign the corresponding image
        vertexItems[i] = new VertexItem(i + 1);

        // Data carried in the graphic object
        QVariant id;
        id.setValue(i + 1);
        vertexItems[i]->setData( KEY_VERTEX_ID, id );

        // Display on the scene
        vertexItems[i]->setPos( staticVertexPositions[i].first, staticVertexPositions[i].second );
        board->addItem( vertexItems[i] );
    }


    // Initialize the "Current Player" label
    currentPlayerText = new QGraphicsTextItem;
    currentPlayerText->setPos(196, 0);
    currentPlayerText->setFont(QFont("AngryBirds", 28));

    board->addItem(currentPlayerText);

    // Prepair the output for error messages
    errorMessage = new QGraphicsTextItem;
    errorMessage->setPos(193, 550);
    errorMessage->setFont(QFont("Arial", 20));

    board->addItem(errorMessage);


    // Initialize the animation handler
    pieceAnimation = new QPropertyAnimation( );

    // Null by default
    selectedPiece = NULL;

    // Generate source pieces (Witouth functionaly, so they aren't independent class)
    QPixmap whiteSourcePixmap(":/pieces/white_source_piece.png");
    QPixmap blackSourcePixmap(":/pieces/black_source_piece.png");
    int sourceMarginLeft = 18;
    int sourceMarginBottom = 18;
    int sourceMarginTop = 0;
    // Put the sources on screen
    for ( int i = 0; i < 9; i++ ) {
        stackSourceBlack[i] = new QGraphicsPixmapItem(blackSourcePixmap);
        stackSourceWhite[i] = new QGraphicsPixmapItem(whiteSourcePixmap);
        stackSourceWhite[i]->setPos( sourceMarginLeft, 600 - sourceMarginBottom - whiteSourcePixmap.height() - (i * (whiteSourcePixmap.height() + sourceMarginTop) ) );
        stackSourceBlack[i]->setPos( 800 - sourceMarginLeft - blackSourcePixmap.width(), 600 - sourceMarginBottom - blackSourcePixmap.height() - (i * (blackSourcePixmap.height() + sourceMarginTop) ) );
        board->addItem( stackSourceBlack[i] );
        board->addItem( stackSourceWhite[i] );
    }

    // Recursivly empty the animation stack
    connect(pieceAnimation, SIGNAL(finished()), this, SLOT(animate()));

    // Put control buttons on screen
    QPixmap imgPlay(":/buttons/play_button.png");
    QPixmap imgPause(":/buttons/pause_button.png");
    QPixmap imgStop(":/buttons/stop_button.png");
    playButton = new ControlButton(imgPlay);
    pauseButton = new ControlButton(imgPause);
    stopButton = new ControlButton(imgStop);
    board->addItem(playButton);
    board->addItem(pauseButton);
    board->addItem(stopButton);
    playButton->setPos(738, 14);
    pauseButton->setPos(762, 14);
    stopButton->setPos(786, 14);
}


GameView::~GameView()
{
    for( int i =0; i<24; i++ ) {
        delete vertexPiece[i];
        delete vertexItems[i];
    }
    delete currentPlayerText;
    delete errorMessage;
    delete playButton;
    delete pauseButton;
    delete stopButton;
    delete pieceAnimation;
    delete selectedPiece;
    for( int i = 0; i < 9; i++ ) {
        delete stackSourceBlack[i];
        delete stackSourceWhite[i];
    }
}
void GameView::showMovement(Movement movement)
{
    Animation anim;

    // Do the movement on the screen
    // Assuming that the "to" field can never be a source


    // If there isn't a deletion, or the movement wasn't showed yet
    if ( !(movement.flagShowed && movement.erase != 0) ) {
        anim.from = movement.from;
        anim.to = movement.to;
        anim.type = (movement.from > 0 ) ? ANIMATION_MOVE : ANIMATION_PLACE;

        animationStack.push_front( anim );
    }

    if ( movement.erase != 0) {
        anim.from = movement.erase;
        anim.to = movement.erase;
        anim.type = ANIMATION_DELETE;

        animationStack.push_front( anim );
    }

    animate();
}

void GameView::onSetPlayer(int player)
{
    if ( player == GameController::PLAYER_BLACK )
        currentPlayerText->setHtml("<span style=\"color:#bb0052;text-align:center;\">Turno del jugador Fucsia</span>");
    else
        currentPlayerText->setHtml("<span style=\"color:#fff;text-align:center;\">Turno del jugador Blanco</span>");
}

void GameView::showError( std::string text )
{
    QString output = "<span style=\"color:#fd0;width:100%;font-family:Arial;font-size:14px;font-style:italic;font-weight:bold;\"><center>" + QString().fromStdString( text ) + "</center></span>";
    errorMessage->setHtml( output );
    QVariant opacity =  errorMessage->property("opacity");
    if( opacity.value<double>() !=1 ) {
        errorAnimation = new QPropertyAnimation(errorMessage, "opacity");
        errorAnimation->setStartValue(0);
        errorAnimation->setEndValue(1);
        errorAnimation->setDuration(100);
        errorAnimation->start(QPropertyAnimation::DeleteWhenStopped);
    }
}

void GameView::clearError()
{
    QVariant opacity =  errorMessage->property("opacity");
    if( opacity.value<double>() !=0 ) {
        errorAnimation = new QPropertyAnimation(errorMessage, "opacity");
        errorAnimation->setStartValue(1);
        errorAnimation->setEndValue(0);
        errorAnimation->setDuration(250);
        errorAnimation->start(QPropertyAnimation::DeleteWhenStopped);
    }
}

void GameView::animate()
{
    if ( !animationStack.empty() ) {
        Animation animation = animationStack.back( );
        animationStack.pop_back();
        // Convert the vertex id to the internal array key
        int intIdFrom = animation.from - 1;
        int intIdTo = animation.to - 1;


        switch ( animation.type ) {
        case ANIMATION_PLACE:

            // Put the piece on the destination
            if ( animation.from == GameModel::SOURCE_BLACK )
                vertexPiece[ intIdTo ] = new PieceItem( GameController::PLAYER_BLACK );
            else
                vertexPiece[ intIdTo ] = new PieceItem( GameController::PLAYER_WHITE );

            // Connect the piece
            connect( this, SIGNAL(triggerUpdateSelect(int)), vertexPiece[ intIdTo ], SLOT(onUpdateSelected(int)) );

            // Show the piece
            board->addItem( vertexPiece[ intIdTo ] );
            vertexPiece[intIdTo]->setPos(staticVertexPositions[intIdTo].first, staticVertexPositions[intIdTo].second);

            // Tell the piece which is its position
            vertexPiece[ intIdTo ]->setData(GameView::KEY_VERTEX_ID, animation.to);

            // Execute the animation
            vertexPiece[ intIdTo ]->animateAppear( pieceAnimation );
            break;

        case ANIMATION_MOVE:
            // Switch data and pointers
            vertexPiece[intIdTo] = vertexPiece[ intIdFrom ];
            vertexPiece[ intIdFrom ] = NULL;
            vertexPiece[ intIdTo ]->setData( KEY_VERTEX_ID, animation.to );

            vertexPiece[ intIdTo ]->animateMove( pieceAnimation, staticVertexPositions[intIdFrom].first, staticVertexPositions[intIdFrom].second, staticVertexPositions[intIdTo].first, staticVertexPositions[intIdTo].second);

            break;

        case ANIMATION_DELETE:
            disconnect( this, SIGNAL(triggerUpdateSelect(int)), vertexPiece[ intIdTo ], SLOT(onUpdateSelected(int)) );
            vertexPiece[ intIdTo ]->animateDelete( pieceAnimation );

            connect(pieceAnimation, SIGNAL(finished()), vertexPiece[intIdTo], SLOT(onDeleteEnd()) );
            vertexPiece[ intIdTo ] = NULL;

            break;
        default:
            break;
        }
        // Recursion with auto-signal pieceAnimation->finished();
    } else
        triggerAnimationEnd();
}

void GameView::popSourcePiece(int player)
{
    switch ( player ) {
    case GameController::PLAYER_BLACK:
        for ( int i = 8; i >= 0; i-- )
            if ( stackSourceBlack[i] != NULL ) {
                delete stackSourceBlack[i];
                stackSourceBlack[i] = NULL;
                return;
            }
        break;
    case GameController::PLAYER_WHITE:
        for ( int i = 8; i >= 0; i-- )
            if ( stackSourceWhite[i] != NULL ) {
                delete stackSourceWhite[i];
                stackSourceWhite[i] = NULL;
                return;
            }
        break;
    }
}


void GameView::mousePressEvent( QMouseEvent *event )
{
    // Returns the vertex id, below the mouse
    QGraphicsItem *clicked = board->itemAt( event->pos(), QTransform() );
    QVariant getData = clicked->data( KEY_VERTEX_ID );

    int id = getData.value<int>();

    if ( id != 0 ) {
        this->triggerUpdateSelect( id );
        this->triggerVertexClick( id );
    }
}

