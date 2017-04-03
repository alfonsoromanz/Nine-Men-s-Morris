#include "player.h"


Player::Player()
{

}

void Player::operator=(const Player &otherPlayer)
{
    human = otherPlayer.human;
    heuristic = otherPlayer.heuristic;
    deep = otherPlayer.deep;
}

void Player::setVirtuality(bool human)
{
    this->human = human;
}

bool Player::getVirtuality()
{
    return human;
}

void Player::setHeuristic(int heuristic)
{
    this->heuristic = heuristic;
}

int Player::getHeuristic()
{
    return heuristic;
}

void Player::setDeep(int deep)
{
    this->deep = deep;
}

int Player::getDeep()
{
    return deep;
}
