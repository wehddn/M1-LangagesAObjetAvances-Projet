#include "Tile.hpp"
#include "Game.hpp"

#include <SFML/Graphics.hpp>

#include "iostream"

struct Camera
{
    sf::View view;
    sf::Vector2f pos;
    bool locked = false;

    void lock(float x, float y)
    {
        pos.x = x;
        pos.y = y;
        locked = true;
    }

    void unlock() { locked = false; }

    void move(float x, float y)
    {
        if (locked)
        {
            view.move(pos.x - x, pos.y - y);
            pos.x = x;
            pos.y = y;
        }
    }
};

int main()
{
    Game g{};
    Tile* current_tile = nullptr;
    Tile displayedTile;

    bool lock_click;
    bool key_click_right;
    bool falsePlace;
    bool zoom;
    sf::RectangleShape* redRect = nullptr;

    Board* b = g.getBoard();
    
    int windowh = 600;
    int windoww = 800;

    sf::RenderWindow window(sf::VideoMode(windoww, windowh), "SFML works!");

    Camera cam;
    cam.view = window.getView();

    std::cout << "Start!\n";
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseMoved)
            {
                cam.move(event.mouseMove.x, event.mouseMove.y);
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                cam.lock(event.mouseButton.x, event.mouseButton.y);
            }
            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                cam.unlock();
            }

            
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){    
                lock_click = false;
            }

            //apres un clic, on compare la position du clic avec les emplacements possibles pour la tuile
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && lock_click != true){
                lock_click = true;
                sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                sf::Vector2f position = window.mapPixelToCoords(pixelPos);

                int rawCounter=0; int colCounter=0;
                for(auto& row:b->getTiles()){
                    for(auto& col:row){
                        if(col!=nullptr){
                            sf::RectangleShape* r = col->getRect();
                            //si on click à l'intérieur d'un emplacement possible de la tuile,
                            //on essaie de mettre une tuile sur le plateau

                            //si la putTile retourne true, on mis la tuile actuelle a null, 
                            //sinon, on mis l'emplacement sélectionné en rouge
                            if(r!=nullptr && r->getGlobalBounds().contains(position.x, position.y)){
                                if(b->putTile(rawCounter, colCounter, col, current_tile)){
                                    current_tile=nullptr;
                                    falsePlace = false;
                                }
                                else{
                                    redRect = r;
                                    falsePlace = true;
                                }
                                break;
                            }
                        }
                        colCounter++;
                    }
                    colCounter=0;
                    rawCounter++;
                }
            }

            //s'il est impossible de mettre une tuile, on change la couleur de la place selectionne en rouge
            //(condition pour effectuer une action de clic une seule fois)
            if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && falsePlace == true){
                if(redRect!=nullptr)
                    redRect->setOutlineColor(sf::Color::Red);
            }
            else{
                if(redRect!=nullptr){
                    redRect->setOutlineColor(sf::Color::Green);
                    redRect=nullptr;
                }
            }

            //condition pour effectuer une action de clic une seule fois
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right){    
                key_click_right = false;
            }

            //on tourne un tuile apres avoir appuye sur la "fleches droite(???)"
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right && key_click_right != true){
                key_click_right = true;
                current_tile->turn();
                displayedTile = *current_tile;
                displayedTile.setPosition(sf::Vector2f(0,0));
            }

            //zoom view avec Z et X
            if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::X)){    
                zoom = false;
            }

            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Z && zoom != true){
                zoom = true;
                cam.view.zoom(0.9f);
            }

            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::X && zoom != true){
                zoom = true;
                cam.view.zoom(1/0.9f);
            }
        }

        window.clear();

        //on charge une tuile
        //on met à jour le plateau du jeu
        if(current_tile==nullptr){
            current_tile = g.getTile();
            b->updateBoard();
            //affichage de la tuile suivante dans le coin
            displayedTile = *current_tile;
            displayedTile.setPosition(sf::Vector2f(0,0));
        }

        window.setView(cam.view);

        window.draw(*b);
        window.draw(displayedTile);

        window.display();

    }

    return 0;
}