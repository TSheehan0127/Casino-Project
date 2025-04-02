//
// Created by Tyler Sheehan on 2/21/25.
//
#include "BlackJack.h"
#include "Poker.h"
using namespace std;

bool testCardClass();
bool testDeckClass();
bool testGameClass();
bool testBlackJack();
bool testPoker();

int main(){
  if(testCardClass()) {
    cout<<"Card class works properly!"<<endl;
  }
  if(testDeckClass()) {
    cout<<"Deck class works properly!"<<endl;
  }
  if (testGameClass()) {
    cout<<"Game class works properly!"<<endl;
  }
  if(testBlackJack()) {
    cout <<"Black Jack works properly!"<<endl;
  }
  if(testPoker()) {
    cout << "Poker works properly!" << endl;
  }

  return 0;
  }

bool testGameClass() {
  bool passed = true;

  //since Game is abstract we have to access it through a child class
  BlackJack gameTester;

  //checks if a deck of cards is 52 cards.
  //+4 because 4 cards are dealt to the player and dealer
  const int deckSize = gameTester.getDeck().getCards().size() + 4;
  if (deckSize != 52) {
    cout <<"Deck size is invalid"<<endl;
    passed = false;
  }

  //checks if win is set by default to false.
  if (gameTester.getWin()) {
    cout <<"win is set equal to true by default." <<endl;
    passed = false;
  }

  //testing if reset deck works.
  gameTester.getDeck().drawCard();
  gameTester.getDeck().drawCard();

  //has to alter the deck first before resetting it.
  //46 should be deck size since there are 48 cards when blackJack is initialized, - 2 from drawing 2 cards.
  if (gameTester.getDeck().getCards().size() != 46) { //checks if two cards were drawn out properly.
    cout <<"Deck is not drawing cards properly" <<endl;
    passed = false;
  }

  //resets the deck and makes sure the deck is back to 52 cards.
  gameTester.resetDeck();
  if (gameTester.getDeck().getCards().size() != 52) {
    cout <<"Reset deck does not work properly"<<endl;
    passed = false;
  }

  //other methods don't need to be tested as by default they are set to 0 (abstract class)
  return passed;
}

//tests the BlackJack class.
bool testBlackJack() {
  bool passed = true;

  //initializes black_jack game
  BlackJack black_jack;

  //initializes a deck of cards
  Deck deck;

  //checks if player and dealers hand are valid cards in the deck.
  vector<Card> playersHand = black_jack.getPlayerHand();
  vector<Card> dealersHand = black_jack.getDealerHand();
  int checker = 0;
  for (int i = 0; i < deck.getCards().size(); i++) {
    if(playersHand[0] == deck.getCards()[i]) {
      checker++;
    }
    if(playersHand[1] == deck.getCards()[i]) {
      checker++;
    }
    if(dealersHand[0] == deck.getCards()[i]) {
      checker++;
    }
    if(dealersHand[1] == deck.getCards()[i]) {
      checker++;
    }
  }

  if (checker != 4) {
    cout<< "Cards in dealer and players hand are not in the deck."<<endl;
    passed = false;
  }

  //testing calculate hand function now:
  //case 1: hand is black Jack:
  vector<Card> blackJackHand = {Card(SPADES, ACE), Card(DIAMONDS,JACK)};

  black_jack.setPlayerHand(blackJackHand);
  if(black_jack.calculateHand(black_jack.getPlayerHand()) != 21) {
    cout<<"Calculate hand couldn't calculate ace and jack combination."<<endl;
    passed = false;
  }

  //case 2: Ace is set to 1
  blackJackHand = {Card(SPADES, ACE), Card(DIAMONDS,JACK), Card(CLUBS, FIVE)};
  black_jack.setPlayerHand(blackJackHand);
  if(black_jack.calculateHand(black_jack.getPlayerHand()) != 16) {
    cout<<"Calculate hand couldn't calculate ace, jack and 5 combination."<<endl;
    passed = false;
  }

  //testing setter for dealer since player already is tested in last cases.
  blackJackHand = {Card(DIAMONDS, TWO), Card(SPADES, THREE)};
  black_jack.setDealerHand((blackJackHand));
  if(black_jack.getDealerHand() != blackJackHand) {
    cout<<"Setter for dealers hand did not work."<<endl;
    passed = false;
  }

  return passed;
}

