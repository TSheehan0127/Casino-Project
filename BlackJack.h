//
// Created by Tyler Sheehan on 2/19/25.
//

#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Game.h"
#include <vector>


class BlackJack: public Game {
private:
    //two vectors are created. the player hand and vector hand.
    vector<Card> playerHand;
    vector<Card> dealerHand;
public:
    BlackJack();

    //determines players current hand value in blackJack.
    int calculateHand(vector<Card> &hand) override;

    //main method that activates user input, will run the game in the console.
    void play() override;

    //getters for player and dealers hand
    vector<Card> &getPlayerHand();
    vector<Card> &getDealerHand();

    //setters for player and dealers hand
    void setPlayerHand(const vector<Card> &hand);
    void setDealerHand(const vector <Card> &hand);


};



#endif //BLACKJACK_H
