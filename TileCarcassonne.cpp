#include "Tile.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

TileCarcassonne::TileCarcassonne(sf::Texture *texture, int tileType){
    this->head = texture;
    setUpRect();
    setSides(tileType);
}

void TileCarcassonne::setUpRect(){
    int recth = 120;    //TODO modifier
    getRect()->setSize(sf::Vector2f(recth, recth));
    font.loadFromFile("./src/Gargi.ttf");
    getRect()->setTexture(this->head);
    getRect()->setOrigin(sf::Vector2f(getRect()->getLocalBounds().width, getRect()->getLocalBounds().height)/2.f);
    directions = {true, false, true, false};
}

void TileCarcassonne::setSides(int x){
    switch (x)
    {
    case 0:
        sides = {{0,0,0},{0,0,0},{0,1,0},{0,1,0}};
        break;
    case 1:
        sides = {{2,2,2},{0,1,0},{0,1,0},{0,0,0}};
        break;
	case 2:
        extraPoints = true;
	case 5:
        sides = {{2,2,2},{0,1,0},{0,1,0},{2,2,2}};
        break;
	case 19:
        extraPoints = true;
	case 3:
        sides = {{2,2,2},{2,2,2},{0,1,0},{2,2,2}};
        break;
	case 4:
        extraPoints = true;
	case 11:
        sides = {{2,2,2},{2,2,2},{0,0,0},{2,2,2}};
        break;
	case 6:
        sides = {{2,2,2},{0,1,0},{0,1,0},{0,1,0}};
        break;
	case 7:
        sides = {{0,1,0},{0,0,0},{0,1,0},{0,0,0}};
        break;
	case 8:
        sides = {{0,0,0},{0,1,0},{0,1,0},{0,1,0}};
        break;
		
	case 9:
        sides = {{2,2,2},{0,0,0},{0,0,0},{0,0,0}};
        break;
	case 10:
        sides = {{2,2,2},{2,2,2},{0,0,0},{0,0,0}};
        break;
	case 12:
        sides = {{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
        break;
	case 13:
        sides = {{0,0,0},{0,0,0},{0,1,0},{0,0,0}};
        break;
	case 22:
        extraPoints = true;
	case 14:
        sides = {{2,2,2},{0,0,0},{0,0,0},{2,2,2}};
        break;
	case 15:
        extraPoints = true;
	case 18:
        sides = {{0,0,0},{2,2,2},{0,0,0},{2,2,2}};
        break;
	case 16:
        sides = {{2,2,2},{0,1,0},{0,0,0},{0,1,0}};
        break;
	case 17:
        sides = {{2,2,2},{0,0,0},{0,1,0},{0,1,0}};
        break;
		
	case 20:
        extraPoints = true;
		sides = {{2,2,2},{2,2,2},{2,2,2},{2,2,2}};
        break;
	case 21:
		sides = {{0,1,0},{0,1,0},{0,1,0},{0,1,0}};
        break;
	case 23:
		sides = {{0,0,0},{2,2,2},{0,0,0},{2,2,2}};
        break;
    }
}

vector<vector<int>> TileCarcassonne::getSides(){
    return sides;
}

void TileCarcassonne::setPosition(const sf::Vector2f &position){
    rect.setPosition(position);
    //setText(position.x, position.y);
}

void TileCarcassonne::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rect);
}

sf::RectangleShape* TileCarcassonne::getRect(){
    return &rect;
}

void TileCarcassonne::rotate(){
    getRect()->rotate(90);
    directions.insert(directions.begin(), directions[3]);
    directions.pop_back();
}

vector<bool> TileCarcassonne::getDirections(){
    return directions;
}