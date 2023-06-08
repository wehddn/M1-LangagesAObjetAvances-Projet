#include "Game.hpp"

#include <iostream>

Game::Game(){};

void Game::nextPlayer(){
    if (current_player_number == playersNumber-1)
        current_player_number = 0;
    else 
        current_player_number += 1;
    setCurrentPlayer(current_player_number);
}

void Game::setCurrentPlayer(int current_player_number){
    current_player = players[current_player_number];
}

int Game::getPlayersNumber(){
    return playersNumber;
}

int Game::getDeckSize(){
    return deck.size();
}

void Game::gameLoop(){}