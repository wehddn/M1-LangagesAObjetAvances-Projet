#include "Tile.hpp"
#include "Game.hpp"

#include <SFML/Graphics.hpp>

#include "iostream"

int main()
{
    Game g{};
    Tile* t = new Tile();

    g.putTile(0, 0, t);
    cout << *t << endl;
    t->turn();
    cout << *t << endl;
    
    int x = 0, y = 0;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(100,100));
    rect.setFillColor(sf::Color{ 100, 100, 100});

    sf::Texture texture;
    texture.loadFromFile("./src/tile.png");
    
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.scale(sf::Vector2f(0.25,0.25));

    sf::Font font;
    font.loadFromFile("./src/Gargi.ttf");
    sf::Text text("", font, 20);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setString("Testttttttttttt");
	text.setPosition(20, 20 );

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

        //first line
        sprite.setPosition(x,y);
        float w = sprite.getLocalBounds().width;
        sf::Sprite sprite1 = sprite;
        sprite1.setPosition(x+(w*0.25),y);
        window.draw(sprite);
        window.draw(sprite1);
        
		//window.draw(text);

        window.display();
    }

    return 0;
}