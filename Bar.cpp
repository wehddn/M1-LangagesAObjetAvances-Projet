#include "Bar.hpp"

#include <iostream>

Bar::Bar(float height, vector<Player*> players){
    barh = height;
    rectBar.setSize(sf::Vector2f(barw, barh));
    rectBar.setFillColor(sf::Color::Black);
    rectBar.setOutlineThickness(3);
    rectBar.setOutlineColor(sf::Color::White);

    playersNames = std::vector<sf::Text*>();
    playersScores = std::vector<sf::Text*>();

    font.loadFromFile("./src/Gargi.ttf");

    for (int i=0; i<int(players.size()); i++){
        sf::Text* text = new sf::Text();
        text->setFont(font);
        text->setCharacterSize(17);
        text->setFillColor(sf::Color::White);
        text->setStyle(sf::Text::Underlined);
        text->setPosition(sf::Vector2f(4, barw+3 + i*21));
        text->setString(players.at(i)->getName() + " : ");
        playersNames.push_back(text);
    }

    for (int i=0; i<int(players.size()); i++){
        sf::Text* text = new sf::Text();
        text->setFont(font);
        text->setCharacterSize(17);
        text->setFillColor(sf::Color::White);
        text->setStyle(sf::Text::Underlined);
        text->setPosition(sf::Vector2f(90, barw+3 + i*21));
        text->setString("0");
        playersScores.push_back(text);
    }
    

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

void Bar::setScore(int player, int score){
    playersScores.at(player)->setString(to_string(score));
}

void Bar::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rectBar);
    target.draw(displayedTile);
    for(auto& text:playersNames){
        target.draw(*text);
    }
    for(auto& text:playersScores){
        target.draw(*text);
    }
}