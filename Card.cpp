//
// Created by Tyler Sheehan on 2/1/25.
//

#include "Card.h"
#include <iostream>
using namespace std;

Card::Card(Suit s, Rank r): suit(s), rank(r) {};

int Card::getValue() const {
    //checks if rank is a number card, returns corresponding number value
    if (rank >= TWO && rank <= TEN) return rank;

    //if the card is a face card aside from ace, returns value of 10
    else if (rank >= JACK && rank <= KING) return 10;

    //if the card is an Ace, it returns a value of 11
    else return 11;
}

//displays information of cards
void Card::displayCard() const {
    //creates a list of the ranks and suits
    string ranks[] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    string suits[] = {"Hearts","Diamonds","Clubs","Spades"};

    //prints out to the console the rank and suit of a card
    cout << ranks[rank - 2] << " of " << suits[suit] << endl;
}


//operators check the value of the cards and returns a boolean
bool Card::operator>(const Card &other) const {
    return this->rank > other.rank;
}

bool Card::operator<(const Card &other) const {
    return this -> rank < other.rank;
}

bool Card::operator==(const Card &other) const {
    if (this->rank == other.rank && this->suit == other.suit) {
        return true;
    }
    return false;
}