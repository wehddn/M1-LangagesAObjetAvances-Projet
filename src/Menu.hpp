#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3
#define DOMINO_SETTINGS_NUMBER 3
#define CARCASSONNE_SETTINGS_NUMBER 1

class Menu{
    public:
    Menu(float width,float height);
    ~Menu();
    
    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void menuLoop();

    int getPressedItem(){
        return selectedItemIndex;
    }

    private:
    int selectedItemIndex;
    std::string status = "menu";
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::Text dominoSettingsText[DOMINO_SETTINGS_NUMBER];
    sf::Text carcassonneSettingsText[CARCASSONNE_SETTINGS_NUMBER];
    int dominoSettingsValues[DOMINO_SETTINGS_NUMBER];
    int carcassonneSettingsValues[CARCASSONNE_SETTINGS_NUMBER];
    sf::Text num;
};