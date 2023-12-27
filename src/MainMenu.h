#ifndef GAME_MAINMENU_H
#define GAME_MAINMENU_H
#include <SFML/Graphics.hpp>

class MainMenu {
public:
    MainMenu();
    int update(sf::RenderWindow &window);
    sf::Texture firstTexture;
    sf::Texture secondTexture;
    sf::Texture thirdTexture;
    sf::Sprite firstButton;
    sf::Sprite secondButton;
    sf::Sprite thirdButton;
};


#endif //GAME_MAINMENU_H
