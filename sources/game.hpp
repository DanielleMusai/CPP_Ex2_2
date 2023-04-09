#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "card.hpp"
#include <vector>
#include <deque>
#include <iostream>
#include <string>

namespace ariel {

class Game {
private:
    Player& player1;
    Player& player2;
    std::deque<Card> deck;
    std::vector<std::pair<Card, Card>> log;
public:
    Game(Player& p1ayer1, Player& player2);
    void playTurn();
    void playAll();
    void printWiner() const;
    void printLog() const;
    void printLastTurn() const;
    void printStats() const;
    void printPlayerStats() const;
};

} // namespace ariel

#endif // GAME_HPP
