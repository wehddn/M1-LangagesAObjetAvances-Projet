#ifndef BAR
#define BAR

#include <SFML/Graphics.hpp>
#include "Tile.hpp"

using namespace std;

class Bar : public sf::Drawable {
    public:
        Bar(float barw);
        void setDisplayedTile(Tile*);
    private:
        Tile displayedTile;
        sf::RectangleShape rectBar;
        int barh = 50; //TODO modifier
        int barw;
        sf::Text text;
        sf::Font font;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif