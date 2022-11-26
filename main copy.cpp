#include <SFML/Graphics.hpp>
#include "iostream"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(50,50));
    rect.setFillColor(sf::Color::Green);

    int speed = 1;
    sf::Vector2i mouse;

    std::cout << "Start!\n";

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            rect.move(0,-speed);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            rect.move(0,speed);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            rect.move(-speed,0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            rect.move(speed,0);
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            mouse = sf::Mouse::getPosition(window);
            rect.setPosition(mouse.x, mouse.y);
        }

        window.clear();
        window.draw(rect);
        window.display();
    }

    return 0;
}