#ifndef GAME
#define GAME

#include "Tile.hpp"
#include "Board.hpp"
#include "Bar.hpp"
#include "Player.hpp"

#include<vector>

using namespace std;

class Game{
    public:
        Game();
        Tile* getTile();
        Board* getBoard();
        void setDeck();
        void setPlayers();
        void nextPlayer();
        void gameLoop();
        int getPlayersNumber();
    private:
        vector<Tile*> deck;
        Board* board;
        int boardX; int boardY;
        int deck_size = 100;
        int playersNumber = 2;
        int current_player_number = 0;
        vector<Player*> players;
        Player *current_player;
};

std::ostream& operator<< (std::ostream &out, Game &game);

#endif