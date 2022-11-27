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

    //sf::Sprite sprite;
    //sprite.setTexture(texture);
    //sprite.scale(sf::Vector2f(0.25,0.25));

    //t->getSprite()->setTexture(texture);
    //t->getSprite()->scale(sf::Vector2f(0.5,0.5));

    sf::Font font;
    font.loadFromFile("./src/Gargi.ttf");
    sf::Text text("", font, 20);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setString("T");

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
        /*float w = t->getSprite()->getGlobalBounds().width;
        float h = t->getSprite()->getGlobalBounds().height;
        sf::FloatRect fr = text.getGlobalBounds();*/

        window.draw(*t);
/*
        sf::Text text2 = text;
        sf::Text text3 = text;
        sf::Text text4 = text;
        sf::Text text5 = text;
        sf::Text text6 = text;
        sf::Text text7 = text;
        sf::Text text8 = text;
        int textx = x-fr.width/2;
        int texty = y-fr.height/2;
        //u - 0
        text.setPosition(textx + w/4.2/2, texty + h/4.2 + h/11.6);
        text2.setPosition(textx + w/4.2/2, texty + h/4.2 + h/11.6*3);
        text3.setPosition(textx + w/4.2/2, texty + h/4.2 + h/11.6*5);
        
        //r - 1
        text7.setPosition(textx + w - w/4/2, texty + h/4.2 + h/11.6);
        text7.setPosition(textx + w - w/4/2, texty + h/4.2 + h/11.6*3);
        text7.setPosition(textx + w - w/4/2, texty + h/4.2 + h/11.6*5);

        //d - 2
        text8.setPosition(textx + w/4.2 + w/11.6, texty + h - h/4/2);
        text8.setPosition(textx + w/4.2 + w/11.6*3, texty + h - h/4/2);
        text8.setPosition(textx + w/4.2 + w/11.6*5, texty + h - h/4/2);

        //l - 3
        text4.setPosition(textx + w/4.2 + w/11.6, texty + h/4.2/2);
        text5.setPosition(textx + w/4.2 + w/11.6*3, texty + h/4.2/2);
        text6.setPosition(textx + w/4.2 + w/11.6*5, texty + h/4.2/2);
        window.draw(*t);*/
/*
    
		window.draw(text);
        window.draw(text2);
        window.draw(text3);

        window.draw(text4);
        window.draw(text5);
        window.draw(text6);

        window.draw(text7);

        window.draw(text8);
*/
        window.display();
    }

    return 0;
}