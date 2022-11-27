#ifndef TILE
#define TILE

#include <SFML/Graphics.hpp>

#include <ostream>
#include <vector>

using namespace std;

class Tile : public sf::Drawable {
    public:
        Tile();
        void turn();
        vector<vector<int>> getSides();
        sf::Sprite* getSprite();
    private:
        vector<vector<int>> sides;
        sf::Text text[4][3];
        sf::Sprite sprite;
        sf::Font font;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void setUpSprite();
};

std::ostream& operator<< (std::ostream &out, Tile &tile);

#endif