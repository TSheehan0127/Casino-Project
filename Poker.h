//
// Created by Tyler Sheehan on 2/20/25.
//

#ifndef POKER_H
#define POKER_H
#include "Game.h"


//this will be a very simplified version of Texas holdem poker.
//there will be no betting and the player will have an option of folding every time a card is drawn.
//the game will only consist of a player and a dealer.

class Poker: public Game {
private:
    //two cards will be given to the player and dealer.
    vector<Card> playerHand;
    vector<Card> dealerHand;

    //the table will consist of the flop, turn, and then river
    vector<Card> table;

    vector<string> hands = {"highCard","pair","two pair", "three of a kind",
        "straight", "flush", "full house", "four of a kind",
        "straight flush", "royal flush"}; // vector of all the hands obtained in poker.

public:
    //constructor.
    Poker();

    //calculateHand method, will determine the current value of a players hand in poker.
    int calculateHand(vector<Card> &hand) override;

    //main function of program, allows for user input.
    void play() override;

    //getters for player and dealers hand
    vector<Card> &getPlayerHand();
    vector<Card> &getDealerHand();

    //getter for table
    vector<Card> &getTable();

    //getter for hands, h
    vector<string> getHands();

    //setters for player and dealers hand
    void setPlayerHand(const vector<Card> &hand);
    void setDealerHand(const vector<Card> &hand);

    //setter for table
    void setTable(const vector<Card> &newTable);

};



#endif //POKER_H
