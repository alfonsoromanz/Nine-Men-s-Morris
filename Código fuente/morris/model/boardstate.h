#ifndef BOARD_STATE_H
#define BOARD_STATE_H

#include <list>
/*!
 * \class BoardState
 *
 * ADT, representation of a possible state of the game,
 * including pieces disposition and functionality.
 *
 * Modeled as a graph, implemented with arrays by optimality.
 */
class BoardState {
private:

    int sourceWhite;//!< Number of disponible white pieces (Not placed yet).

    int sourceBlack;//!< Number of disponible black pieces (Not placed yet).

    int boardWhite;//!< Number of white pieces on board
    int boardBlack;//!< Number of white pieces on board

    int contentMap[24]; //!< Disposition of the pieces on the board.
    int conections[3][8]; //!< Graph's conections (arists).

    /*!
     * Return the corresponding position of a vertex in the internal representation of arrays.
     * \param vertex Beetween 1 and 24.
     * \return A pair of integers corresponding with the row and column on the internal array.
     */
    std::pair<int, int> getVertexPosition(int vertex);

public:

    BoardState();

    /*!
     * Clear the current BoardState object
     */
    void clear();


    int getVertexState(int vertex) const; //!< Return the player's colour of the piece at the current vertex.

    int getTotalByColour(int colour); //!< Return the number of pieces from a colour (only in the board!).

    int getSourceByColour( int colour ) const;

    std::list<int> getPiecesByColour(int colour); //!< Return the pieces positions of a colour.

    std::list<int> getAdyacents(int vertex);//!< Return the adyacents vertex in the graph (board) of a particular vertex.


    std::list<std::pair<int, int> > getMillsAdyacents(int vertex); //!< Return the adyacents vertex who are part of the sames mills.


    void extractPieceAtVertex(int vertex);//!< Remove the piece of a vertex or source.


    void insertPieceAtVertex(int vertex, int colour);//!< Insert a piece into a vertex.

    bool operator<(const BoardState &otherState) const;
    bool operator>(const BoardState &otherState) const;
};
#endif
