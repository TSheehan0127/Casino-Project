# Casino-Project
this project was used to learn more about inheritance and polymorphism with C++ and how far I could go with it.

The application consists of two games a player can use: Black Jack and Poker.
As the program runs, a player is given options through the terminal for what they can do in each game. For the case of blackJack it's either hit or stay, and for Poker it's to fold.

For poker I only gave the player to fold for each turn as there are no chips implemented to the program.
There are also a few directions I would like to go with this project such as some decision making on the computer side as well as added chips to bet in the program.
Finally I would love to add visuals to the program to make it more user friendly.

The main purpose of this project was to enhance my knowledge with polymorphism and inheritance through C++. Inheritance is the process of obtaining properties from an already used class and to expand on those properties in another class. Some examples of this include using classes such as Black Jack and Poker, where both inherit from the Games class as well as the Deck class using a "has a " inherited relationship with the cards class. Polymorphism is the process of multiple classes responding to a function that are the same type. In other words they allow different inherited classes respond to a specific function performing the same behavior. The example of polymorphism is in the main class where either black jack or poker is set to be the current game. Whichever one is chosen, both have a play method that is called through polymorphism to start the specific game.
