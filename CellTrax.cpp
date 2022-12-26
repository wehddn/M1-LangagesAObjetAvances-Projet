#include "Cell.hpp"

#include <iostream>

CellTrax::CellTrax(){}

void CellTrax::setTile(TileTrax* tile){
    t = tile;
}

TileTrax* CellTrax::getTile(){
    return t;
}

void CellTrax::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if(t!=nullptr){
        target.draw(*t);
    }
    else{
        target.draw(*rect);
    }
}