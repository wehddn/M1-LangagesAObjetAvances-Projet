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
        TileTrax(sf::Texture *textureH, sf::Texture *textureT);
        void rotate(); // tourner de 90°
        void turn(); // changer de sens
        sf::RectangleShape* getRect();
        vector<bool> getDirections();
        void setPosition(const sf::Vector2f &position);
    private:
        sf::Texture *head;
        sf::Texture *tail;
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void setUpRect();
        vector<bool> directions; //n, b, n, b (head) ou b, n, n, b (tail)
        string state = "head";
};

class TileCarcassonne : public Tile {
    public:
        TileCarcassonne(sf::Texture *texture, int tileType);
        void rotate(); // tourner de 90°
        sf::RectangleShape* getRect();
        vector<bool> getDirections();
        vector<vector<int>> getSides();
        void setPosition(const sf::Vector2f &position);
    private:
        void setSides(int x);
        sf::Texture *head;
        sf::Texture *tail;
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void setUpRect();
        vector<vector<int>> sides;
        vector<bool> directions; //n, b, n, b (head) ou b, n, n, b (tail)
        string state = "head";
        bool extraPoints = false;
};

#endif