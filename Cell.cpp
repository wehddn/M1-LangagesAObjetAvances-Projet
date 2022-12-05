#include "Cell.hpp"

#include <iostream>

Cell::Cell(){}

void Cell::newRect(){
    rect = new sf::RectangleShape(sf::Vector2f(100, 100));
    rect->setFillColor(sf::Color::Transparent);
    rect->setOutlineThickness(2);
    rect->setOutlineColor(sf::Color::Green);
}

void Cell::setRect(sf::RectangleShape* newrect){
    rect = newrect;
}

void Cell::setTile(Tile* tile){
    t = tile;
}

sf::RectangleShape* Cell::getRect(){
    return rect;
}

Tile* Cell::getTile(){
    return t;
}

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if(t!=nullptr){
        target.draw(*t);
    }
    else{
        target.draw(*rect);
    }
}