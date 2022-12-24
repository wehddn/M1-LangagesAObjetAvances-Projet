#include "BoardTrax.hpp"

#include <iostream>

BoardTrax::BoardTrax(){
    Cell* c = new Cell();
    vector<Cell*> line(1, c);
    board.push_back(line);
    boardX = 1; boardY = 1;
}

bool BoardTrax::putTile(int x, int y, Cell* c, Tile* t){
    //on verifie les cotes des tuiles voisines
    //retourne false si on ne peut pas mettre une tuile

    if (!checkSize(x, y))
        return false;

    //if(!checkSides(x, y, t))
    //    return false;

    t->setPosition(c->getRect()->getPosition());
    c->setTile(t);
    c->setRect(nullptr);
    
    if (x==boardX-1){
        vector<Cell*> line(boardY, nullptr);
        board.push_back(line);
        boardX++;
    }

    if (x==0){
        vector<Cell*> line(boardY, nullptr);
        board.insert(board.begin(), line);
        boardX++;
    }

    if (y==boardY-1){
        for(auto& row:board){
            row.push_back(nullptr);
        }
        boardY++;
    }

    if (y==0){
        for(auto& row:board){
            row.insert(row.begin(), nullptr);
        }
        boardY++;
    }

    return true;
}

bool BoardTrax::checkSize(int x, int y){
    if (x>8 || y>8 || (x==0 && boardX>9) || (y==0 && boardY>9))
        return false;
    else
        return true;
}

bool BoardTrax::checkSides(int x, int y, Tile* t){
    int result = 0;

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

    stepScore = result;
    return true;
}

int BoardTrax::sideScore(vector<int> side){
    return side.at(0) + side.at(1) + side.at(2);
}

int BoardTrax::getStepScore(){
    return stepScore;
}

void BoardTrax::updateBoard(){
    if(board.size()==1){
        cout << "updateBoard 1" << endl;
        board.at(0).at(0)->newRect();
    }
    else{
        cout << "updateBoard n" << endl;
        for(int i=0; i<boardX; i++){
            for(int j=0; j<boardY; j++){
                if(board.at(i).at(j)!=nullptr){
                    if(board.at(i).at(j)->getTile()!=nullptr){
                        sf::Vector2f position = board.at(i).at(j)->getTile()->getRect()->getPosition();
                        setRectAtPositions(i-1, j, position.x-recth, position.y);
                        setRectAtPositions(i, j-1, position.x, position.y-recth);
                        setRectAtPositions(i, j+1, position.x, position.y+recth);
                        setRectAtPositions(i+1, j, position.x+recth, position.y);
                    }
                }
            }
        }
    }
}

vector<vector<Cell*>> BoardTrax::getTiles(){
    return board;
}

int BoardTrax::getTileSize(){
    return recth;
}

void BoardTrax::setRectAtPositions(int i, int j, int x, int y){
    if(board.at(i).at(j)==nullptr)
        board.at(i).at(j) = new Cell();
    if(board.at(i).at(j)->getTile()==nullptr){
        board.at(i).at(j)->newRect();
        board.at(i).at(j)->getRect()->setPosition(sf::Vector2f(x, y));
        board.at(i).at(j)->getRect()->setOrigin(sf::Vector2f(board.at(i).at(j)->getRect()->getLocalBounds().width, board.at(i).at(j)->getRect()->getLocalBounds().height)/2.f);
        board.at(i).at(j)->getRect()->setSize(sf::Vector2f(recth, recth));
    }
}

void BoardTrax::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(auto& row:board){
        for(auto& col:row){
            if(col != nullptr){
                target.draw(*col);
            }
        }
    }
}