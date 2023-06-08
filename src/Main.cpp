#include "Menu.hpp"
#include "GarbageCollector.hpp"

#include <SFML/Graphics.hpp>

#include "iostream"

int main()
{
    srand(time(NULL));
    Menu menu(800, 800);
    menu.menuLoop();
}