//
// Created by Tyler Sheehan on 2/19/25.
//

#include "Game.h"
using namespace std;

//instantiates the deck object again resetting the deck back to 52 cards.
void Game::resetDeck() {
    deck = Deck();
}

Deck& Game::getDeck() {
    return deck;
}

bool Game::getWin() {
    return win;
}


