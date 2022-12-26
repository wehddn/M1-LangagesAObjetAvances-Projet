#ifndef BOARD
#define BOARD

#include <SFML/Graphics.hpp>

#include "Cell.hpp"

#include <ostream>
#include <vector>

using namespace std;

class Board : public sf::Drawable {
    public:
        Board();
        void updateBoard();
        vector<vector<Cell*>> getTiles();
        int getTileSize();
        int getStepScore();
    private:
        vector<vector<Cell*>> board;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void setRectAtPositions(int i, int j, int x, int y);
        int boardX; int boardY;
        int boardh = 600; //TODO modifier
        int boardw = 800;
        int recth = 120;
        bool checkSides(int x, int y, Tile* t);
        int sideScore(vector<int> side);
        int stepScore;
};

class BoardDomino : public Board {
    public:
        BoardDomino();
        bool putTile(int x, int y, CellDomino* c, TileDomino* t);
        void updateBoard();
        vector<vector<CellDomino*>> getTiles();
        int getTileSize();
        int getStepScore();
    private:
        vector<vector<CellDomino*>> board;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void setRectAtPositions(int i, int j, int x, int y);
        int boardX; int boardY;
        int boardh = 600; //TODO modifier
        int boardw = 800;
        int recth = 120;
        bool checkSides(int x, int y, Tile* t);
        int sideScore(vector<int> side);
        int stepScore;
};

class BoardTrax : public Board {
    public:
        BoardTrax();
        bool putTile(int x, int y, CellTrax* c, TileTrax* t);
        void updateBoard();
        vector<vector<CellTrax*>> getTiles();
        int getTileSize();
        int getStepScore();
        bool checkPaths(int x, int y, CellTrax* c);
    private:
        vector<vector<CellTrax*>> board;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void setRectAtPositions(int i, int j, int x, int y);
        int boardX; int boardY;
        int boardh = 600; //TODO modifier
        int boardw = 800;
        int recth = 120;
        bool checkSides(int x, int y, TileTrax* t);
        bool checkSize(int x, int y);
        bool checkLeftBoardPath(int x, int y);
};

#endif