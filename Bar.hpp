#ifndef BAR
#define BAR

#include <SFML/Graphics.hpp>
#include "Tile.hpp"
#include "Player.hpp"

using namespace std;

class Bar : public sf::Drawable {
    public:
        Bar();
        void setBar();
        void setEndText();
        void setEndGame();
        int displayNextPlayer(int current_player);
    protected:
        sf::RectangleShape rectBar;
        sf::RectangleShape rectEmpty;
        sf::Font font;
        vector<sf::Text*> playersNames;
        int barh; //TODO modifier
        sf::Text* text;
        sf::Text* endGameText; 
        vector<sf::Text*> settings;
        Tile displayedTile;
        int barw = 120;
        int tileh = 120;
        bool endGame = false;
    private:
        vector<sf::Text*> playersScores;
};

class BarDomino : public Bar {
    public:
        BarDomino(float barw, vector<PlayerDomino*>);
        void setScore(int player, int score);
        void displayNextPlayer(int current_player);
        void setDisplayedTile(Tile*);
    private:
        vector<sf::Text*> playersScores;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

class BarTrax : public Bar {
    public:
        BarTrax(float barw, vector<PlayerTrax*>);
        void setDisplayedTile(Tile*);
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

class BarCarcassonne : public Bar {
    public:
        BarCarcassonne(float barw, vector<PlayerCarcassonne*>);
        void setDisplayedTile(Tile*);
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif