//
// Created by Tyler Sheehan on 2/1/25.
//

#ifndef DECK_H
#define DECK_H




#include <iostream>
#include "Card.h"
using namespace std;


class Deck{
private:
  vector<Card> cards;

  public:
    //constructor used to define the vector of cards.
    //by default will contain 52 of all cards.
    Deck();

    //shuffles deck randomly
    void shuffleDeck();

    //returns a card from the deck and removes it from the deck.
    Card drawCard();

    vector<Card>& getCards();
};

#endif //DECK_H