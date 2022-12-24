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
        virtual void turn();
        virtual void rotate();
        virtual vector<vector<int>> getSides();
        virtual sf::RectangleShape* getRect();
        virtual void setPosition(const sf::Vector2f &position);
        vector<vector<int>> sides;
        sf::Text text[4][3];
        sf::RectangleShape rect;
        sf::Font font;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void setUpRect();
        virtual void setText(float x, float y);
};

class TileDomino : public Tile {
    public:
        TileDomino(int tileValue);
        TileDomino();
        void rotate();
        sf::RectangleShape* getRect();
        vector<vector<int>> getSides();
        void setPosition(const sf::Vector2f &position);
    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void setText(float x, float y);
        void setUpRect();
};

class TileTrax : public Tile {
    public:
        TileTrax();
        void rotate(); // tourner de 90°
        void turn(); // changer de sens
        sf::RectangleShape* getRect();
        vector<vector<int>> getSides();
        void setPosition(const sf::Vector2f &position);
    private:
        sf::Texture *head;
        sf::Texture *tail;
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void setText(float x, float y);
        void setUpRect();
        string state = "head";
};

#endif