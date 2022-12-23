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
        virtual Board* getBoard();
        virtual Tile* getTile();
        virtual void setDeck();
        virtual int getDeckSize();
        virtual void setPlayers();
        virtual void nextPlayer();
        virtual void gameLoop();
        virtual int getPlayersNumber();
        vector<Tile*> deck;
        Board* board;
        int boardX; int boardY;
        int deck_size = 3;
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
        Board* getBoard();
        TileDomino* getTile();
        int getDeckSize();
        void setPlayers();
        void nextPlayer();
        void setDeck();
        int getPlayersNumber();
        void gameLoop();
    private :
        vector<TileDomino*> deck;
};

class GameTrax : public Game{
public :
        GameTrax();
        GameTrax(int settings[2]);
        Board* getBoard();
        TileTrax* getTile();
        int getDeckSize();
        void setPlayers();
        void nextPlayer();
        void setDeck();
        int getPlayersNumber();
        void gameLoop();
    private :
        vector<TileTrax*> deck;
};


std::ostream& operator<< (std::ostream &out, Game &game);

#endif