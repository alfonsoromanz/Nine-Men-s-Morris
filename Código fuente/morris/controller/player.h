#ifndef PLAYER_H
#define PLAYER_H


/*!
 * \class Player
 *
 * ADT of human configuration.
 */
class Player {
private:

    bool human;//!< Player virtuality (Human or virtual).

    int heuristic;
    int deep;

public:

    static const bool PLAYER_HUMAN = 0x01;
    static const bool PLAYER_VIRTUAL = 0x00;

    Player();

    // Operator =, setters and getters
    void operator= (const Player &otherPlayer);

    void setVirtuality(bool human);
    bool getVirtuality();

    void setHeuristic(int heuristic);
    int getHeuristic();

    void setDeep(int deep);
    int getDeep();

};
#endif
