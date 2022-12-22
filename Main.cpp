#include "Tile.hpp"
#include "Game.hpp"
#include "Menu.hpp"

#include <SFML/Graphics.hpp>

#include "iostream"

int main()
{
    srand(time(NULL));
    Menu menu(800, 800);
    menu.menuLoop();

    //Game g{};
    //g.gameLoop();
}