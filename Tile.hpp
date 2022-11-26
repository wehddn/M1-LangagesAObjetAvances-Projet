#ifndef TILE
#define TILE

#include <ostream>
#include <vector>

using namespace std;

class Tile{
    private:
        vector<vector<int>> sides;
    public:
        Tile();
        void turn();
        vector<vector<int>> getSides();

};

std::ostream& operator<< (std::ostream &out, Tile &tile);

#endif