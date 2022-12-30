#include "Tile.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Tile::Tile(int tileValue){}

Tile::Tile(){};

void Tile::setText(float x, float y){
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

void Tile::setPosition(const sf::Vector2f &position){
    rect.setPosition(position);
    setText(position.x, position.y);
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rect);

    for (int i=0; i<4; i++){
        for (int j=0; j<3; j++){
            target.draw(text[i][j]);
        }
    }
}

sf::RectangleShape* Tile::getRect(){
    return &rect;
}

void Tile::turn(){
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

void Tile::rotate(){}

vector<vector<int>> Tile::getSides(){
    return sides;
}