#include "Player.hpp"

PlayerDomino::PlayerDomino(){
    currentTile = nullptr;
}

void PlayerDomino::addScore(int s){
    score += s;
}

int PlayerDomino::getScore(){
    return score;
}

void PlayerDomino::setTile(TileDomino* t){
    currentTile = t;
}

TileDomino* PlayerDomino::getTile(){
    return currentTile;
}