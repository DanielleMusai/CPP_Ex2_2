#include "card.hpp"
#include <string>

namespace ariel {

Card::Card(Suit suit, Rank rank) : suit_(suit), rank_(rank) {}

Suit Card::getSuit() const {
    return suit_;
}

Rank Card::getRank() const {
    return rank_;
}

std::string Card::toString() const {
    std::string suitStr;
    switch(suit_) {
        case Suit::HEARTS:
            suitStr = "Hearts";
            break;
        case Suit::DIAMONDS:
            suitStr = "Diamonds";
            break;
        case Suit::CLUBS:
            suitStr = "Clubs";
            break;
        case Suit::SPADES:
            suitStr = "Spades";
            break;
    }
    
    std::string rankStr;
    switch(rank_) {
        case Rank::ACE:
            rankStr = "Ace";
            break;
        case Rank::TWO:
            rankStr = "Two";
            break;
        case Rank::THREE:
            rankStr = "Three";
            break;
        case Rank::FOUR:
            rankStr = "Four";
            break;
        case Rank::FIVE:
            rankStr = "Five";
            break;
        case Rank::SIX:
            rankStr = "Six";
            break;
        case Rank::SEVEN:
            rankStr = "Seven";
            break;
        case Rank::EIGHT:
            rankStr = "Eight";
            break;
        case Rank::NINE:
            rankStr = "Nine";
            break;
        case Rank::TEN:
            rankStr = "Ten";
            break;
        case Rank::JACK:
            rankStr = "Jack";
            break;
        case Rank::QUEEN:
            rankStr = "Queen";
            break;
        case Rank::KING:
            rankStr = "King";
            break;
    }
    
    return rankStr + " of " + suitStr;
}

bool Card::operator>(const Card& other) const {
    return this->rank_ > other.rank_;
}

bool Card::operator<(const Card& other) const {
    return this->rank_ < other.rank_;
}

bool Card::operator==(const Card& other) const {
    return this->rank_ == other.rank_;
}

std::ostream& operator<<(std::ostream& outputStream, const Card& card) {
    outputStream << card.toString();
    return outputStream;
}

}
