#ifndef PLAYER
#define PLAYER

#include "Tile.hpp"

class Player{
    public:
        Player();
        void addScore(int s);
        int getScore();
        void setTile(Tile* t);
        Tile* getTile();
        void setName(string n);
        string getName();
    private:
        int score = 0;
        Tile* currentTile;
        string name;
};

#endif