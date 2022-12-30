#include "Board.hpp"

#include <iostream>

Board::Board(){}

bool Board::checkSides(int x, int y, Tile* t){
    /*int result = 0;

    if(y>0){
        if(board[x][y-1]!=nullptr){
            if(board[x][y-1]->getTile()!=nullptr){
                if(t->getSides().at(0)!=board[x][y-1]->getTile()->getSides().at(2))
                    return false;
                else
                    result += sideScore(t->getSides().at(0));
            }
        }
    }

    if(y<boardY-1){
        if(board[x][y+1]!=nullptr){
            if(board[x][y+1]->getTile()!=nullptr){
                if(t->getSides().at(2)!=board[x][y+1]->getTile()->getSides().at(0))
                    return false;
                else
                    result += sideScore(t->getSides().at(2));
            }
        }
    }

    if(x>0){
        if(board[x-1][y]!=nullptr){
            if(board[x-1][y]->getTile()!=nullptr){
                if(t->getSides().at(3)!=board[x-1][y]->getTile()->getSides().at(1))
                    return false;
                else
                    result += sideScore(t->getSides().at(3));
            }
        }
    }

    if(x<boardX-1){
        if(board[x+1][y]!=nullptr){
            if(board[x+1][y]->getTile()!=nullptr){
                if(t->getSides().at(1)!=board[x+1][y]->getTile()->getSides().at(3))
                    return false;
                else
                    result += sideScore(t->getSides().at(1));
            }
        }
    }

    stepScore = result;*/
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
    /*if(board.at(i).at(j)==nullptr)
        board.at(i).at(j) = new Cell();
    if(board.at(i).at(j)->getTile()==nullptr){
        board.at(i).at(j)->newRect();
        board.at(i).at(j)->getRect()->setPosition(sf::Vector2f(x, y));
        board.at(i).at(j)->getRect()->setSize(sf::Vector2f(recth, recth));
    }*/
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