#include "Player.hpp"

PlayerTrax::PlayerTrax(){
    currentTile = nullptr;
}

void PlayerTrax::setTile(TileTrax* t){
    currentTile = t;
}

TileTrax* PlayerTrax::getTile(){
    return currentTile;
}