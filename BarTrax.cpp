#include "Bar.hpp"
#include "GarbageCollector.hpp"

#include <iostream>

BarTrax::BarTrax(float height, vector<PlayerTrax*> players){
    barh = height;
    setBar();

    for (int i=0; i<int(players.size()); i++){
        sf::Text* text1 = new sf::Text(*text);
        GarbageCollector::create(text1);
        text1->setPosition(sf::Vector2f(4, tileh+3 + i*21));
        text1->setString(players.at(i)->getName());
        playersNames.push_back(text1);
    }

    sf::Text* rotate = new sf::Text(*text);
    GarbageCollector::create(rotate);
    rotate->setPosition(sf::Vector2f(4, barh - 3*22));
    rotate->setString("Rotate : Up");
    settings.push_back(rotate);

    setEndText();
}

void BarTrax::displayNextPlayer(int current_player_number){

    int previous_player_number = 0;
    if (current_player_number == 0)
        previous_player_number = int(playersNames.size())-1;
    else 
        previous_player_number = current_player_number - 1;

    playersNames.at(previous_player_number)->setFillColor(sf::Color::White);

    playersNames.at(current_player_number)->setFillColor(sf::Color::Green);

}

void BarTrax::setDisplayedTile(Tile* t){
    displayedTile = *t;
    displayedTile.setPosition(sf::Vector2f(tileh/2, tileh/2));
    displayedTile.getRect()->setOutlineThickness(3);
    displayedTile.getRect()->setOutlineColor(sf::Color::White);
}

void BarTrax::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rectBar);

    if(!endGame)
        target.draw(displayedTile);
    else
        target.draw(rectEmpty);

    for(auto& text:playersNames){
        target.draw(*text);
    }

    for(auto& text:settings){
        target.draw(*text);
    }
    
    if(endGame){
        target.draw(*endGameText);
    }
}