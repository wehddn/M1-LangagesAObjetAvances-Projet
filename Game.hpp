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
        virtual int getDeckSize();
        virtual void nextPlayer();
        virtual int getPlayersNumber();
        virtual void gameLoop();
        virtual void setCurrentPlayer(int current_player_number);
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
        GameDomino(int settings[2]);
        BoardDomino* getBoard();
        TileDomino* getTile();
        int getDeckSize();
        void setPlayers();
        void setDeck();
        void setCurrentPlayer(int current_player_number);
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
        void setDeck();
        void setCurrentPlayer(int current_player_number);
        void gameLoop();
    private :
        vector<TileTrax*> deck;
        BoardTrax* boardTrax;
        PlayerTrax *current_player;
        vector<PlayerTrax*> players;
};

struct Camera
{
    sf::View view;
    sf::Vector2f pos;
    bool locked = false;

    void lock(float x, float y)
    {
        pos.x = x;
        pos.y = y;
        locked = true;
    }

    void unlock() { locked = false; }

    void move(float x, float y)
    {
        if (locked)
        {
            view.move(pos.x - x, pos.y - y);
            pos.x = x;
            pos.y = y;
        }
    }
};

#endif