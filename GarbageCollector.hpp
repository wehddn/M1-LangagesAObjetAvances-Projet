#ifndef GARBAGECOLLECTOR
#define GARBAGECOLLECTOR

#include <SFML/Graphics.hpp>
#include "Cell.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Tile.hpp"

#include <map>
#include <set>
using namespace std;

class GarbageCollector{
    private:
        static set<sf::Text*> texts;
        static set<Cell*> cells;
        static set<pair<int,int>*> pairsIntInt;
        static set<sf::RectangleShape*> rectangleShapes;
        static set<Board*> boards;
        static set<Player*> players;
        static set<sf::Texture*> textures;
        static set<Tile*> tiles;
    public:
        GarbageCollector();
        ~GarbageCollector();
        static void create(sf::Text* text);
        static void create(Cell* cell);
        static void create(pair<int,int>* pairIntInt);
        static void create(sf::RectangleShape* rectangleShape);
        static void create(Board* board);
        static void create(Player* player);
        static void create(sf::Texture* texture);
        static void create(Tile* tile);

        static void del(sf::Text* text);
        static void del(Cell* cell);
        static void del(pair<int,int>* pairIntInt);
        static void del(sf::RectangleShape* rectangleShape);
        static void del(Board* board);
        static void del(Player* player);
        static void del(sf::Texture* texture);
        static void del(Tile* tile);
};

#endif