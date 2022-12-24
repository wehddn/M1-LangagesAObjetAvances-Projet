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
        void setTile(Tile* t);
        sf::RectangleShape* getRect();
        Tile* getTile();
    private:
        Tile* t = nullptr;;
        sf::RectangleShape* rect;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        
};

#endif