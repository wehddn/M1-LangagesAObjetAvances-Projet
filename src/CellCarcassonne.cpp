#include "Cell.hpp"

#include <iostream>

CellCarcassonne::CellCarcassonne(){}

void CellCarcassonne::setTile(TileCarcassonne* tile){
    t = tile;
}

TileCarcassonne* CellCarcassonne::getTile(){
    return t;
}

void CellCarcassonne::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if(t!=nullptr){
        target.draw(*t);
    }
    else{
        target.draw(*rect);
    }
}