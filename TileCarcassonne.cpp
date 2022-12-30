#include "Tile.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

TileCarcassonne::TileCarcassonne(sf::Texture *texture){
    this->head = texture;
    setUpRect();
}

void TileCarcassonne::setUpRect(){
    int recth = 120;    //TODO modifier
    getRect()->setSize(sf::Vector2f(recth, recth));
    font.loadFromFile("./src/Gargi.ttf");
    getRect()->setTexture(this->head);
    getRect()->setOrigin(sf::Vector2f(getRect()->getLocalBounds().width, getRect()->getLocalBounds().height)/2.f);
    directions = {true, false, true, false};
}

void TileCarcassonne::setPosition(const sf::Vector2f &position){
    rect.setPosition(position);
    //setText(position.x, position.y);
}

void TileCarcassonne::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rect);
}

sf::RectangleShape* TileCarcassonne::getRect(){
    return &rect;
}

void TileCarcassonne::rotate(){
    getRect()->rotate(90);
    directions.insert(directions.begin(), directions[3]);
    directions.pop_back();
}

vector<bool> TileCarcassonne::getDirections(){
    return directions;
}