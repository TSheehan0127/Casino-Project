//
// Created by Tyler Sheehan on 2/20/25.
//

#include "Poker.h"
#include <algorithm>

//function used for input validation, returns true if player folds, false if stay
bool foldStay() {
    cout<<"would you like to fold(f) or stay(s)?"<<endl;
    string playerDecision;
    getline(cin, playerDecision);
    while(true) {
        if (playerDecision == "f"){
            return true;
        }
        if(playerDecision =="s") {
            return false;
        }
        cout<<"Invalid response try again.";
        getline(cin, playerDecision);
    }
}

Poker::Poker() {
    //provides player and dealer their hands.
    playerHand.push_back(deck.drawCard());
    dealerHand.push_back(deck.drawCard());
    playerHand.push_back(deck.drawCard());
    dealerHand.push_back(deck.drawCard());

    //sets cards out for the table.
    deck.drawCard(); //throws one card out.
    //flop
    table.push_back(deck.drawCard());
    table.push_back(deck.drawCard());
    table.push_back(deck.drawCard());
    deck.drawCard(); //throws out another card.
    //turn
    table.push_back(deck.drawCard());
    deck.drawCard(); //throws out final card.
    //river
    table.push_back(deck.drawCard());
}

//retrieves player hand.
vector<Card> &Poker::getPlayerHand() {
    return playerHand;
}

//retrieves dealer hand.
vector<Card> &Poker::getDealerHand() {
    return dealerHand;
}

//retrieves table:
vector<Card> &Poker::getTable() {
    return table;
}

vector<string> Poker::getHands() {
    return hands;
}



//sets players hand to new vector
void Poker::setPlayerHand(const vector<Card> &hand) {
    playerHand = hand;
}

//sets dealers hand to new vector
void Poker::setDealerHand(const vector<Card> &hand) {
    dealerHand = hand;
}

//sets table
void Poker::setTable(const vector<Card> &newTable) {
    table = newTable;
}

//determines value of hand for player and dealer.
//returns integer value corresponding to the hand.
int Poker::calculateHand(vector<Card> &hand) {
    //creates vector with the table and current hand
    vector<Card> totalHand = hand;
    totalHand.insert(totalHand.end(), table.begin(), table.end());

    //sorts by rank of cards.
    sort(totalHand.begin(),totalHand.end());

    //arrays to count the rank and suit for different types of hands.
    int rankCount[15] = {0}; //takes ranks 2 - 14 (two to ace)
    int suitCount[4] = {0}; //4 different suits: hearts, diamonds, clubs, spades

    //loops through the hand and adds the occurrence of a rank and suit into the arrays.
    for (const Card &card : totalHand) {
        rankCount[card.rank]++;
        suitCount[card.suit]++;
    }

    //checks for flush:
    bool flush = false;
    int suit = -1;
    for (int i =0; i<4; i++) { //iterates through each suit
        if (suitCount[i] >= 5) { //checks if the hand contains more than 5 cards of the same suit.
            flush = true;
            suit = i; // stores the suit.
            break;
        }
    }

    //checks for straight (5 ordered ranks)
    bool straight = false;
    int ordered = 0;
    for(int i = 2; i <= 14; i++) {
        if (rankCount[i] > 0) { // checks if there is a card at rank
            ordered++; // add 1 to order if so
            if(ordered >= 5) { // checks if there are 5 ranks next to each other
                straight = true;
            }
        } else {
            ordered = 0; // if there is no card at the current rank, ordered = 0
        }
    }

    //has to check if the straight is in the flush.
    if(flush){
        //obtains all the cards in the flush.
        vector<int> flushRanks;
        for(const Card &card : totalHand) {
            if (card.suit == suit) {
                flushRanks.push_back(card.rank);
            }
        }

        //sorts all the cards in the flush
        sort(flushRanks.begin(),flushRanks.end());

        //determines if there is a straight in the flush vector
        int flushOrdered = 1;
        int highFlushVal = flushRanks[0]; // obtains highest val card in straight
        for (int i = 1; i< flushRanks.size(); i++) {
            if(flushRanks[i] == flushRanks[i - 1] + 1) {
                flushOrdered++;
                highFlushVal = flushRanks[i];
            } else if (flushRanks[i] != flushRanks[i - 1]){
                //only resets if card is not a duplicate.
                flushOrdered = 1;
            }
        }

        //checks for royal flush
        if (flushOrdered >= 5 && highFlushVal == ACE) {
            return 10;
        }
        //checks for straight flush
        if(flushOrdered >= 5) {
            return 9;
        }

    }

    //checks for of a kind
    for (int i = TWO; i <= ACE; i++) {
        if(rankCount[i] == 4) {
            return 8;
        }
    }

    //checks for full house
    bool threeKind = false;
    bool pair = false;
    for (int i = TWO; i <= ACE; i++) {
        if(rankCount[i] == 3) {
            threeKind = true;
        }
        if(rankCount[i] == 2) {
            pair = true;
        }
    }
    if(threeKind && pair) {
        return 7;
    }

    //checks flush
    if(flush) {
        return 6;
    }

    //checks straight
    if(straight) {
        return 5;
    }

    //checks three of a kind
    if (threeKind) {
        return 4;
    }

    //checks for two pair and pair.
    if(pair) {
        int pairs = 0;
        for (int i = TWO; i <= ACE; i++) {
            if(rankCount[i] == 2) {
                pairs++;
            }
        }
        if (pairs == 2) {
            return 3;
        }else {
            return 2;
        }
    }

    //if nothing else suffices high card is returned.
    return 1;
}

