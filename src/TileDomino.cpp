#include "Tile.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

TileDomino::TileDomino(int tileValue){
    tileValue++;
    for(int i=0; i<4; i++)
    {
        sides.push_back(std::vector<int>());
        for(int j=0; j<3; j++)
        {    
            sides[i].push_back((rand() % (tileValue)));
        }
    }
    setUpRect();
}

TileDomino::TileDomino(){};

void TileDomino::setUpRect(){ //TODO charger des textures dans Game
    int recth = 120;    //TODO modifier
    getRect()->setSize(sf::Vector2f(recth, recth));
    font.loadFromFile("./resources/Gargi.ttf");
    sf::Texture *texture = new sf::Texture;
    
    
    texture->loadFromFile("./resources/tile.png");
    getRect()->setTexture(texture);
        
    for (int i=0; i<4; i++){
        for (int j=0; j<3; j++){
            text[i][j].setFont(font);
            text[i][j].setCharacterSize(15);
            text[i][j].setFillColor(sf::Color::Red);
            text[i][j].setStyle(sf::Text::Bold | sf::Text::Underlined);
            text[i][j].setString(to_string(sides.at(i).at(j)));
        }
    }

    setText(0, 0);
}

void TileDomino::setText(float x, float y){
    float w = getRect()->getGlobalBounds().width;
    float h = getRect()->getGlobalBounds().height;
    sf::FloatRect fr = text[0][0].getGlobalBounds();
    int textx = x-fr.width/2;
    int texty = y-fr.height/2;

    for (int i=0; i<4; i++){
        for (int j=0; j<3; j++){
            fr = text[i][j].getGlobalBounds();
            textx = x-fr.width/2;
            texty = y-fr.height/2;
            switch (i)
            {
                case 0:
                    text[i][j].setPosition(textx + w/4.2 + w/11.6*(j*2+1), texty + h/4.2/2);
                    break;
                case 1:
                    text[i][j].setPosition(textx + w - w/4/2, texty + h/4.2 + h/11.6*(j*2+1));
                    break;
                case 2:
                    text[i][j].setPosition(textx + w/4.2 + w/11.6*(j*2+1), texty + h - h/4/2);
                    break;
                case 3:
                    text[i][j].setPosition(textx + w/4.2/2, texty + h/4.2 + h/11.6*(j*2+1));
                    break;
                default:
                    break;
            }
        }
    }
}

void TileDomino::setPosition(const sf::Vector2f &position){
    rect.setPosition(position);
    setText(position.x, position.y);
}

void TileDomino::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rect);

    for (int i=0; i<4; i++){
        for (int j=0; j<3; j++){
            target.draw(text[i][j]);
        }
    }
}

sf::RectangleShape* TileDomino::getRect(){
    return &rect;
}

void TileDomino::rotate(){
    int size = sides.size()-1;
    vector<int> tmp = sides.back();
    sides.erase(sides.begin()+size);
    sides.insert(sides.begin(), tmp);
    std::reverse(sides.at(2).begin(),sides.at(2).end());
    std::reverse(sides.at(0).begin(),sides.at(0).end());
    
    for (int i=0; i<4; i++){
        for (int j=0; j<3; j++){
            text[i][j].setString(to_string(sides.at(i).at(j)));
        }
    }
}

vector<vector<int>> TileDomino::getSides(){
    return sides;
}