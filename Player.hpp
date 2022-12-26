#ifndef PLAYER
#define PLAYER

#include "Tile.hpp"

class Player{
    public:
        Player();
        void setTile(Tile* t);
        Tile* getTile();
        void setName(string n);
        string getName();
    protected:
        string name;
    private:
        Tile* currentTile;
};

class PlayerDomino : public Player{
    public:
        PlayerDomino();
        void addScore(int s);
        int getScore();
        void setTile(TileDomino* t);
        TileDomino* getTile();
    private:
        int score = 0;
        TileDomino* currentTile;
};

class PlayerTrax : public Player{
    public:
        PlayerTrax();
        void setTile(TileTrax* t);
        TileTrax* getTile();
    private:
        int score = 0;
        TileTrax* currentTile;
};

#endif