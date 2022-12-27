#include "Board.hpp"

#include <iostream>

BoardTrax::BoardTrax(){
    CellTrax* c = new CellTrax();
    vector<CellTrax*> line(1, c);
    board.push_back(line);
    boardX = 1; boardY = 1;
}

bool BoardTrax::putTile(int x, int y, CellTrax* c, TileTrax* t){
    //on verifie les cotes des tuiles voisines
    //retourne false si on ne peut pas mettre une tuile

    if (!checkSize(x, y))
        return false;

    if(!checkSides(x, y, t))
        return false;

    if(forcedLock!=nullptr){
        if(x!=forcedLock->first || y!=forcedLock->second)
            return false;
        else
            forcedLock=nullptr;
    }

    t->setPosition(c->getRect()->getPosition());
    c->setTile(t);
    c->setRect(nullptr);
    
    if (x==boardX-1){
        vector<CellTrax*> line(boardY, nullptr);
        board.push_back(line);
        boardX++;
    }

    if (x==0){
        vector<CellTrax*> line(boardY, nullptr);
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

bool BoardTrax::checkSides(int x, int y, TileTrax* t){
    if(y>0){
        if(board[x][y-1]!=nullptr){
            if(board[x][y-1]->getTile()!=nullptr){
                if(t->getDirections().at(0)!=board[x][y-1]->getTile()->getDirections().at(2))
                    return false;
            }
        }
    }

    if(y<boardY-1){
        if(board[x][y+1]!=nullptr){
            if(board[x][y+1]->getTile()!=nullptr){
                if(t->getDirections().at(2)!=board[x][y+1]->getTile()->getDirections().at(0))
                    return false;
            }
        }
    }

    if(x>0){
        if(board[x-1][y]!=nullptr){
            if(board[x-1][y]->getTile()!=nullptr){
                if(t->getDirections().at(3)!=board[x-1][y]->getTile()->getDirections().at(1))
                    return false;
            }
        }
    }

    if(x<boardX-1){
        if(board[x+1][y]!=nullptr){
            if(board[x+1][y]->getTile()!=nullptr){
                if(t->getDirections().at(1)!=board[x+1][y]->getTile()->getDirections().at(3))
                    return false;
            }
        }
    }

    return true;
}

void BoardTrax::updateBoard(){
    if(board.size()==1){
        board.at(0).at(0)->newRect();
    }
    else{
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

vector<vector<CellTrax*>> BoardTrax::getTiles(){
    return board;
}

int BoardTrax::getTileSize(){
    return recth;
}

void BoardTrax::setRectAtPositions(int i, int j, int x, int y){
    if(board.at(i).at(j)==nullptr)
        board.at(i).at(j) = new CellTrax();
    if(board.at(i).at(j)->getTile()==nullptr){
        board.at(i).at(j)->newRect();
        board.at(i).at(j)->getRect()->setPosition(sf::Vector2f(x, y));
        board.at(i).at(j)->getRect()->setOrigin(sf::Vector2f(board.at(i).at(j)->getRect()->getLocalBounds().width, board.at(i).at(j)->getRect()->getLocalBounds().height)/2.f);
        board.at(i).at(j)->getRect()->setSize(sf::Vector2f(recth, recth));
    }
}

bool BoardTrax::checkPaths(int x, int y){
    if(x==0) x++;
    if(y==0) y++;
    visitedTiles.clear();
    if(checkNextTile(x+1, y)){
        if(cycle(x, y, x, y, 3)) return true;
    }
    if(checkNextTile(x-1, y)){
        if(cycle(x, y, x, y, 1)) return true;
    }
    if(checkNextTile(x, y+1)){
        if(cycle(x, y, x, y, 0)) return true;
    }
    if(checkNextTile(x, y-1)){
        if(cycle(x, y, x, y, 2)) return true;
    }

    vector<bool> directions = board.at(x).at(y)->getTile()->getDirections();
    vector<int> firstDir;
    vector<int> secondDir;
    for(int i=0; i<4; i++){
        if(directions.at(i))
            firstDir.push_back(i);
        else
            secondDir.push_back(i);
    }

    if(boardX>9 || boardY>9){
        if(boardsPath(x, y, firstDir.at(0)) && boardsPath(x, y, firstDir.at(1)))
            return true;
        if(boardsPath(x, y, secondDir.at(0)) && boardsPath(x, y, secondDir.at(1)))
            return true;
    }

    return false;
}

bool BoardTrax::boardsPath(int x, int y, int dir){

    int newDir = nextDirection(x, y, dir);

    pair<int, int> nextXY = nextCoords(x, y, newDir);
    int nextX = nextXY.first, nextY = nextXY.second;
    

    if(checkNextTile(nextX, nextY)){
        if(boardsPath(nextX, nextY, newDir)){
            return true;
        }
    }
    else {
        if(nextX==9 || nextX==0 || nextY == 9 || nextY==0)
            return true;
    }
    return false;
}

bool BoardTrax::cycle(int baseX, int baseY, int x, int y, int dir){

    int newDir = nextDirection(x, y, dir);

    pair<int, int> nextXY = nextCoords(x, y, newDir);
    int nextX = nextXY.first, nextY = nextXY.second;

    if(checkNextTile(nextX, nextY)){
        if(!visitedTilesContains(nextX, nextY)){
            pair<int, int> pair = make_pair(nextX, nextY);
            visitedTiles.push_back(pair);
            if(baseX==nextX && baseY==nextY)
                return true;
            if(cycle(baseX, baseY, nextX, nextY, newDir)){
                return true;
            }
        }
    }
    return false;
}

int BoardTrax::nextDirection(int x, int y, int dir){
    int newDir;
    int firstDir = (dir+2) % 4;
    vector<bool> directions = board.at(x).at(y)->getTile()->getDirections();
    for(int i=0; i<4; i++){
        if(directions.at(i)==directions.at(firstDir) && i!=firstDir){
            newDir=i;
            break;
        }
    }
    return newDir;
}

pair<int, int> BoardTrax::nextCoords(int x, int y, int newDir){
    int nextX, nextY;

    switch (newDir)
    {
    case 1:
        nextX=x+1; nextY=y;
        break;
    case 3:
        nextX=x-1; nextY=y;
        break;
    case 2:
        nextX=x; nextY=y+1;
        break;
    case 0:
        nextX=x; nextY=y-1;
        break;
    default:
        break;
    }
    return make_pair(nextX, nextY);
}

bool BoardTrax::checkNextTile(int x, int y){
    if(board.at(x).at(y)!=nullptr){
        if (board.at(x).at(y)->getTile()!=nullptr)
            return true;
    }
    return false;
}

bool BoardTrax::visitedTilesContains(int x, int y){
    for(auto& pair:visitedTiles){
        if(x==pair.first && y==pair.second)
            return true;
    }
    return false;
}

bool BoardTrax::checkForced(int x, int y){
    if(x==0) x++;
    if(y==0) y++;

    if(board.at(x+1).at(y)!=nullptr){
        if(board.at(x+1).at(y)->getTile()==nullptr && checkForcedTile(x+1, y)){
            forcedLock = new pair<int, int>(x+1, y);
            return true;
        }
    }

    if(board.at(x-1).at(y)!=nullptr){
        if(board.at(x-1).at(y)->getTile()==nullptr && checkForcedTile(x-1, y)){
            forcedLock = new pair<int, int>(x-1, y);
            return true;
        }
    }

    if(board.at(x).at(y+1)!=nullptr){
        if(board.at(x).at(y+1)->getTile()==nullptr && checkForcedTile(x, y+1)){
            forcedLock = new pair<int, int>(x, y+1);
            return true;
        }
    }

    if(board.at(x).at(y-1)!=nullptr){
        if(board.at(x).at(y-1)->getTile()==nullptr && checkForcedTile(x, y-1)){
            forcedLock = new pair<int, int>(x, y-1);
            return true;
        }
    }

    return false;
}

bool BoardTrax::checkForcedTile(int newX, int newY){
    int forceCountBlack = 0;
    int forceCountWhite = 0;
    if(checkNextTile(newX+1, newY)){
        if(board.at(newX+1).at(newY)->getTile()->getDirections().at(3))
            forceCountBlack++;
        else forceCountWhite++;
    }
    if(checkNextTile(newX-1, newY)){
        if(board.at(newX-1).at(newY)->getTile()->getDirections().at(1))
            forceCountBlack++;
        else forceCountWhite++;
    }
    if(checkNextTile(newX, newY+1)){
        if(board.at(newX).at(newY+1)->getTile()->getDirections().at(0))
            forceCountBlack++;
        else forceCountWhite++;
    }
    if(checkNextTile(newX, newY-1)){
        if(board.at(newX).at(newY-1)->getTile()->getDirections().at(2))
            forceCountBlack++;
        else forceCountWhite++;
    }
    if (forceCountBlack > 1 || forceCountWhite > 1)
        return true;
    return false;
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