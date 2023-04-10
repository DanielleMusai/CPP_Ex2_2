#include "player.hpp"
#include <algorithm>
#include <stdexcept>
#include <random>

namespace ariel {

Player::Player(const std::string& name) : name(name) {}


const std::string Player::getName() const {
    return name;
}


int Player::stacksize() const {
    return stack.size();
}

int Player::cardesTaken() const {
    return cardsTaken.size();
}

void Player::addCard(const Card& card) {
    stack.push_back(card);
}

Card Player::removeCard() {
    if (stack.empty()) {
        throw std::runtime_error("Player has no more cards to play.");
    }
    Card card = stack.back();
    stack.pop_back();
    return card;
}



void Player::addCards(const std::vector<Card>& cards) {
    for (const Card& card : cards) {
        cardsTaken.push_back(card);
    }
}



}
