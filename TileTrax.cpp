#include "Tile.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

TileTrax::TileTrax(sf::Texture *textureH, sf::Texture *textureT){
    this->head = textureH;
    this->tail = textureT;
    setUpRect();
}


void TileTrax::setUpRect(){
    int recth = 120;    //TODO modifier
    getRect()->setSize(sf::Vector2f(recth, recth));
    font.loadFromFile("./src/Gargi.ttf");
    //sf::Texture *textureH = new sf::Texture;
    //textureH->loadFromFile("./src/tileTraxH.png");
    //this->head = textureH;
    //sf::Texture *textureT = new sf::Texture;
    //textureT->loadFromFile("./src/tileTraxT.png");
    //this->tail = textureT;
    getRect()->setTexture(this->head);
    getRect()->setOrigin(sf::Vector2f(getRect()->getLocalBounds().width, getRect()->getLocalBounds().height)/2.f);
    directions = {true, false, true, false};
    
}

void TileTrax::setText(float x, float y){
    
}

void TileTrax::setPosition(const sf::Vector2f &position){
    rect.setPosition(position);
    setText(position.x, position.y);
}

void TileTrax::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rect);
}

sf::RectangleShape* TileTrax::getRect(){
    return &rect;
}

void TileTrax::turn(){
    if(state == "head"){
        state = "tail";
        getRect()->setTexture(this->tail);
        getRect()->setRotation(0);
        directions = {false, true, true, false};
    }
    else{
        state = "head";
        getRect()->setTexture(this->head);
        getRect()->setRotation(0);
        directions = {true, false, true, false};
    }
}

void TileTrax::rotate(){
    getRect()->rotate(90);
    directions.insert(directions.begin(), directions[3]);
    directions.pop_back();
}

vector<bool> TileTrax::getDirections(){
    return directions;
}