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
        Game(int settings[2]);
        virtual Tile* getTile();
        virtual void setDeck();
        virtual int getDeckSize();
        virtual void setPlayers();
        virtual void nextPlayer();
        virtual void gameLoop();
        virtual int getPlayersNumber();
        vector<Tile*> deck;
        int boardX; int boardY;
        int deck_size = 64;
        int playersNumber = 2;
        int current_player_number = 0;
        vector<Player*> players;
        Player *current_player;
        int tileValue;
};

class GameDomino : public Game {
    public :
        GameDomino();
        GameDomino(int settings[2]);
        BoardDomino* getBoard();
        TileDomino* getTile();
        int getDeckSize();
        void setPlayers();
        void nextPlayer();
        void setDeck();
        int getPlayersNumber();
        void gameLoop();
    private :
        vector<TileDomino*> deck;
        BoardDomino* board;
        vector<PlayerDomino*> players;
        PlayerDomino *current_player;
};

class GameTrax : public Game{
public :
        GameTrax();
        BoardTrax* getBoardTrax();
        TileTrax* getTile();
        int getDeckSize();
        void setPlayers();
        void nextPlayer();
        void setDeck();
        int getPlayersNumber();
        void gameLoop();
    private :
        vector<TileTrax*> deck;
        BoardTrax* boardTrax;
        PlayerTrax *current_player;
        vector<PlayerTrax*> players;
};

#endif