//
// Created by Tyler Sheehan on 2/19/25.
//

#include "BlackJack.h"
#include <iostream>

BlackJack::BlackJack() {
    //adds two cards to the player hand.
    playerHand.push_back(deck.drawCard());
    playerHand.push_back(deck.drawCard());

    //adds two cards to the dealers hand.
    dealerHand.push_back(deck.drawCard());
    dealerHand.push_back(deck.drawCard());
}


int BlackJack::calculateHand(vector<Card> &hand){
    int total = 0;
    int aces = 0;
    //iterates through hand and retrieves value of each card.
    for (Card card : hand) {
        total += card.getValue();
        //checks if a card is an ace.
        if (card.rank == ACE) {
            aces += 1;
        }
    }
    // sets ace to be a value of 1 if player hits above 21 with an ace.
    while (total > 21 && aces > 0) {
        total -= 10;
        aces--;
    }

    //returns the total.
    return total;
}

void BlackJack::play() {
    cout << "playing black jack now." << endl;
    cout<< "Dealing cards..." << endl;

    cout<<"Dealers shown card: "<<endl;
    dealerHand[1].displayCard();

    //displays both of the players card.
    cout<<"your hand: "<<endl;
    playerHand[0].displayCard();
    playerHand[1].displayCard();
    cout<<"Your total: "<< calculateHand(playerHand) <<endl;

    //variable used to define if a player or dealer has busted.
    bool playerBusted = false, dealerBusted = false;

    //loop that handles if player should hit or stay.
    while (true) {
        string playerDecision;
        cout<<"Hit (h) or Stay? (s): ";
        getline(cin, playerDecision);

        //checks if player hit
        if (playerDecision == "h") {
            //retrieves a new card from the deck.
            playerHand.push_back(deck.drawCard());
            cout <<"Player draws ";
            //displays new card and total amount
            playerHand.back().displayCard();
            cout <<"Your new total is "<<calculateHand(playerHand)<<endl;

            //checks if player busted
            if (calculateHand(playerHand) > 21) {
                cout<<"bust, Player loses."<<endl;
                playerBusted = true;
                break;
            }

        } else if (playerDecision == "s") {
            cout<<"player stays"<<endl;
            break;
        } else {
            cout<<"please enter a valid character."<<endl;
        }
    }

    //statement only runs if player hasn't busted
    if(!playerBusted) {
        //dealers turn begins.
        cout<<"Dealers turn."<<endl;
        cout<<"Dealers reveals first card:"<<endl;
        //reveals their first card.
        dealerHand[0].displayCard();

        //loop only runs if hand total for the dealer is less than 17
        //will make the dealer keep hitting until they are between 17 and 21
        while(calculateHand(dealerHand) < 17 ) {
            cout<<"Dealer hits, "<<endl;
            //dealer draws a new card and displays it to the console
            dealerHand.push_back(deck.drawCard());
            cout<<"Dealer draws ";
            dealerHand.back().displayCard();
            cout <<"Dealers new total is "<<calculateHand(dealerHand)<<endl;

            //checks if dealer has busted
            if (calculateHand(dealerHand) > 21) {
                cout << "Dealer busted player wins" << endl;
                dealerBusted = true;
                break;
            }
        }
        //once loop is done running dealer says, only if they haven't already busted.
        if (!dealerBusted) {
            cout <<"Dealer stays"<<endl;
        }
    }
    //using game logic to determine winner.
    if (!playerBusted && !dealerBusted) {
        //checks if player hand is greater than dealer hand
        if(calculateHand(playerHand) > calculateHand(dealerHand)) {
            win = true;
            cout<< "player wins! "<<calculateHand(playerHand) <<" is greater than "<<calculateHand(dealerHand)<<endl;
            // checks if both hands are equal, results in a draw, win = false.
        }else if (calculateHand(playerHand) == calculateHand(dealerHand)) {
            cout<<" Game is a tie! both player and Dealer have a value of "<<calculateHand(dealerHand)<<endl;
            // then determines that the dealer is a winner if both other statements fail.
        }else {
            cout<< "Dealer wins! "<<calculateHand(dealerHand) <<" is greater than "<<calculateHand(playerHand)<<endl;
        }
    }
}

//retrieves player hand.
vector<Card> &BlackJack::getPlayerHand() {
    return playerHand;
}

//retrieves dealer hand.
vector<Card> &BlackJack::getDealerHand() {
    return dealerHand;
}

//sets players hand to new vector
void BlackJack::setPlayerHand(const vector<Card> &hand) {
    playerHand = hand;
}

//sets dealers hand to new vector
void BlackJack::setDealerHand(const vector<Card> &hand) {
    dealerHand = hand;
}




