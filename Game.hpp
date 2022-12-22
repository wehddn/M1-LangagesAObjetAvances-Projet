#ifndef GAME
#define GAME

#include "Tile.hpp"
#include "Board.hpp"
#include "Bar.hpp"

#include<vector>

using namespace std;

class Game{
    public:
        Game();
        Tile* getTile();
        Board* getBoard();
        void setDeck();
        void gameLoop();
    private:
        vector<Tile*> deck;
        Board* board;
        int boardX; int boardY;
        int deck_size = 100;
};

std::ostream& operator<< (std::ostream &out, Game &game);

#endif