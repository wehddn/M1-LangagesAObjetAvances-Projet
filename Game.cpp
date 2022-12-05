#include "Game.hpp"

#include <iostream>

Game::Game(){
    board = new Board();
    setDeck();
}

Tile* Game::getTile(){
    Tile* r = deck.back();
    deck.pop_back();
    return r;
}

Board* Game::getBoard(){
    return board;
}

void Game::setDeck(){
    int size = board->getTileSize();
    for(int i=0; i<deck_size; i++){
        Tile* t = new Tile();
        t->setPosition(sf::Vector2f(size, size));
        deck.push_back(t);
    }
}

std::ostream& operator<< (std::ostream &out, Game &game)
{   string res = "";
    /*for(auto& row:game.getBoard()){
        for(auto& col:row){
            if(col == nullptr)
                cout << "null\n";
            else
                cout << *col;
        }
    }*/
    out << "";
    return out;
}