#include "Player.hpp"

PlayerCarcassonne::PlayerCarcassonne(){
    currentTile = nullptr;
}

void PlayerCarcassonne::setTile(TileCarcassonne* t){
    currentTile = t;
}

TileCarcassonne* PlayerCarcassonne::getTile(){
    return currentTile;
}