#include "Bar.hpp"

#include <iostream>

Bar::Bar(){
    /*barh = height;
    rectBar.setSize(sf::Vector2f(barw, barh));
    rectBar.setFillColor(sf::Color::Black);
    rectBar.setOutlineThickness(3);
    rectBar.setOutlineColor(sf::Color::White);

    rectEmpty.setSize(sf::Vector2f(tileh, tileh));
    rectEmpty.setFillColor(sf::Color::Black);
    rectEmpty.setOutlineThickness(3);
    rectEmpty.setOutlineColor(sf::Color::White);

    playersNames = std::vector<sf::Text*>();
    playersScores = std::vector<sf::Text*>();

    font.loadFromFile("./src/Gargi.ttf");

    sf::Text* text = new sf::Text();
    text->setFont(font);
    text->setCharacterSize(17);
    text->setFillColor(sf::Color::White);
    text->setStyle(sf::Text::Underlined);

    for (int i=0; i<int(players.size()); i++){
        sf::Text* text1 = new sf::Text(*text);
        text1->setPosition(sf::Vector2f(4, tileh+3 + i*21));
        text1->setString(players.at(i)->getName() + " : ");
        playersNames.push_back(text1);
    }

    for (int i=0; i<int(players.size()); i++){
        sf::Text* text1 = new sf::Text(*text);
        text1->setPosition(sf::Vector2f(90, tileh+3 + i*21));
        text1->setString("0");
        playersScores.push_back(text1);
    }

    sf::Text* zoom = new sf::Text(*text);
    zoom->setPosition(sf::Vector2f(4, barh - 1*22));
    zoom->setString("Zoom : Z/X");
    settings.push_back(zoom);

    sf::Text* throwOut = new sf::Text(*text);
    throwOut->setPosition(sf::Vector2f(4, barh - 2*22));
    throwOut->setString("Throw out : D");
    settings.push_back(throwOut);

    sf::Text* turn = new sf::Text(*text);
    turn->setPosition(sf::Vector2f(4, barh - 3*22));
    turn->setString("Turn : ->");
    settings.push_back(turn);

    float playersTextHeight = playersScores.at(players.size()-1)->getPosition().y;
    float settingsTextHeight = settings.at(settings.size()-1)->getPosition().y;
    float endGameHeight = playersTextHeight + (settingsTextHeight-playersTextHeight)/2;
    endGameText = new sf::Text(*text);
    endGameText->setPosition(sf::Vector2f(4, endGameHeight));
    endGameText->setString("Game Over!");*/
}

void Bar::setBar(){
    rectBar.setSize(sf::Vector2f(barw, barh));
    rectBar.setFillColor(sf::Color::Black);
    rectBar.setOutlineThickness(3);
    rectBar.setOutlineColor(sf::Color::White);

    rectEmpty.setSize(sf::Vector2f(tileh, tileh));
    rectEmpty.setFillColor(sf::Color::Black);
    rectEmpty.setOutlineThickness(3);
    rectEmpty.setOutlineColor(sf::Color::White);

    font.loadFromFile("./src/Gargi.ttf");

    playersNames = std::vector<sf::Text*>();

    text = new sf::Text();
    text->setFont(font);
    text->setCharacterSize(17);
    text->setFillColor(sf::Color::White);
    text->setStyle(sf::Text::Underlined);

    sf::Text* zoom = new sf::Text(*text);
    zoom->setPosition(sf::Vector2f(4, barh - 1*22));
    zoom->setString("Zoom : Z/X");
    settings.push_back(zoom);

    sf::Text* turn = new sf::Text(*text);
    turn->setPosition(sf::Vector2f(4, barh - 2*22));
    turn->setString("Turn : Right");
    settings.push_back(turn);
}

void Bar::setEndText(){
    float playersTextHeight = playersNames.at(playersNames.size()-1)->getPosition().y;
    float settingsTextHeight = settings.at(settings.size()-1)->getPosition().y;
    float endGameHeight = playersTextHeight + (settingsTextHeight-playersTextHeight)/2;
    endGameText = new sf::Text(*text);
    endGameText->setPosition(sf::Vector2f(4, endGameHeight));
    endGameText->setString("Game Over!");
}

void Bar::setScore(int player, int score){
    playersScores.at(player)->setString(to_string(score));
}

void Bar::displayNextPlayer(int current_player_number){

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

void Bar::setEndGame(std::vector<Player*> players){
    endGame = true;
}

void Bar::draw(sf::RenderTarget& target, sf::RenderStates states) const {
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