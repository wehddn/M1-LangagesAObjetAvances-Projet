#include "GarbageCollector.hpp"

#include <iostream>

set<sf::Text*> GarbageCollector::texts;
set<Cell*> GarbageCollector::cells;
set<pair<int,int>*> GarbageCollector::pairsIntInt;
set<sf::RectangleShape*> GarbageCollector::rectangleShapes;
set<Board*> GarbageCollector::boards;
set<Player*> GarbageCollector::players;
set<sf::Texture*> GarbageCollector::textures;
set<Tile*> GarbageCollector::tiles;

GarbageCollector::GarbageCollector(){};

GarbageCollector::~GarbageCollector(){
    clean();
};

void GarbageCollector::clean(){
    for(sf::Text* o : texts ){
        delete(o);
        del(o);
    }
    for(Cell* o : cells ){
        delete(o);
        del(o);
    }
    for(pair<int,int>* o : pairsIntInt ){
        delete(o);
        del(o);
    }
    for(sf::RectangleShape* o : rectangleShapes ){
        delete(o);
        del(o);
    }
    for(Board* o : boards ){
        delete(o);
        del(o);
    }
    for(Player* o : players ){
        delete(o);
        del(o);
    }
    for(sf::Texture* o : textures ){
        delete(o);
        del(o);
    }
    for(Tile* o : tiles ){
        delete(o);
        del(o);
    }
};

void GarbageCollector::create(sf::Text* object){
    texts.insert(object);
}
void GarbageCollector::create(Cell* object){
    cells.insert(object);
}
void GarbageCollector::create(pair<int,int>* object){
    pairsIntInt.insert(object);
}
void GarbageCollector::create(sf::RectangleShape* object){
    rectangleShapes.insert(object);
}
void GarbageCollector::create(Board* object){
    boards.insert(object);
}
void GarbageCollector::create(Player* object){
    players.insert(object);
}
void GarbageCollector::create(sf::Texture* object){
    textures.insert(object);
}
void GarbageCollector::create(Tile* object){
    tiles.insert(object);
}


void GarbageCollector::del(sf::Text* object){
    texts.erase(object);
}
void GarbageCollector::del(Cell* object){
    cells.erase(object);
}
void GarbageCollector::del(pair<int,int>* object){
    pairsIntInt.erase(object);
}
void GarbageCollector::del(sf::RectangleShape* object){
    rectangleShapes.erase(object);
}
void GarbageCollector::del(Board* object){
    boards.erase(object);
}
void GarbageCollector::del(Player* object){
    players.erase(object);
}
void GarbageCollector::del(sf::Texture* object){
    textures.erase(object);
}
void GarbageCollector::del(Tile* object){
    tiles.erase(object);
}