#ifndef BAR
#define BAR

#include <SFML/Graphics.hpp>
#include "Tile.hpp"
#include "Player.hpp"

using namespace std;

class Bar : public sf::Drawable {
    public:
        Bar(float barw, vector<Player*>);
        void setDisplayedTile(Tile*);
        void setScore(int player, int score);
    private:
        Tile displayedTile;
        sf::RectangleShape rectBar;
        int barh; //TODO modifier
        int barw = 120;
        sf::Font font;
        vector<sf::Text*> playersNames;
        vector<sf::Text*> playersScores;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif