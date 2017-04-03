#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>
#include <QMouseEvent>
#include "../controller/movement.h"
#include "vertexitem.h"
#include "pieceitem.h"
#include <QPropertyAnimation>
#include "controlbutton.h"

/*!
 * \class GameView
 *
 * Generate the user interface, manage the animations and derive the user clicks.
 * Instances of this class can be displayed as widgets.
 */
class GameView : public QWidget {
    Q_OBJECT
private:


    // Type of animations to show
    static const int ANIMATION_MOVE = 0x0;
    static const int ANIMATION_DELETE = 0x1;
    static const int ANIMATION_PLACE = 0x2;


    /*!
     * \class Animation
     * Structure to contain animation information.
     */
    class Animation {
    public:
        int from;
        int to;
        int type;
        Animation() {
            this->from = 0;
            this->to = 0;
            this->type = ANIMATION_DELETE;
        }
        void operator= (const Animation &other) {
            this->from = other.from;
            this->to = other.to;
            this->type = other.type;
        }
    };


    std::list< Animation > animationStack; //!< Queue of animations to show.

    PieceItem *vertexPiece[24]; //!< Pieces references (pointers).

    VertexItem *vertexItems[24]; //!< The vertexes references, used in destructor and necesary to maintain the object on the screen.

    QGraphicsTextItem *currentPlayerText; //!< Text output.
    QGraphicsTextItem *errorMessage; //!< Text output.

    // The graphicals items
    QGraphicsView *view;
    QGraphicsScene *board;


    QGraphicsPixmapItem *background;//!< The Background Image

    std::pair<int, int> staticVertexPositions[24]; //!< The relative/theoric position of vertexes on screen.

    QPropertyAnimation *pieceAnimation; //!< Handler of piece's animations.
    QPropertyAnimation *errorAnimation; //!< Handler of error's animations.

    PieceItem *selectedPiece; //!< Reference to the current selected piece.

    QGraphicsPixmapItem *stackSourceBlack[ 9 ]; //!< Source graphic representation.
    QGraphicsPixmapItem *stackSourceWhite[ 9 ]; //!< Source graphic representation.

public slots:
    void showMovement(Movement movement);
    void onSetPlayer(int player);
    void showError( std::string text );
    void clearError( );
    void animate();//!< Allows recursive chains of animations
    void popSourcePiece( int player );

signals:
    void triggerVertexClick(int vertex);
    void triggerAnimationEnd();
    void triggerUpdateSelect( int id );

protected:
    void mousePressEvent(QMouseEvent *event);

public:
    /*!
     * Constructor
     */
    explicit GameView(QWidget *parent = 0);

    static const int KEY_VERTEX_ID = 0x0; //!<Key to read/save the vertex id data.

    // The control buttons
    ControlButton * playButton;
    ControlButton * pauseButton;
    ControlButton * stopButton;

    ~GameView();

};
#endif
