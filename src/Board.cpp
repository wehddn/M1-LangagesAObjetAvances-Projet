#include "Board.hpp"

#include <iostream>

Board::Board(){}

bool Board::checkSides(int x, int y, Tile* t){
    return true;
}

int Board::sideScore(vector<int> side){
    return side.at(0) + side.at(1) + side.at(2);
}

int Board::getStepScore(){
    return stepScore;
}

vector<vector<Cell*>> Board::getTiles(){
    return board;
}

int Board::getTileSize(){
    return recth;
}

void Board::setRectAtPositions(int i, int j, int x, int y){
    
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(auto& row:board){
        for(auto& col:row){
            if(col != nullptr){
                target.draw(*col);
            }
        }
    }
}