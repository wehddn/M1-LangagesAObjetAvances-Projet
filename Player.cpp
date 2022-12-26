#include "Player.hpp"

Player::Player(){}

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