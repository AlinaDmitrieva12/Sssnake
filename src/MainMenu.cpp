#include "MainMenu.h"

MainMenu::MainMenu() {
    firstTexture.loadFromFile("../res/start.png");
    firstButton.setTexture(firstTexture);
    firstButton.setPosition(150, 80);
    secondTexture.loadFromFile("../res/customization.png");
    secondButton.setTexture(secondTexture);
    secondButton.setPosition(150, 210);
    thirdTexture.loadFromFile("../res/exit.png");
    thirdButton.setTexture(thirdTexture);
    thirdButton.setPosition(150, 320);
}

int MainMenu::update(sf::RenderWindow &window) {
    int menuNum = 0;

    firstButton.setColor(sf::Color::White);
    secondButton.setColor(sf::Color::White);
    thirdButton.setColor(sf::Color::White);

    if (firstButton.getGlobalBounds().contains(sf::Mouse::getPosition(window))) {
        firstButton.setColor(sf::Color::Magenta);
        menuNum = 1;
    }
    if (secondButton.getGlobalBounds().contains(sf::Mouse::getPosition(window))) {
        secondButton.setColor(sf::Color::Magenta);
        menuNum = 2;
    }
    if (thirdButton.getGlobalBounds().contains(sf::Mouse::getPosition(window))) {
        thirdButton.setColor(sf::Color::Magenta);
        menuNum = 3;
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (menuNum == 1){
            return 1;
        }
        if (menuNum == 2) {
            return 2;
        }
        if (menuNum == 3) {
            window.close();
        }
    }
    return 3;
}