bool testPoker() {
  bool passed = true;

  //initializes poker
  Poker pokerGame;

  //checks if table size is accurate
  if(pokerGame.getTable().size() != 5) {
    cout<<"table size is not 5"<<endl;
    passed = false;
  }

  //checks if player hand, table, and dealer hand are accurate cards

  //initializes a deck of cards
  Deck deck;

  //checks if player and dealers hand are valid cards in the deck.
  vector<Card> playersHand = pokerGame.getPlayerHand();
  vector<Card> dealersHand = pokerGame.getDealerHand();
  vector<Card> tableHand = pokerGame.getTable();

  int checker = 0;
  for (int i = 0; i < deck.getCards().size(); i++) {
    if(playersHand[0] == deck.getCards()[i]) {
      checker++;
    }
    if(playersHand[1] == deck.getCards()[i]) {
      checker++;
    }
    if(dealersHand[0] == deck.getCards()[i]) {
      checker++;
    }
    if(dealersHand[1] == deck.getCards()[i]) {
      checker++;
    }

    if(tableHand[0] == deck.getCards()[i]) {
      checker++;
    }
    if(tableHand[1] == deck.getCards()[i]) {
      checker++;
    }
    if(tableHand[2] == deck.getCards()[i]) {
      checker++;
    }
    if(tableHand[3] == deck.getCards()[i]) {
      checker++;
    }
    if(tableHand[4] == deck.getCards()[i]) {
      checker++;
    }
  }

  if(checker != 9) {
    cout<<"Cards in players hand, dealers hand, and tables hand are not in the deck"<<endl;
    passed = false;
  }

  //testing conditions for calculate hand.

  //setting vectors for each condition
  vector<Card> royalFlush = {Card(SPADES,ACE),Card(SPADES,KING),Card(SPADES,QUEEN),Card(SPADES,JACK),Card(SPADES,TEN)};
  vector<Card> straightFlush = {Card(SPADES, TWO),Card(SPADES,THREE),Card(SPADES,FOUR),Card(SPADES,FIVE),Card(SPADES,SIX)};
  vector<Card> fourOfAkind = {Card(HEARTS,TWO),Card(SPADES,TWO),Card(DIAMONDS,TWO),Card(CLUBS,TWO)};
  vector<Card> fullHouse = {Card(DIAMONDS,TWO),Card(SPADES,TWO),Card(HEARTS,TWO),Card(DIAMONDS,THREE),Card(CLUBS,THREE)};
  vector<Card> flush = {Card(SPADES, TWO),Card(SPADES,TEN),Card(SPADES,FOUR),Card(SPADES,SEVEN),Card(SPADES,SIX)};
  vector<Card> straight = {Card(SPADES, TWO),Card(DIAMONDS,THREE),Card(SPADES,FOUR),Card(CLUBS,FIVE),Card(SPADES,SIX)};
  vector<Card> threeOfAkind = {Card(SPADES,THREE),Card(HEARTS,THREE),Card(CLUBS,THREE)};
  vector<Card> twoPair = {Card(DIAMONDS,TWO),Card(SPADES,TWO),Card(DIAMONDS,THREE),Card(CLUBS,THREE)};
  vector<Card> pair = {Card(DIAMONDS,TWO),Card(SPADES,TWO)};
  vector<Card> highCard = {Card(DIAMONDS,ACE)};

  //testVal will be used to check for all cases
  int testVal = 0;

  //test case 1: royal flush
  pokerGame.setPlayerHand({royalFlush[0],royalFlush[1]});
  pokerGame.setTable({royalFlush[2],royalFlush[3],royalFlush[4]});

  testVal= pokerGame.calculateHand(pokerGame.getPlayerHand());
  if(testVal != 10) {
    cout<<"Royal flush was not obtained"<<endl;
    passed = false;
  }

  //test case 2: straight flush
  pokerGame.setPlayerHand({straightFlush[0],straightFlush[1]});
  pokerGame.setTable({straightFlush[2],straightFlush[3],straightFlush[4]});

  testVal= pokerGame.calculateHand(pokerGame.getPlayerHand());
  if(testVal != 9) {
    cout<<"Straight flush was not obtained"<<endl;
    passed = false;
  }

  //test case 3: four of a kind
  pokerGame.setPlayerHand({fourOfAkind[0],fourOfAkind[1]});
  pokerGame.setTable({fourOfAkind[2],fourOfAkind[3]});

  testVal= pokerGame.calculateHand(pokerGame.getPlayerHand());
  if(testVal != 8) {
    cout<<"four of a kind was not obtained"<<endl;
    passed = false;
  }
  //test case 4: full house
  pokerGame.setPlayerHand({fullHouse[0],fullHouse[1]});
  pokerGame.setTable({fullHouse[2],fullHouse[3],fullHouse[4]});

  testVal= pokerGame.calculateHand(pokerGame.getPlayerHand());
  if(testVal != 7) {
    cout<<"full house was not obtained"<<endl;
    passed = false;
  }

  //test case 5: flush
  pokerGame.setPlayerHand({flush[0],flush[1]});
  pokerGame.setTable({flush[2],flush[3],flush[4]});

  testVal= pokerGame.calculateHand(pokerGame.getPlayerHand());
  if(testVal != 6) {
    cout<<"Flush was not obtained"<<endl;
    passed = false;
  }

  //test case 6: straight
  pokerGame.setPlayerHand({straight[0],straight[1]});
  pokerGame.setTable({straight[2],straight[3],straight[4]});

  testVal= pokerGame.calculateHand(pokerGame.getPlayerHand());
  if(testVal != 5) {
    cout<<"Straight was not obtained"<<endl;
    passed = false;
  }

  //test case 7: three of a kind
  pokerGame.setPlayerHand({threeOfAkind[0],threeOfAkind[1]});
  pokerGame.setTable({threeOfAkind[2]});

  testVal= pokerGame.calculateHand(pokerGame.getPlayerHand());
  if(testVal != 4) {
    cout<<"Three of a kind was not obtained"<<endl;
    passed = false;
  }

  //test case 8: two pair
  pokerGame.setPlayerHand({twoPair[0],twoPair[1]});
  pokerGame.setTable({twoPair[2],twoPair[3]});

  testVal= pokerGame.calculateHand(pokerGame.getPlayerHand());
  if(testVal != 3) {
    cout<<"Two pair was not obtained"<<endl;
    passed = false;
  }

  //test case 9: pair
  pokerGame.setPlayerHand({pair[0],pair[1]});
  pokerGame.setTable({});

  testVal= pokerGame.calculateHand(pokerGame.getPlayerHand());
  if(testVal != 2) {
    cout<<"Pair was not obtained"<<endl;
    passed = false;
  }

  //test case 10: high card
  pokerGame.setPlayerHand({highCard[0]});
  pokerGame.setTable({});

  testVal= pokerGame.calculateHand(pokerGame.getPlayerHand());
  if(testVal != 1) {
    cout<<"High card was not obtained"<<endl;
    passed = false;
  }

  return passed;
}

