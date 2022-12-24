#include "Tile.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

TileTrax::TileTrax(){
    setUpRect();
}


void TileTrax::setUpRect(){
    int recth = 120;    //TODO modifier
    getRect()->setSize(sf::Vector2f(recth, recth));
    font.loadFromFile("./src/Gargi.ttf");
    sf::Texture *textureH = new sf::Texture;
    textureH->loadFromFile("./src/tileTraxH.png");
    this->head = textureH;
    sf::Texture *textureT = new sf::Texture;
    textureT->loadFromFile("./src/tileTraxT.png");
    this->tail = textureT;
    getRect()->setTexture(textureH);
    
}

void TileTrax::setText(float x, float y){
    
}

void TileTrax::setPosition(const sf::Vector2f &position){
    rect.setPosition(position);
    setText(position.x, position.y);
}

void TileTrax::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rect);
}

sf::RectangleShape* TileTrax::getRect(){
    return &rect;
}

void TileTrax::turn(){
    if(state == "head"){
        state = "tail";
        getRect()->setTexture(this->head);
    }
    else{
        state = "head";
        getRect()->setTexture(this->tail);
    }
}

void TileTrax::rotate(){
    getRect()->rotate(90);
}

vector<vector<int>> TileTrax::getSides(){
    return sides;
}

std::ostream& operator<< (std::ostream &out, TileTrax &tile)
{   string res = "";
    vector<vector<int>> sides = tile.getSides(); 
    for (int i=0; i<4; i++){
        switch (i)
        {
        case 0:
            res+= "up   : ";
            break;
        case 1:
            res+= "right: ";
            break;
        case 2:
            res+= "down : ";
            break;
        case 3:
            res+= "left : ";
            break;
        default:
            break;
        }
        for (int j=0; j<3; j++){
            res += to_string(sides.at(i).at(j)) + " ";
        }
        res += "\n";
    }

    out << res;
    return out;
}