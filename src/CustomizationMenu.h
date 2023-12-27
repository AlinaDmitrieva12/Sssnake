#ifndef GAME_CUSTOMIZATIONMENU_H
#define GAME_CUSTOMIZATIONMENU_H
#include <SFML/Graphics.hpp>


class CustomizationMenu {
public:
    CustomizationMenu();
    int update(sf::RenderWindow &window);
    sf::Texture firstTexture;
    sf::Texture secondTexture;
    sf::Texture thirdTexture;
    sf::Sprite firstButton;
    sf::Sprite secondButton;
    sf::Sprite thirdButton;
};


#endif //GAME_CUSTOMIZATIONMENU_H
