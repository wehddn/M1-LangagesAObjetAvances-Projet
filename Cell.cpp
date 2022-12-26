#include "Cell.hpp"

#include <iostream>

Cell::Cell(){}

void Cell::newRect(){
    rect = new sf::RectangleShape(sf::Vector2f(100, 100));
    rect->setFillColor(sf::Color::Transparent);
    rect->setOutlineThickness(2);
    rect->setOutlineColor(sf::Color::Transparent);
}

void Cell::setRect(sf::RectangleShape* newrect){
    rect = newrect;
}

sf::RectangleShape* Cell::getRect(){
    return rect;
}

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const {}