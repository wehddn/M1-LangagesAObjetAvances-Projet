#include "Bar.hpp"

#include <iostream>

Bar::Bar(float width){
    barw = width;
    rectBar.setSize(sf::Vector2f(barw, barh));
    rectBar.setFillColor(sf::Color::Black);
    rectBar.setOutlineThickness(3);
    rectBar.setOutlineColor(sf::Color::White);
    

/*    font.loadFromFile("./src/Gargi.ttf");

    text.setFont(font);
    text.setCharacterSize(17);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Underlined);
    text.setString("test");
    
    text.setPosition(sf::Vector2f(130, 5));*/

}

void Bar::setDisplayedTile(Tile* t){
    displayedTile = *t;
    displayedTile.setPosition(sf::Vector2f(0, 0));    
    displayedTile.getRect()->setOutlineThickness(3);
    displayedTile.getRect()->setOutlineColor(sf::Color::White);
}

void Bar::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rectBar);
    target.draw(displayedTile);
    target.draw(text);
}