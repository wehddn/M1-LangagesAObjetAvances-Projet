#include "Tile.hpp"
#include "Game.hpp"

#include <SFML/Graphics.hpp>

#include "iostream"

int main()
{
    Game g{};
    Tile* current_tile = nullptr;
    Tile displayedTile;

    bool lock_click;
    bool key_click;
    bool falsePlace;
    sf::RectangleShape* redRect = nullptr;

    Board* b = g.getBoard();
    
    int windowh = 600;
    int windoww = 800;

    sf::RenderWindow window(sf::VideoMode(windoww, windowh), "SFML works!");

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

        //on charge une tuile
        //on met à jour le plateau du jeu
        if(current_tile==nullptr){
            current_tile = g.getTile();
            b->updateBoard();
            //affichage de la tuile suivante dans le coin
            displayedTile = *current_tile;
            displayedTile.setPosition(sf::Vector2f(0,0));
        }

        //condition pour effectuer une action de clic une seule fois
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){    
            lock_click = false;

        //apres un clic, on compare la position du clic avec les emplacements possibles pour la tuile
        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && lock_click != true){
            lock_click = true;
            sf::Vector2i position = sf::Mouse::getPosition(window);
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
            key_click = false;
        }

        //on tourne un tuile apres avoir appuye sur la "fleches droite(???)"
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right && key_click != true){
            key_click = true;
            current_tile->turn();
            displayedTile = *current_tile;
            displayedTile.setPosition(sf::Vector2f(0,0));
        }

        window.draw(*b);
        window.draw(displayedTile);

        window.display();

    }

    return 0;
}