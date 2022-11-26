#ifndef GAME
#define GAME

#include "Tile.hpp"

#include<vector>

using namespace std;

class Game{
    private:
        vector<Tile> deck;
        vector<vector<Tile*>> board;
        vector<Tile*> testBoard;
        int boardX; int boardY;
        vector<vector<int>> test;
    public:
        Game();
        Tile getTile();
        void putTile(int x, int y, Tile* t);
        void setTestBoard(Tile*);
        vector<vector<Tile*>> getBoard();
};

std::ostream& operator<< (std::ostream &out, Game &game);

#endif