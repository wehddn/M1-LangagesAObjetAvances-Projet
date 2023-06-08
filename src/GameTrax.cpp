#include "Game.hpp"
#include "GarbageCollector.hpp"

#include <iostream>

GameTrax::GameTrax()
{
    board = new BoardTrax();
    GarbageCollector::create(board);
    setDeck();
    setPlayers();
}

void GameTrax::setPlayers(){
    for(int i=0; i<playersNumber; i++){    
        PlayerTrax* p = new PlayerTrax();
        GarbageCollector::create(p);
        string name = "Player " + to_string(i+1);
        p->setName(name);
        players.push_back(p);
    }
    current_player = players[0];
}

TileTrax *GameTrax::getTile()
{
    TileTrax *r = deck.back();
    deck.pop_back();
    return r;
}

BoardTrax *GameTrax::getBoard()
{
    return board;
}

void GameTrax::setCurrentPlayer(int current_player_number){
    current_player = players[current_player_number];
}

void GameTrax::setDeck()
{
    int size = board->getTileSize();
    sf::Texture *textureH = new sf::Texture;
    GarbageCollector::create(textureH);
    textureH->loadFromFile("./resources/tileTraxH.png");
    sf::Texture *textureT = new sf::Texture;
    GarbageCollector::create(textureT);
    textureT->loadFromFile("./resources/tileTraxT.png");
    for (int i = 0; i < deck_size; i++)
    {
        TileTrax *t = new TileTrax(textureH, textureT);
        GarbageCollector::create(t);
        t->setPosition(sf::Vector2f(size, size));
        deck.push_back(t);
    }
}

int GameTrax::getDeckSize(){
    return deck.size();
}

void GameTrax::gameLoop()
{
    bool lock_click;
    bool key_click_right;
    bool key_click_up;
    bool falsePlace;
    bool zoom;

    bool end = false;

    sf::RectangleShape *redRect = nullptr;

    BoardTrax *boardTrax = getBoard();

    int windowh = 600;
    int windoww = 800;

    sf::RenderWindow window(sf::VideoMode(windoww, windowh), "TRAX");

    BarTrax bar(windowh, players);
    bar.displayNextPlayer(0);

    Camera cam;
    cam.view = window.getView();
    
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

            // zoom view avec Z et X
            if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::X))
            {
                zoom = false;
            }

            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Z && zoom != true)
            {
                zoom = true;
                cam.view.zoom(1 / 0.9f);
            }

            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::X && zoom != true)
            {
                zoom = true;
                cam.view.zoom(0.9f);
            }

            if(end)
                break;

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                lock_click = false;
            }

            // apres un clic, on compare la position du clic avec les emplacements possibles pour la tuile
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && lock_click != true)
            {
                lock_click = true;
                sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
                sf::Vector2f position = window.mapPixelToCoords(pixelPos);

                int rawCounter = 0;
                int colCounter = 0;

                if (boardTrax->getTiles().size()==1){
                    boardTrax->getTiles().at(0).at(0)->getRect()->setPosition(sf::Vector2f(position.x, position.y));
                }
                
                for (auto &row : boardTrax->getTiles())
                {
                    for (auto &col : row)
                    {
                        if (col != nullptr)
                        {
                            sf::RectangleShape *r = col->getRect();
                            // si on click à l'intérieur d'un emplacement possible de la tuile,
                            // on essaie de mettre une tuile sur le plateau

                            // si la putTile retourne true, on mis la tuile actuelle a null,
                            // sinon, on mis l'emplacement sélectionné en rouge
                            if (r != nullptr && r->getGlobalBounds().contains(position.x, position.y))
                            {
                                if (boardTrax->putTile(rawCounter, colCounter, col, current_player->getTile()))
                                {
                                    end = (boardTrax->checkPaths(rawCounter, colCounter) || getDeckSize()<=0);
                                    if(!end){
                                        current_player->setTile(nullptr);
                                        falsePlace = false;
                                        if(!boardTrax->checkForced(rawCounter, colCounter))
                                            nextPlayer();
                                        bar.displayNextPlayer(current_player_number);
                                    }
                                    else
                                        bar.setEndGame();
                                }
                                else
                                {
                                    redRect = r;
                                    falsePlace = true;
                                }
                                break;
                            }
                        }
                        colCounter++;
                    }
                    colCounter = 0;
                    rawCounter++;
                }
            }

            // s'il est impossible de mettre une tuile, on change la couleur de la place selectionne en rouge
            //(condition pour effectuer une action de clic une seule fois)
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && falsePlace == true)
            {
                if (redRect != nullptr)
                    redRect->setOutlineColor(sf::Color::Red);
            }
            else
            {
                if (redRect != nullptr)
                {
                    redRect->setOutlineColor(sf::Color::Transparent);
                    redRect = nullptr;
                }
            }

            // condition pour effectuer une action de clic une seule fois
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
            {
                key_click_right = false;
            }
            // on tourne un tuile apres avoir appuye sur la "fleches droite(???)"
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right && key_click_right != true)
            {
                key_click_right = true;
                current_player->getTile()->rotate();
                bar.setDisplayedTile(current_player->getTile());
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
            {
                key_click_up = false;
            }
            //rotate l'image
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up && key_click_up != true)
            {
                key_click_up = true;
                current_player->getTile()->turn();
                bar.setDisplayedTile(current_player->getTile());
            }
        }

        // on charge une tuile
        // on met à jour le plateau du jeu
        if (current_player->getTile() == nullptr)
        {
            current_player->setTile(getTile());
            boardTrax->updateBoard();
            // affichage de la tuile suivante dans le coin
            //displayedTile = *current_tile;
            //displayedTile.setPosition(sf::Vector2f(0, 0));
            bar.setDisplayedTile(current_player->getTile());
        }

        window.clear();

        window.setView(cam.view);
        window.draw(*boardTrax);

        // fixer element (ne pas changer lors du zoom)
        window.setView(window.getDefaultView());
        //window.draw(bar2);
        window.draw(bar);
        window.setView(cam.view);

        window.display();
    }
}