#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <vector>

namespace ariel {

enum class Suit {
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
};

enum class Rank{
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

    class Card {
     public:
            Card(Suit suit, Rank rank);
            Suit getSuit() const;
            Rank getRank() const;
            std::string toString() const;
            bool operator>(const Card& other) const;
            bool operator<(const Card& other) const;
            bool operator==(const Card& other) const;
            friend std::ostream& operator<<(std::ostream& outputStream, const Card& card);
     private:
           Suit suit_;
           Rank rank_;
};
    }


#endif