bool testCardClass() {
  bool passed = true;

  Card card1 = Card(DIAMONDS,KING);
  Card card2 = Card(SPADES, KING);

  //checks == operator
  if(card1 == card2) {
    cout<<"equals operator does not work."<<endl;
    passed = false;
  }

  //checks > and < operator
  card2 = Card(SPADES,SIX);

  if(card1<card2 || card2>card1) {
    cout<<"Greater than and less than operator don't work"<<endl;
    passed = false;
  }

  //checks if get value works.
  //case 1:
  if(card1.getValue() != 10) {
    cout<<"Face card has wrong value"<<endl;
    passed = false;
  }

  //case2:
  if(card2.getValue() != 6) {
    cout<<"number card has wrong value" <<endl;
    passed = false;
  }

  return passed;
}

bool testDeckClass() {
  bool passed = true;

  //initiates Deck object.
  Deck deck;

  //tests if constructor works, checks if all 52 cards are added into a deck
  if(deck.getCards().size() != 52) {
    cout <<"52 cards are not in the deck"<<endl;
    passed = false;
  }

  //tests if drawCard() works
  deck.drawCard();

  if(deck.getCards().size() != 51) {
    cout<<"Draw card does not work properly."<<endl;
    passed = false;
  }

  //test if shuffle works.
  vector<Card> notShuffled = deck.getCards();
  deck.shuffleDeck();

  vector<Card> shuffled = deck.getCards();

  int count = 0;
  for(int i = 0; i < 52; i++) {
    if(notShuffled[i] == shuffled[i]) {
      count ++;
    }
  }

  if (count == 52) {
    cout<<"Deck was not shuffled."<<endl;
    passed = false;
  }

  return passed;
}

