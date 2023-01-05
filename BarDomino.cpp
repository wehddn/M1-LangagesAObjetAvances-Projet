#include "Bar.hpp"
#include "GarbageCollector.hpp"

#include <iostream>

BarDomino::BarDomino(float height, vector<PlayerDomino*> players){
    barh = height;

    playersScores = std::vector<sf::Text*>();
    
    setBar();

    for (int i=0; i<int(players.size()); i++){
        sf::Text* text1 = new sf::Text(*text);
        GarbageCollector::create(text1);
        text1->setPosition(sf::Vector2f(4, tileh+3 + i*21));
        text1->setString(players.at(i)->getName() + " : ");
        playersNames.push_back(text1);
    }

    for (int i=0; i<int(players.size()); i++){
        sf::Text* text1 = new sf::Text(*text);
        GarbageCollector::create(text1);
        text1->setPosition(sf::Vector2f(90, tileh+3 + i*21));
        text1->setString("0");
        playersScores.push_back(text1);
    }

    sf::Text* throwOut = new sf::Text(*text);
    GarbageCollector::create(throwOut);
    throwOut->setPosition(sf::Vector2f(4, barh - 3*22));
    throwOut->setString("Throw out : D");
    settings.push_back(throwOut);

    setEndText();
}

void BarDomino::setScore(int player, int score){
    playersScores.at(player)->setString(to_string(score));
}

void BarDomino::displayNextPlayer(int current_player_number){

    int previous_player_number = 0;
    if (current_player_number == 0)
        previous_player_number = int(playersNames.size())-1;
    else 
        previous_player_number = current_player_number - 1;

    playersScores.at(previous_player_number)->setFillColor(sf::Color::White);
    playersNames.at(previous_player_number)->setFillColor(sf::Color::White);

    playersScores.at(current_player_number)->setFillColor(sf::Color::Green);
    playersNames.at(current_player_number)->setFillColor(sf::Color::Green);

}

void BarDomino::setDisplayedTile(Tile* t){
    displayedTile = *t;
    displayedTile.setPosition(sf::Vector2f(0, 0));
    displayedTile.getRect()->setOutlineThickness(3);
    displayedTile.getRect()->setOutlineColor(sf::Color::White);
}

void BarDomino::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rectBar);

    if(!endGame)
        target.draw(displayedTile);
    else
        target.draw(rectEmpty);

    for(auto& text:playersNames){
        target.draw(*text);
    }
    for(auto& text:playersScores){
        target.draw(*text);
    }

    for(auto& text:settings){
        target.draw(*text);
    }
    
    if(endGame){
        target.draw(*endGameText);
    }
}