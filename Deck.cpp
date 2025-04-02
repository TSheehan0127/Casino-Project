//
// Created by Tyler Sheehan on 2/1/25.
//

#include "Deck.h"
#include <random>

using namespace std;

Deck::Deck(){
  //iterates through every suit and rank and adds each card into the deck.

  for (int s = HEARTS; s <= SPADES; s++) {
    for (int r = TWO; r <= ACE; r++) {
      //static cast forces integer to become a Suit and Rank datatype for the Card class
      //link: https://www.geeksforgeeks.org/static_cast-in-cpp/
      cards.push_back(Card(static_cast<Suit>(s),static_cast<Rank>(r)));
    }
  }
  //randomly shuffles cards in the deck.
  shuffleDeck();
}

void Deck::shuffleDeck() {
  random_device rd;
  mt19937 g(rd());

  //method will randomly shuffle the deck.
  shuffle(cards.begin(), cards.end(), g);
}

Card Deck::drawCard() {
  //checks if the deck is empty
  if (!cards.empty()) {
    //takes card at the end of the deck and then removes it from the deck.
    Card drawnCard = cards.back();
    cards.pop_back();
    return drawnCard;
  }
  //throw is used for error handling, main will ensure that the deck is not empty while playing the game.
  throw runtime_error("No more cards are in the deck!");
}

vector<Card>& Deck::getCards() {
  return cards;
}
