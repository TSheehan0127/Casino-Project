#include <iostream>
#include "Game.h"
#include "Poker.h"
#include "BlackJack.h"
using namespace std;


int main() {
    unique_ptr<Game> game;
    cout << "Welcome to the casino!" << endl;

    while (true) {
        string input;
        cout << "Would you like to play Blackjack (b) or Poker (p)? (n to exit)" << endl;
        getline(cin, input);

        if (input == "b") {
            game = make_unique<BlackJack>();
        } else if (input == "p") {
            game = make_unique<Poker>();
        } else if (input == "n") {
            cout << "Thanks for visiting the casino!" << endl;
            return 0;
        } else {
            cout << "Invalid input. Please enter 'b', 'p', or 'n'." << endl;
            continue;
        }

        game->play();

        while (true) {
            cout << "Would you like to play again (y/n)" <<endl;
            getline(cin, input);
            if (input == "y") {
                break;
            } else if (input == "n") {
                cout << "Thanks for visiting the casino!" << endl;
                return 0;
            } else {
                cout << "Invalid input enter (y) for yes, (n) for no" << endl;
            }
        }
    }
}
