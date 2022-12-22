#include "Player.hpp"

Player::Player(){
    currentTile = nullptr;
}

void Player::addScore(int s){
    score += s;
}

int Player::getScore(){
    return score;
}

void Player::setTile(Tile* t){
    currentTile = t;
}

Tile* Player::getTile(){
    return currentTile;
}

void Player::setName(string n){
    name = n;
}

string Player::getName(){
    return name;
}