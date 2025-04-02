# M2OEP-tjsheeha

- Your name 
  - Tyler Sheehan
  

- A summary of your program, including a list of Module 2 concepts used.
  - The program presented is a casino application that provides a user to play one of two games: Black Jack or Poker.
  - Black Jack, created in my previous open-ended project while may look similar to the user, was modified to make it easier to establish other games in the program. Creating a super class called Game, I made it so black jack was its own class allowing for easily readable code.
  - The biggest extension to this program would be Poker. Using the game super class, the Poker class which inherits from Game, allows a user to play a very simplified version of Texas Holdem. When I say simplified, a user is only given two options at each turn of the game: to fold or stay.
  - Along with applying these two games the main method provided user input to play again, and to quit the program. And finally the last thing added was a testing program, which ensured that everything worked in the casino application.

  - A list of Module 2 concepts used:
    - 1.) Has-a relationship: A deck class has cards, a game class has a deck
    - 2.) is-a relationship: Poker is a game, Black Jack is a game
    - 3.) Testing: there is a separate testing program that validates all classes and methods
    - 4.) main program complexity: main program allows for user input, utilizes polymorphism, and addresses all classes created in the program.

- Any known bugs at time of submission
  - there are no known bugs at the time of submitting the project.
  

- Future work (how you could expand the program with more time)
  - With more time, the Casino application can work on a few things:
    - A: adding visuals. Making it so there are actual cards will make it more fun for a player as they can see what is going on.
    - B: adding a chip class. Since Poker doesn't have much functionality without betting it may be fun to add betting and chips.
    - C: Computer decision-making. In poker and blackJack a computer is set by default to do certain actions but, it would be nice to have maybe a difficulty setting that predicted certain actions based on their setting.

- Citations for any code not written by you or the instructor
    - One citation is learning static cast.
    Static cast allows for datatypes to safely be converted to other types during compile time. It is necessary for my project to convert integer types to my enumerated types for declaring all cards in a deck.
    link: https://www.geeksforgeeks.org/static_cast-in-cpp/

- The grade you think you have earned, based on the grading rubric below, with justification
  - The points I belive I should earn for this project are based on the following:
  - +40 points for main program complexity and usability
  - +20 points for testing the program
  - +20 points for has-a relationship: A Deck has Cards
  - +20 points for has-a relationship: A Game has a Deck
  - +20 points for is-a relationship: BlackJack is a Game
  - +20 points for is-a relationship: Poker is a Game
  - -5 points for lifespan of this project
  
In total for this open-ended project I should earn 135 points.