void Poker::play() {
    //variable used to check if player has folded
    bool folded = false;

    cout << "playing poker texas holdem now." << endl;
    cout<< "Dealing cards..." << endl;

    //displays users cards
    cout<< "your cards: " << endl;
    playerHand[0].displayCard();
    playerHand[1].displayCard();

    //fold stay is called, used for input validation
    folded = foldStay();

    //next turn starts if player hasn't folded
    if(!folded) {
        //displays first three cards on the table
        cout << "dealing flop: " << endl;
        cout << "cards on table: " << endl;
        table[0].displayCard();
        table[1].displayCard();
        table[2].displayCard();

        //displays your cards again
        cout<< "your cards: " << endl;
        playerHand[0].displayCard();
        playerHand[1].displayCard();


        //provides user action again
        folded = foldStay();
    }

    //checks again if folded
    if(!folded) {
        //next turn starts displays next card on table
        cout << "dealing turn: " << endl;
        cout << "cards on table: " << endl;
        table[0].displayCard();
        table[1].displayCard();
        table[2].displayCard();
        table[3].displayCard();

        //displays users cards
        cout<< "your cards: " << endl;
        playerHand[0].displayCard();
        playerHand[1].displayCard();

        folded = foldStay();
    }

    if(!folded) {
        //shows last card on table
        cout << "dealing river: " << endl;
        cout << "cards on table: " << endl;
        table[0].displayCard();
        table[1].displayCard();
        table[2].displayCard();
        table[3].displayCard();
        table[4].displayCard();

        //displays your cards once again
        cout<< "your cards: " << endl;
        playerHand[0].displayCard();
        playerHand[1].displayCard();

        //provides one more chance for the user to fold or stay
        folded = foldStay();
    }


    if(!folded) {
        //displays final results
        cout<< "final results: " << endl;
        int playerHandVal = calculateHand(playerHand); //calculates players hand
        cout<<"Your hand value is: " << hands[playerHandVal -1] <<endl; //outputs what your hand value is

        //checks dealers hand
        int dealerHandVal = calculateHand(dealerHand);
        //reveals dealers cards
        cout<<"Dealers hand:"<<endl;
        dealerHand[0].displayCard();
        dealerHand[1].displayCard();
        cout<<"Dealers hand value is: " << hands[dealerHandVal - 1] << endl; //outputs dealers hand value

        //sets conditions to check who won
        if(playerHandVal > dealerHandVal) {
            cout<<"Player wins!"<<endl;
            win = true;
        }else if(playerHandVal < dealerHandVal) {
            cout<<"Player loses"<<endl;
            win = false;
        } else { //tie sets win to false
            cout <<"tie: "<<endl;
            win = false;
        }
    }
}

