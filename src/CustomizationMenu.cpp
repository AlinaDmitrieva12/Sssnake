#include "CustomizationMenu.h"

CustomizationMenu::CustomizationMenu() {
    firstTexture.loadFromFile("../res/redSnake.png");
    firstButton.setTexture(firstTexture);
    firstButton.setPosition(375, 100);
    firstButton.setOrigin(50, 37.5);
    secondTexture.loadFromFile("../res/orangeSnake.png");
    secondButton.setTexture(secondTexture);
    secondButton.setPosition(375, 240);
    secondButton.setOrigin(50, 37.5);
    thirdTexture.loadFromFile("../res/blueSnake.png");
    thirdButton.setTexture(thirdTexture);
    thirdButton.setPosition(375, 380);
    thirdButton.setOrigin(50, 37.5);
}

int CustomizationMenu::update(sf::RenderWindow &window) {
    int menuNum = 0;

    firstButton.setScale(1, 1);
    secondButton.setScale(1, 1);
    thirdButton.setScale(1, 1);


    if (firstButton.getGlobalBounds().contains(sf::Mouse::getPosition(window))) {
        firstButton.setScale(-1, 1);
        menuNum = 1;

    }
    if (secondButton.getGlobalBounds().contains(sf::Mouse::getPosition(window))) {
        secondButton.setScale(-1, 1);
        menuNum = 2;
    }
    if (thirdButton.getGlobalBounds().contains(sf::Mouse::getPosition(window))) {
        thirdButton.setScale(-1, 1);
        menuNum = 3;
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (menuNum == 1){
            return 4;
        }
        if (menuNum == 2) {
            return 5;
        }
        if (menuNum == 3) {
            return 6;
        }
    }
    return 2;
}
