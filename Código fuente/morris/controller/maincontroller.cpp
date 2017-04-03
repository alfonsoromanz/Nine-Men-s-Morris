#include "maincontroller.h"

/*!
 * Initialize the main window and run this.
 *
 * Load the fonts necessaries for the whole application.
 */
MainController::MainController( QApplication *a )
{
    // Saves a reference to the application
    this->app = a;


    // Resources initialization (Load font)
    QFontDatabase::addApplicationFont ( ":/font.ttf" );

    // Main window initialization
    mainWindow.setFixedHeight(600);
    mainWindow.setFixedWidth(800);
    mainWindow.setWindowTitle("Nine Men's Morris");
    mainWindow.show();

    // Start showing the main menu
    show_menu();

}

void MainController::exit_game()
{
    this->app->quit();
}

void MainController::show_menu()
{
    // Get the compiled .ui file
    mainMenu.setupUi( &mainWindow );

    // Set the window's title
    mainWindow.setWindowTitle("Nine Men's Morris");

    // Connect the events
    connect( mainMenu.play, SIGNAL(clicked()), this, SLOT(show_game()) );
    connect ( mainMenu.whitePlayerVirtuality, SIGNAL(currentIndexChanged(int)), this, SLOT (onWhitePlayerVirtualityChanged(int)) );
    connect ( mainMenu.blackPlayerVirtuality, SIGNAL(currentIndexChanged(int)), this, SLOT (onBlackPlayerVirtualityChanged(int)) );

    // Setting default configuration
    onWhitePlayerVirtualityChanged( mainMenu.whitePlayerVirtuality->currentIndex() );
    onBlackPlayerVirtualityChanged( mainMenu.blackPlayerVirtuality->currentIndex() );
}

void MainController::show_game()
{
    // Get the main menu configuration setted by the user
    int bpVirtuality = mainMenu.blackPlayerVirtuality->currentIndex();
    int wpVirtuality = mainMenu.whitePlayerVirtuality->currentIndex();
    int bpHeuristic = mainMenu.blackPlayerHeuristic->value();
    int wpHeuristic = mainMenu.whitePlayerHeuristic->value();
    int bpDeep = mainMenu.blackPlayerDeep->value();
    int wpDeep = mainMenu.whitePlayerDeep->value();
    int starterPlayer = mainMenu.starterPlayer->currentIndex();


    // Make and set the game players
    Player whitePlayer, blackPlayer;
    whitePlayer.setVirtuality( (wpVirtuality == 0) ? Player::PLAYER_HUMAN : Player::PLAYER_VIRTUAL );
    blackPlayer.setVirtuality( (bpVirtuality == 0) ? Player::PLAYER_HUMAN : Player::PLAYER_VIRTUAL );
    whitePlayer.setHeuristic( wpHeuristic );
    blackPlayer.setHeuristic( bpHeuristic );
    whitePlayer.setDeep( wpDeep );
    blackPlayer.setDeep( bpDeep );

    // Initialize the game
    gc = GameController::getInstance();
    gc->setPlayers( whitePlayer, blackPlayer );
    gc->start( (starterPlayer == 0) ? GameController::PLAYER_WHITE : GameController::PLAYER_BLACK );

    // Display the game in the main window
    mainWindow.setCentralWidget( gc->getView() );

    // Connect slots and signals
    connect( gc, SIGNAL(triggerEnd( int )), this, SLOT(show_end_menu( int )) );
}

void MainController::show_end_menu( int winner )
{
    // Get the compiled ui for the board
    endMenu.setupUi( &mainWindow );

    // Set the window's title
    mainWindow.setWindowTitle("Nine Men's Morris");

    // Set the winner message
    switch ( winner ) {
    case GameController::PLAYER_BLACK:
        endMenu.result->setStyleSheet( "color:#BB0052; text-align:center; font-size:48pt; font-family:\"AngryBirds\";" );
        endMenu.result->setText("Ha ganado el jugador Fucsia");
        break;
    case GameController::PLAYER_WHITE:
        endMenu.result->setStyleSheet( "color:#FFFFFF; text-align:center; font-size:48pt; font-family:\"AngryBirds\";" );
        endMenu.result->setText("Ha ganado el jugador Blanco");
        break;
    default:
        endMenu.result->setStyleSheet( "color:#FFFFFF; text-align:center; font-size:48pt; font-family:\"AngryBirds\";" );
        endMenu.result->setText("Juego terminado");
        break;
    }

    // Connect the events
    connect( endMenu.exit_button, SIGNAL(clicked()), this, SLOT(exit_game()) );
    connect( endMenu.back, SIGNAL(clicked()), this, SLOT(show_menu()) );
}

void MainController::onWhitePlayerVirtualityChanged( int value )
{
    if (value == 0) {
        mainMenu.whitePlayerDeep->setEnabled(false);
        mainMenu.whitePlayerHeuristic->setEnabled(false);
    } else {
        mainMenu.whitePlayerDeep->setEnabled(true);
        mainMenu.whitePlayerHeuristic->setEnabled(true);
    }
}

void MainController::onBlackPlayerVirtualityChanged( int value )
{
    if (value == 0) {
        mainMenu.blackPlayerDeep->setEnabled(false);
        mainMenu.blackPlayerHeuristic->setEnabled(false);
    } else {
        mainMenu.blackPlayerDeep->setEnabled(true);
        mainMenu.blackPlayerHeuristic->setEnabled(true);
    }
}
