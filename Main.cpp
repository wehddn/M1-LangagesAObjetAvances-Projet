#include "Tile.hpp"
#include "Game.hpp"

#include <SFML/Graphics.hpp>

#include "iostream"

int main()
{
    Game g{};
    Tile* t = new Tile();
    
    int x = 0, y = 0;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    std::cout << "Start!\n";

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        t->getSprite()->setPosition(x,y);

        window.draw(*t);

        window.display();
    }

    return 0;
}