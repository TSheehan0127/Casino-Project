cmake_minimum_required(VERSION 3.29)
project(open_ended)

set(CMAKE_CXX_STANDARD 14)

add_executable(open_ended main.cpp Card.cpp Deck.cpp
        Deck.cpp
        Game.h
        Game.cpp
        BlackJack.h
        BlackJack.cpp
        Poker.h
        Poker.cpp)

add_executable(casino_testing testing.cpp Card.cpp Deck.cpp
        Deck.cpp
        Game.h
        Game.cpp
        BlackJack.h
        BlackJack.cpp
        Poker.h
        Poker.cpp
        testing.cpp)