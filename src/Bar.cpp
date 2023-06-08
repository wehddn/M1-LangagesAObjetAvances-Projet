#include "Bar.hpp"
#include "GarbageCollector.hpp"

#include <iostream>

Bar::Bar(){}

void Bar::setBar(){
    rectBar.setSize(sf::Vector2f(barw, barh));
    rectBar.setFillColor(sf::Color::Black);
    rectBar.setOutlineThickness(3);
    rectBar.setOutlineColor(sf::Color::White);

    rectEmpty.setSize(sf::Vector2f(tileh, tileh));
    rectEmpty.setFillColor(sf::Color::Black);
    rectEmpty.setOutlineThickness(3);
    rectEmpty.setOutlineColor(sf::Color::White);

    font.loadFromFile("./resources/Gargi.ttf");

    playersNames = std::vector<sf::Text*>();

    text = new sf::Text();
    GarbageCollector::create(text);
    text->setFont(font);
    text->setCharacterSize(17);
    text->setFillColor(sf::Color::White);
    text->setStyle(sf::Text::Underlined);

    sf::Text* zoom = new sf::Text(*text);
    GarbageCollector::create(zoom);
    zoom->setPosition(sf::Vector2f(4, barh - 1*22));
    zoom->setString("Zoom : Z/X");
    settings.push_back(zoom);

    sf::Text* turn = new sf::Text(*text);
    GarbageCollector::create(turn);
    turn->setPosition(sf::Vector2f(4, barh - 2*22));
    turn->setString("Turn : Right");
    settings.push_back(turn);
}

void Bar::setEndText(){
    float playersTextHeight = playersNames.at(playersNames.size()-1)->getPosition().y;
    float settingsTextHeight = settings.at(settings.size()-1)->getPosition().y;
    float endGameHeight = playersTextHeight + (settingsTextHeight-playersTextHeight)/2;
    endGameText = new sf::Text(*text);
    GarbageCollector::create(endGameText);
    endGameText->setPosition(sf::Vector2f(4, endGameHeight));
    endGameText->setString("Game Over!");
}

int Bar::displayNextPlayer(int current_player_number){

    int previous_player_number = 0;
    if (current_player_number == 0)
        previous_player_number = int(playersNames.size())-1;
    else 
        previous_player_number = current_player_number - 1;

    playersNames.at(previous_player_number)->setFillColor(sf::Color::White);
    playersNames.at(current_player_number)->setFillColor(sf::Color::Green);

    return previous_player_number;
}

void Bar::setEndGame(){
    endGame = true;
}