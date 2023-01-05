#include "Board.hpp"
#include "GarbageCollector.hpp"

#include <iostream>

BoardCarcassonne::BoardCarcassonne(){
    CellCarcassonne* c = new CellCarcassonne();
    GarbageCollector::create(c);
    vector<CellCarcassonne*> line(1, c);
    board.push_back(line);
    boardX = 1; boardY = 1;
}

bool BoardCarcassonne::putTile(int x, int y, CellCarcassonne* c, TileCarcassonne* t){
    //on verifie les cotes des tuiles voisines
    //retourne false si on ne peut pas mettre une tuile

    if(!checkSides(x, y, t))
        return false;

    t->setPosition(c->getRect()->getPosition());
    c->setTile(t);
    c->setRect(nullptr);
    
    if (x==boardX-1){
        vector<CellCarcassonne*> line(boardY, nullptr);
        board.push_back(line);
        boardX++;
    }

    if (x==0){
        vector<CellCarcassonne*> line(boardY, nullptr);
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

bool BoardCarcassonne::checkSides(int x, int y, TileCarcassonne* t){
    if(y>0){
        if(board[x][y-1]!=nullptr){
            if(board[x][y-1]->getTile()!=nullptr){
                if(t->getSides().at(0)!=board[x][y-1]->getTile()->getSides().at(2))
                    return false;
            }
        }
    }

    if(y<boardY-1){
        if(board[x][y+1]!=nullptr){
            if(board[x][y+1]->getTile()!=nullptr){
                if(t->getSides().at(2)!=board[x][y+1]->getTile()->getSides().at(0))
                    return false;
            }
        }
    }

    if(x>0){
        if(board[x-1][y]!=nullptr){
            if(board[x-1][y]->getTile()!=nullptr){
                if(t->getSides().at(3)!=board[x-1][y]->getTile()->getSides().at(1))
                    return false;
            }
        }
    }

    if(x<boardX-1){
        if(board[x+1][y]!=nullptr){
            if(board[x+1][y]->getTile()!=nullptr){
                if(t->getSides().at(1)!=board[x+1][y]->getTile()->getSides().at(3))
                    return false;
            }
        }
    }

    return true;
}

void BoardCarcassonne::updateBoard(){
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

vector<vector<CellCarcassonne*>> BoardCarcassonne::getTiles(){
    return board;
}

int BoardCarcassonne::getTileSize(){
    return recth;
}

void BoardCarcassonne::setRectAtPositions(int i, int j, int x, int y){
    if(board.at(i).at(j)==nullptr){
        board.at(i).at(j) = new CellCarcassonne();
        GarbageCollector::create(board.at(i).at(j));
    }
    if(board.at(i).at(j)->getTile()==nullptr){
        board.at(i).at(j)->newRect();
        board.at(i).at(j)->getRect()->setPosition(sf::Vector2f(x, y));
        board.at(i).at(j)->getRect()->setOrigin(sf::Vector2f(board.at(i).at(j)->getRect()->getLocalBounds().width, board.at(i).at(j)->getRect()->getLocalBounds().height)/2.f);
        board.at(i).at(j)->getRect()->setSize(sf::Vector2f(recth, recth));
    }
}

bool BoardCarcassonne::checkPaths(int x, int y){
    //Vérification des conditions de fin de partie

    //Pour chaque tuile posée, on vérifie récursivement les 4 tuiles adjacentes jusqu'à ce qu'une boucle soit détectée
    if(x==0) x++;
    if(y==0) y++;
    visitedTiles.clear();
    if(nextTileExists(x+1, y)){
        if(cycle(x, y, x, y, 3)) return true;
    }
    if(nextTileExists(x-1, y)){
        if(cycle(x, y, x, y, 1)) return true;
    }
    if(nextTileExists(x, y+1)){
        if(cycle(x, y, x, y, 0)) return true;
    }
    if(nextTileExists(x, y-1)){
        if(cycle(x, y, x, y, 2)) return true;
    }

    //Pour chaque tuile posée, on vérifie récursivement des paires de tuiles adjacentes de même couleur
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

bool BoardCarcassonne::boardsPath(int x, int y, int dir){
    //Pour une direction donné, on trouve la nouvelle direction de la couleur correspondante
    int newDir = nextDirection(x, y, dir);

    //On calcule les coordonnées de la tuile suivante
    pair<int, int> nextXY = nextCoords(x, y, newDir);
    int nextX = nextXY.first, nextY = nextXY.second;
    
    //Si la tuile suivante existe on la vérifie récursivement
    //Si non, on vérifie si la tuile actuelle se trouve sur le bord
    if(nextTileExists(nextX, nextY)){
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

bool BoardCarcassonne::cycle(int baseX, int baseY, int x, int y, int dir){
    //Pour une direction donné, on trouve la nouvelle direction de la couleur correspondante
    int newDir = nextDirection(x, y, dir);

    //On calcule les coordonnées de la tuile suivante
    pair<int, int> nextXY = nextCoords(x, y, newDir);
    int nextX = nextXY.first, nextY = nextXY.second;

    //Si la tuile suivante existe et n'a pas été visitée, on vérifie si elle est le début de la boucle
    //Si oui, la boucle est détectée, sinon, on vérifie récursivement la tuile suivante
    if(nextTileExists(nextX, nextY)){
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

int BoardCarcassonne::nextDirection(int x, int y, int dir){
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

pair<int, int> BoardCarcassonne::nextCoords(int x, int y, int newDir){
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

bool BoardCarcassonne::nextTileExists(int x, int y){
    if(board.at(x).at(y)!=nullptr){
        if (board.at(x).at(y)->getTile()!=nullptr)
            return true;
    }
    return false;
}

bool BoardCarcassonne::visitedTilesContains(int x, int y){
    for(auto& pair:visitedTiles){
        if(x==pair.first && y==pair.second)
            return true;
    }
    return false;
}

void BoardCarcassonne::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(auto& row:board){
        for(auto& col:row){
            if(col != nullptr){
                target.draw(*col);
            }
        }
    }
}