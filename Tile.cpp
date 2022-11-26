#include "Tile.hpp"

#include <iostream>

Tile::Tile(){
    for(int i=0; i<4; i++)
    {
        sides.push_back(std::vector<int>());
        for(int j=0; j<3; j++)
        {    
            sides[i].push_back((rand() % 3));   
        }
    }
}

void Tile::turn(){
    int size = sides.size()-1;
    vector<int> tmp = sides.back();
    sides.erase(sides.begin()+size);
    sides.insert(sides.begin(), tmp);
}

vector<vector<int>> Tile::getSides(){
    return sides;
}

std::ostream& operator<< (std::ostream &out, Tile &tile)
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