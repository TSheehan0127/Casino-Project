//
// Created by Tyler Sheehan on 2/19/25.
//

#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Card.h"


//Abstract super class that will be used for Black Jack and Poker
class Game {
protected:
    //contains 2 fields, a win boolean and a deck of cards
    bool win = false;
    Deck deck;

public:
    //constructor for Game, A deck of cards and win are set by default.
    Game() = default;
    virtual ~Game() = default;

    //resets the deck class to be 52 cards again randomly shuffled.
    virtual void resetDeck();

    //the main functionality of current game, takes in player input.
    virtual void play() = 0;

    //determines for blackJack and Poker the players current hand.
    virtual int calculateHand(vector<Card> &hand) = 0;

    //getter for win
    bool getWin();

    //getter for a card Deck
    Deck& getDeck();

};



#endif //GAME_H
