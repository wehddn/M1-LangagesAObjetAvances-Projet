#include "Game.hpp"

#include <iostream>

Game::Game(){
    srand(time(0));
    for(int j=0; j<5; j++)
        {    
            deck.push_back(Tile());
        }
}

Tile Game::getTile(){
    Tile r = deck.back();
    deck.pop_back();
    return r;
}

void Game::putTile(int x, int y, Tile* t){
    if (board.size()==0){
        vector<Tile*> line(3, nullptr);
        board.push_back(line);
        board.push_back(line);
        board.push_back(line);
        board[1][1]=t;
        boardX = 3; boardY = 3;
        return;
    }
    else{
        board[x][y]=t;
        
        if (x==boardX-1){
            vector<Tile*> line(boardY, nullptr);
            board.push_back(line);
            boardX++;
        }

        if (x==0){
            vector<Tile*> line(boardY, nullptr);
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
    }
}

void Game::setTestBoard(Tile* t){
    testBoard.push_back(nullptr);
    testBoard.push_back(t);
    testBoard.push_back(nullptr);
}

vector<vector<Tile*>> Game::getBoard(){
    return board;
}

std::ostream& operator<< (std::ostream &out, Game &game)
{   string res = "";
    Tile t = game.getTile();
    for(auto& row:game.getBoard()){
        for(auto& col:row){
            if(col == nullptr)
                cout << "null\n";
            else
                cout << *col;
        }
    }
    out << "";
    return out;
}