//
// Created by Tyler Sheehan on 2/1/25.
//

#ifndef CARD_H
#define CARD_H


enum Suit {HEARTS, DIAMONDS, CLUBS, SPADES};
enum Rank {TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK = 11, QUEEN, KING, ACE = 14};

class Card {
  public:
    Suit suit;
    Rank rank;

    //constructor for card class
    Card(Suit s, Rank r);

    //method returns the value of the card given
    int getValue() const;

    //displays information of the card at hand.
    void displayCard() const;

    //overload operator, used to check if a card is greater than or less than
    bool operator>(const Card& other) const;

    bool operator<(const Card& other) const;

    //overload operator, checks if a cards suit and rank is equal to another cards suit and rank
    bool operator==(const Card& other) const;
};



#endif //CARD_H
