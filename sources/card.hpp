#pragma once

#include <string>

namespace ariel {

    class Card {

        private:
            std::string suit;
            std::string rank;
            int value;

        public:
            Card(std::string suit, std::string rank, int value);
            std::string getSuit() const;
            std::string getRank() const;
            int getValue() const;
            bool operator<(const Card& other) const;

    };

}
