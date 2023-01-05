#include "GarbageCollector.hpp"

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
    for(auto &o : texts ){
        delete(o);
    }
    for(auto &o : cells ){
        delete(o);
    }
    for(auto &o : pairsIntInt ){
        delete(o);
    }
    for(auto &o : rectangleShapes ){
        delete(o);
    }
    for(auto &o : boards ){
        delete(o);
    }
    for(auto &o : players ){
        delete(o);
    }
    for(auto &o : textures ){
        delete(o);
    }
    for(auto &o : tiles ){
        delete(o);
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