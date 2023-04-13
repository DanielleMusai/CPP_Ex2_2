#include "game.hpp"
#include "card.hpp"
#include <algorithm>
#include <stdexcept>
#include <random>
#include <string>
#include <vector>

namespace ariel {

Game::Game(Player& p1, Player& p2) : player1(p1), player2(p2),draw(0) {
    std::vector<Card> cards;
    for (int i = 1; i <= 13; i++) {
        cards.push_back(Card(Suit::HEARTS, static_cast<Rank>(i)));
        cards.push_back(Card(Suit::DIAMONDS, static_cast<Rank>(i)));
        cards.push_back(Card(Suit::CLUBS, static_cast<Rank>(i)));
        cards.push_back(Card(Suit::SPADES, static_cast<Rank>(i)));
    }

    std::random_device rd;
    std::default_random_engine g_(rd());
    std::shuffle(cards.begin(), cards.end(), g_); // taking from the internet 
    deck = std::deque<Card>(cards.begin(), cards.end());

    for (int i = 0; i < 26; i++) {
        player1.addCard(deck.front());
        deck.pop_front();
        player2.addCard(deck.front());
        deck.pop_front();
    }
}


void Game::playTurn() {
    if (&player1 == &player2) {
        throw std::invalid_argument("Player cannot play against himself");
    }
    if (player1.stacksize() == 0 || player2.stacksize() == 0) {
        throw std::invalid_argument("Player has no more cards to play with");
    }
    
    Card card1 = player1.removeCard();
    Card card2 = player2.removeCard();
    log.push_back(std::make_pair(card1, card2));
    
    if (card1 > card2) {
        player1.addCards({card1, card2});
    } else if (card2 > card1) {
        player2.addCards({card1, card2});
    } else {
        std::vector<Card> pair = {card1, card2};
        while (card1 == card2) {
            if (player1.stacksize() == 0 || player2.stacksize() == 0) {
                break;
            }
            draw++;
            pair.push_back(player1.removeCard());
            pair.push_back(player2.removeCard());
            if (player1.stacksize() == 0 || player2.stacksize() == 0) {
                break;
            }
            card1 = player1.removeCard();
            card2 = player2.removeCard();
            if (card1 == card2) {
             /*
             players draw identical cards, place one card face down and another card on top of it.
             The high card player takes all six cards
             */
                draw++;
                pair.push_back(card1);
                pair.push_back(card2);
                pair.push_back(player1.removeCard());
                pair.push_back(player2.removeCard());
                if (card1 > card2) {
                    player1.addCards(pair);
                } else {
                    player2.addCards(pair);
                }
                break;
            }
            pair.push_back(card1);
            pair.push_back(card2);
        }
        if (card1 > card2) {
            player1.addCards(pair);
        } else if (card2 > card1) {
            player2.addCards(pair);
        } else {
            // both players have run out of cards while breaking a tie, split the pot
            player1.addCards(pair);
            player2.addCards(pair);
        }
    }
}




void Game::playAll() {
    while (player1.stacksize() > 0 && player2.stacksize() > 0) {
        try {
            playTurn();
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
            break;
        }
    }
}


void Game::printWiner() const {
    int p1cardsTaken = player1.cardesTaken();
    int p2cardsTaken = player2.cardesTaken();
    if (p1cardsTaken > p2cardsTaken) {
        std::cout << player1.getName() << " Wins!" << std::endl;
    } else if (p2cardsTaken > p1cardsTaken) {
        std::cout << player2.getName() << " Wins!" << std::endl;
    } else {
        std::cout << "Its a tie!" << std::endl;
    }
}




void Game::printLog() const {
    //int i = 0;
    for (auto& turn : log) {
        //std::cout << i++ << std::endl;
        std::cout << player1.getName() << " played " << turn.first.toString() << std::endl;
        std::cout << player2.getName() << " played " << turn.second.toString() << std::endl;
    }
}

void Game::printLastTurn() const {
    auto lastPair = log.back();
    std::cout << lastPair.first.toString() << " VS. " << lastPair.second.toString() << std::endl;
}

void Game::printStats() const {
    int totalTurns = log.size();
    int totalCardsTaken = player1.cardesTaken() + player2.cardesTaken();
    double draw_rate = (double)draw * 2;

    // Print player stats
    std::cout << player1.getName() << ":" << std::endl;
    std::cout << "  Win rate: " << (player1.cardesTaken() * 100.0 / totalCardsTaken) << "%" << std::endl;
    std::cout << "  Cards won: " << player1.cardesTaken()  << std::endl;
   

    std::cout << player2.getName() << ":" << std::endl;
    std::cout << "  Win rate: " << (player2.cardesTaken() * 100.0 / totalCardsTaken) << "%" << std::endl;
    std::cout << "  Cards won: " << player2.cardesTaken() << std::endl;

    std::cout << "Draw rate: " << draw_rate * 100 / totalCardsTaken << "%" << std::endl;
    std::cout << "Number of draws: " << draw << "\n";

 
}



void Game::printPlayerStats() const {
    std::cout << player1.getName() << " has " << player1.stacksize() << " cards left" << std::endl;
    std::cout << player2.getName() << " has " << player2.stacksize() << " cards left" << std::endl;
    std::cout << player1.getName() << " has taken " << player1.cardesTaken() << " cards" << std::endl;
    std::cout << player2.getName() << " has taken " << player2.cardesTaken() << " cards" << std::endl;
}
}


