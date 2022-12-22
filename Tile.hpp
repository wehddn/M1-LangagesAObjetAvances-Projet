#ifndef TILE
#define TILE

#include <SFML/Graphics.hpp>

#include <ostream>
#include <vector>

using namespace std;

class Tile : public sf::Drawable {
    public:
        Tile(int tileValue);
        Tile();
        void turn();
        vector<vector<int>> getSides();
        sf::RectangleShape* getRect();
        void setPosition(const sf::Vector2f &position);
    private:
        vector<vector<int>> sides;
        sf::Text text[4][3];
        sf::RectangleShape rect;
        sf::Font font;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void setUpRect();
        void setText(float x, float y);
};

std::ostream& operator<< (std::ostream &out, Tile &tile);

#endif