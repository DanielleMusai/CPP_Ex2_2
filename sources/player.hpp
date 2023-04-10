#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "card.hpp"

namespace ariel {

class Player {
private:
    std::string name;
    std::vector<Card> stack;
    std::vector<Card> cardsTaken;
public:
    Player(const std::string& name);
    const std::string getName() const;
    int stacksize() const;
    int cardesTaken() const;
    void addCard(const Card& card);
    Card removeCard();
    void addCards(const std::vector<Card>& cards);
    
};

} 

#endif 