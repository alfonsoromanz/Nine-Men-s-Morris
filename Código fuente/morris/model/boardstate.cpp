#include "../controller/gamecontroller.h"

// Constructor
BoardState::BoardState()
{
    int vertex = 0;

    // Initialice with statics values the conection's matrix with a right desplazament
    for ( int j = 0; j < 3; j++ )
        for ( int k = 1; k < 9; k++ ) {
            conections[j][ k % 8 ] = ++vertex;
        }

    clear();

}

void BoardState::clear()
{

    // Initialice all the vertex as empty
    for ( int i = 0; i < 24; i++ )
        contentMap[i] = GameController::PLAYER_NULL;

    sourceWhite = 9;
    sourceBlack = 9;
    boardWhite = 0;
    boardBlack = 0;
}


int BoardState::getVertexState(int vertex) const
{
    return contentMap[ vertex - 1 ];
}

int BoardState::getTotalByColour(int colour)
{

    if( colour == GameController::PLAYER_BLACK )
        return boardBlack + sourceBlack;
    else if( colour == GameController::PLAYER_WHITE )
        return boardWhite + sourceWhite;
    else
        return 24 - boardBlack - boardWhite;
}

int BoardState::getSourceByColour(int colour) const
{
    return (colour == GameController::PLAYER_BLACK) ? sourceBlack : sourceWhite;
}

std::list<int> BoardState::getPiecesByColour(int colour)
{
    std::list<int> vertexes;
    for ( int i = 0; i < 24; i++ )
        if ( contentMap[i] == colour )
            vertexes.push_back( i + 1 );

    return vertexes;
}

std::pair<int, int> BoardState::getVertexPosition(int vertex)
{
    // works with the real vertex id (1..24)
    int column, row;
    std::pair<int, int> position;
    // Calculate the position of a vertex in the conection's matrix
    row = ((vertex - 1) / 8 );
    column = vertex % 8;

    position.first = row;
    position.second = column;

    return position;
}

std::list<int> BoardState::getAdyacents(int vertex)
{
    std::pair<int, int> position;
    bool pairColumn;
    std::list<int> adyacents;

    // Depending of the column's parity, the limiting fields are adyacents or not
    position = getVertexPosition(vertex);
    pairColumn = !(position.second % 2);
    if ( pairColumn ) {
        // Add the next and previous field (horizontally) cyclically (without overflow)
        adyacents.push_back( conections[position.first][ (8 + (position.second - 1) ) % 8] );
        adyacents.push_back( conections[position.first][ (position.second + 1) % 8] );

    } else {
        // Add the next and previous field cyclically (without overflow)
        adyacents.push_back( conections[position.first][ (8 + position.second - 1) % 8] );
        adyacents.push_back( conections[position.first][ (position.second + 1) % 8] );

        // Add the next and previous field (vertically)
        if (position.first > 0)
            adyacents.push_back( conections[position.first - 1][ position.second ] );
        if (position.first < 2)
            adyacents.push_back( conections[position.first + 1][ position.second ] );
    }
    return adyacents;
}

std::list<std::pair<int, int> > BoardState::getMillsAdyacents(int vertex)
{
    std::pair<int, int> position;
    bool pairColumn;
    std::list<std::pair<int, int> > adyacents;
    std::pair<int, int> aux;

    // Depending of the column's parity, the limiting fields are adyacents or not
    position = getVertexPosition(vertex);
    pairColumn = !(position.second % 2);

    if ( pairColumn ) {
        // Add the 2 next and 2 previous fields (horizontally) cyclically (without overflow)
        aux.first = conections[position.first][ (8 + position.second - 1) % 8];
        aux.second = conections[position.first][ (8 + position.second - 2) % 8];
        adyacents.push_back( aux );


        aux.first = conections[position.first][ (position.second + 1) % 8];
        aux.second = conections[position.first][ (position.second + 2) % 8];
        adyacents.push_back( aux );
    } else {
        // Add the next and previous field cyclically (without overflow)
        aux.first = conections[position.first][ (8 + position.second - 1) % 8];
        aux.second = conections[position.first][ (position.second + 1) % 8];
        adyacents.push_back( aux );
        bool firsting = true;

        // Add the whole column
        for ( int i = 0; i < 3; i++)
            if ( i != position.first )
                if (firsting) {
                    aux.first = conections[i][ position.second ];
                    firsting = false;
                } else {
                    aux.second = conections[i][ position.second ];
                }

        adyacents.push_back( aux );
    }

    return adyacents;
}

void BoardState::extractPieceAtVertex(int vertex)
{
    if ( vertex == GameModel::SOURCE_BLACK )
        sourceBlack--;
    else if ( vertex == GameModel::SOURCE_WHITE )
        sourceWhite--;
    else {
        int colour = contentMap[ vertex - 1 ];

        if( colour == GameController::PLAYER_BLACK )
            boardBlack--;
        else if( colour == GameController::PLAYER_WHITE )
            boardWhite--;

        contentMap[ vertex - 1 ] = GameController::PLAYER_NULL;

    }
}

void BoardState::insertPieceAtVertex(int vertex, int colour)
{
    contentMap[ vertex - 1] = colour;

    if( colour == GameController::PLAYER_BLACK )
        boardBlack++;
    else if( colour == GameController::PLAYER_WHITE )
        boardWhite++;
}

