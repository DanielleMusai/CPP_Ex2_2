#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "card.hpp"


namespace ariel
{
class Player
{
private:
    std::string name;
public:
    Player(std::string name);
    Player(){}
    int stacksize();
    int cardesTaken();
//player::~player()
//{
//}
};
}
#endif /* PLAYER_H */