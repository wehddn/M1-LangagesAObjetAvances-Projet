#include "Menu.hpp"
#include "Game.hpp"

#include "GarbageCollector.hpp"

#include <iostream>
using namespace std;

Menu::Menu(float width, float height)
{
    if(!font.loadFromFile("./resources/arial.TTF")){
        // handle error
    }

    float menuHeight = height/(MAX_NUMBER_OF_ITEMS +1); 

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Domino");
    menu[0].setPosition(sf::Vector2f(width / 4,menuHeight *1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Trax");
    menu[1].setPosition(sf::Vector2f(width / 4,menuHeight *2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Carcassonne");
    menu[2].setPosition(sf::Vector2f(width / 4,menuHeight *3));

    selectedItemIndex = 0;


    dominoSettingsValues[0] = 2;
    dominoSettingsValues[1] = 20;
    dominoSettingsValues[2] = 2;

    float dominosSettingsWidth = width / 4 + menu[0].getLocalBounds().width + 30;
    float dominosSettingsHeight = menuHeight + 9;
    
    dominoSettingsText[0].setFont(font);
    dominoSettingsText[0].setCharacterSize(20);
    dominoSettingsText[0].setFillColor(sf::Color::White);
    dominoSettingsText[0].setString("Players : " + to_string(dominoSettingsValues[0]));
    dominoSettingsText[0].setPosition(sf::Vector2f(dominosSettingsWidth, dominosSettingsHeight));

    dominosSettingsWidth += dominoSettingsText[0].getLocalBounds().width + 30;

    dominoSettingsText[1].setFont(font);
    dominoSettingsText[1].setCharacterSize(20);
    dominoSettingsText[1].setFillColor(sf::Color::White);
    dominoSettingsText[1].setString("Deck size : " + to_string(dominoSettingsValues[1]));
    dominoSettingsText[1].setPosition(sf::Vector2f(dominosSettingsWidth, dominosSettingsHeight)); 

    dominosSettingsWidth += dominoSettingsText[1].getLocalBounds().width + 30;

    dominoSettingsText[2].setFont(font);
    dominoSettingsText[2].setCharacterSize(20);
    dominoSettingsText[2].setFillColor(sf::Color::White);
    dominoSettingsText[2].setString("Max value of tile : " + to_string(dominoSettingsValues[2]));
    dominoSettingsText[2].setPosition(sf::Vector2f(dominosSettingsWidth, dominosSettingsHeight)); 


    carcassonneSettingsValues[0] = 2;

    float carcassonneSettingsWidth = width / 4 + menu[2].getLocalBounds().width + 30;
    float carcassonneSettingsHeight = menuHeight * 3 + 9;

    carcassonneSettingsText[0].setFont(font);
    carcassonneSettingsText[0].setCharacterSize(20);
    carcassonneSettingsText[0].setFillColor(sf::Color::White);
    carcassonneSettingsText[0].setString("Players : " + to_string(carcassonneSettingsValues[0]));
    carcassonneSettingsText[0].setPosition(sf::Vector2f(carcassonneSettingsWidth, carcassonneSettingsHeight));
}

Menu::~Menu(){

}

void Menu::draw(sf::RenderWindow &window){
    for(int i=0;i< MAX_NUMBER_OF_ITEMS;i++){
        window.draw(menu[i]);
    }
    for(int i=0;i< DOMINO_SETTINGS_NUMBER;i++){
        window.draw(dominoSettingsText[i]);
    }
    for(int i=0;i< CARCASSONNE_SETTINGS_NUMBER;i++){
        window.draw(carcassonneSettingsText[i]);
    }
}

void Menu::MoveUp(){
    if((selectedItemIndex -1 >= 0) && status=="menu"){
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    } else if(selectedItemIndex == 0 && status == "domino"){
        if(dominoSettingsValues[0] < 6)
            dominoSettingsValues[0]++;
        dominoSettingsText[0].setString("Players : " + to_string(dominoSettingsValues[0]));
    } else if(selectedItemIndex == 1 && status == "domino"){
        if(dominoSettingsValues[1] < 99)
            dominoSettingsValues[1]++;
        dominoSettingsText[1].setString("Deck size : " + to_string(dominoSettingsValues[1]));
    } else if(selectedItemIndex == 2 && status == "domino"){
        if(dominoSettingsValues[2] < 9)
            dominoSettingsValues[2]++;
        dominoSettingsText[2].setString("Max value of tile : " + to_string(dominoSettingsValues[2]));
    } else if(status == "carcassonne"){
        if(carcassonneSettingsValues[0] < 4)
            carcassonneSettingsValues[0]++;
        carcassonneSettingsText[0].setString("Players : " + to_string(carcassonneSettingsValues[0]));
    }
}

void Menu::MoveDown(){
    if((selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) && status=="menu"){
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    } else if(selectedItemIndex == 0 && status == "domino"){
        if(dominoSettingsValues[0] > 2)
            dominoSettingsValues[0]--;
        dominoSettingsText[0].setString("Players : " + to_string(dominoSettingsValues[0]));
    } else if(selectedItemIndex == 1 && status == "domino"){
        if(dominoSettingsValues[1] > 10)
            dominoSettingsValues[1]--;
        dominoSettingsText[1].setString("Deck size : " + to_string(dominoSettingsValues[1]));
    } else if(selectedItemIndex == 2 && status == "domino"){
        if(dominoSettingsValues[2] > 1)
            dominoSettingsValues[2]--;
        dominoSettingsText[2].setString("Max value of tile : " + to_string(dominoSettingsValues[2]));
    } else if(status == "carcassonne"){
        if(carcassonneSettingsValues[0] > 2)
            carcassonneSettingsValues[0]--;
        carcassonneSettingsText[0].setString("Players : " + to_string(carcassonneSettingsValues[0]));
    }
}

void Menu::MoveRight(){
    if((selectedItemIndex == 0) && status=="menu"){
        menu[0].setFillColor(sf::Color::White);
        dominoSettingsText[0].setFillColor(sf::Color::Red);
        status = "domino";
    } else if((selectedItemIndex + 1 < DOMINO_SETTINGS_NUMBER) && status == "domino" ){
        dominoSettingsText[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        dominoSettingsText[selectedItemIndex].setFillColor(sf::Color::Red);
    } else if((selectedItemIndex == MAX_NUMBER_OF_ITEMS-1) && status=="menu"){
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        carcassonneSettingsText[0].setFillColor(sf::Color::Red);
        status = "carcassonne";
    }
}

void Menu::MoveLeft(){
    if((selectedItemIndex == 0) && status=="domino"){
        menu[0].setFillColor(sf::Color::Red);
        dominoSettingsText[0].setFillColor(sf::Color::White);
        status = "menu";
    }else if((selectedItemIndex -1 >= 0) && status == "domino" ){
        dominoSettingsText[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        dominoSettingsText[selectedItemIndex].setFillColor(sf::Color::Red);
    }else if(status=="carcassonne"){
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
        carcassonneSettingsText[0].setFillColor(sf::Color::White);
        status = "menu";
    }
}

void Menu::menuLoop(){
    GarbageCollector gc;
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
                    case sf::Keyboard::Left:
                        MoveLeft();
                        break;
                    case sf::Keyboard::Right:
                        MoveRight();
                        break;

                    case sf::Keyboard::Return:
                        if(getPressedItem() == 0 && status=="menu"){
                            GameDomino g(dominoSettingsValues);
                            windowM.close();
                            g.gameLoop();
                            GarbageCollector::clean();
                            windowM.create(sf::VideoMode(800,800), "MENU");
                        }
                        else if(getPressedItem() == 1 && status=="menu"){
                            GameTrax g{};
                            windowM.close();
                            g.gameLoop();
                            GarbageCollector::clean();
                            windowM.create(sf::VideoMode(800,800), "MENU");
                        }
                        else if(getPressedItem() == 2 && status=="menu"){
                            GameCarcassonne g(carcassonneSettingsValues);
                            windowM.close();
                            g.gameLoop();
                            GarbageCollector::clean();
                            windowM.create(sf::VideoMode(800,800), "MENU");
                        }
                        break;
                    default:
                        break;
                }
                break;
            case sf::Event::Closed:
                windowM.close();
                break;
            default:
                break;
            }
        }

        windowM.clear();
        draw(windowM);

        windowM.display();
    }
}