#ifndef CELL
#define CELL

#include <SFML/Graphics.hpp>

#include "Tile.hpp"

#include <ostream>
#include <vector>

using namespace std;

class Cell : public sf::Drawable {
    public:
        Cell();
        void newRect();
        void setRect(sf::RectangleShape* rect); //TODO merge new and set in set with default value
        sf::RectangleShape* getRect();
    protected:
        sf::RectangleShape* rect;
    private:
        Tile* t = nullptr;;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;      
};

class CellDomino : public Cell {
    public:
        CellDomino();
        void setTile(TileDomino* t);
        TileDomino* getTile();
    private:
        TileDomino* t = nullptr;;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;      
};

class CellTrax : public Cell {
    public:
        CellTrax();
        void setTile(TileTrax* t);
        TileTrax* getTile();
    private:
        TileTrax* t = nullptr;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        
};

#endif