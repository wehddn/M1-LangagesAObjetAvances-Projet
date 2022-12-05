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
        bool putTile(int x, int y, Cell* c, Tile* t);
        void updateBoard();
        vector<vector<Cell*>> getTiles();
        int getTileSize();
    private:
        vector<vector<Cell*>> board;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void setRectAtPositions(int i, int j, int x, int y);
        int boardX; int boardY;
        int boardh = 600; //TODO modifier
        int boardw = 800;
        int recth = 120;
        bool checkSides(int x, int y, Tile* t);
};

#endif