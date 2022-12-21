#include "Menu.hpp"
#include "Game.hpp"

#include <iostream>
using namespace std;

Menu::Menu(float width, float height)
{
    if(!font.loadFromFile("arial.TTF")){
        // handle error
    }
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Domino");
    menu[0].setPosition(sf::Vector2f(width / 2,height/(MAX_NUMBER_OF_ITEMS +1) *1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Trax");
    menu[1].setPosition(sf::Vector2f(width / 2,height/(MAX_NUMBER_OF_ITEMS +1) *2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Carcassonne");
    menu[2].setPosition(sf::Vector2f(width / 2,height/(MAX_NUMBER_OF_ITEMS +1) *3));


    selectedItemIndex = 0;
}

Menu::~Menu(){

}

void Menu::draw(sf::RenderWindow &window){
    for(int i=0;i< MAX_NUMBER_OF_ITEMS;i++){
        window.draw(menu[i]);
    }
}

void Menu::MoveUp(){
    if((selectedItemIndex -1 >= 0)){
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::MoveDown(){
    if((selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)){
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::menuLoop(){
    sf::RenderWindow windowM(sf::VideoMode(800,800), "MENU");
    while(windowM.isOpen()){

        sf::Event event;

        while(windowM.pollEvent(event)){
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch(event.key.code){
                    case sf::Keyboard::Up:
                        MoveUp();
                        break;
                    case sf::Keyboard::Down:
                        MoveDown();
                        break;

                    case sf::Keyboard::Return:
                        if(getPressedItem() == 0){
                            Game g{};
                            windowM.close();
                            g.gameLoop();
                            std::cout << "End DOMINO!\n";
                            windowM.create(sf::VideoMode(800,800), "MENU");
                        }
                        break;
                }
                break;
            case sf::Event::Closed:
                windowM.close();
                break;
            }
        }

        windowM.clear();
        draw(windowM);

        windowM.display();
    }
}