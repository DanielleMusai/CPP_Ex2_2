#include <vector>
#include <string>
#include "player.hpp"

namespace ariel
{
class Game
{
private:
   Player& m_player1;
   Player& m_player2;
 

public:
    Game(Player& m_player1,Player& m_player2);
    
    void playTurn();
    void playAll();
    void printWiner() const;
    void printLog() const;
    void printLastTurn() const;
    void printStats() const;
    void printPlayerStats() const;
};
}

  