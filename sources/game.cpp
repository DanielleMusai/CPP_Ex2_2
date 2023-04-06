#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "game.hpp"
using namespace std;
using namespace ariel;

namespace ariel
{
Game::Game(Player& p1, Player& p2) : m_player1(p1), m_player2(p2) {}
void Game::playTurn(){}
void Game::playAll(){}
void Game::printWiner() const {}
void Game::printLog() const {}
void Game::printLastTurn() const {}
void Game::printStats() const {}
void Game::printPlayerStats() const {}
}

