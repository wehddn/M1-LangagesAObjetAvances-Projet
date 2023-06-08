#include "Cell.hpp"

#include <iostream>

CellDomino::CellDomino(){}

void CellDomino::setTile(TileDomino* tile){
    t = tile;
}

TileDomino* CellDomino::getTile(){
    return t;
}

void CellDomino::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if(t!=nullptr){
        target.draw(*t);
    }
    else{
        target.draw(*rect);
    }
}