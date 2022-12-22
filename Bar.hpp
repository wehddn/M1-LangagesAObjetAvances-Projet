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
        void displayNextPlayer(int current_player);
        void setEndGame(std::vector<Player*>);
    private:
        Tile displayedTile;
        sf::RectangleShape rectBar;
        sf::RectangleShape rectEmpty;
        int barh; //TODO modifier
        int barw = 120;
        int tileh = 120;
        sf::Font font;
        vector<sf::Text*> playersNames;
        vector<sf::Text*> playersScores;
        vector<sf::Text*> settings;
        sf::Text* endGameText; 
        bool endGame = false;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif