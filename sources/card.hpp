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
    TWO = 2,
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
    KING,
    ACE = 1
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
            /*
            the friend keyword is used to give a non-member 
            function or class access to the private and protected members of another class
            the operator<< function needs to access the private members
            suit_ and rank_ in order to generate the output string 
            */
            friend std::ostream& operator<<(std::ostream& outputStream, const Card& card);

     private:
           Suit suit_;
           Rank rank_;
};
    }


#endif