#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Game.h"

int main() {
    srand(time(nullptr));
    sf::RenderWindow window;
    sf::Clock clock;
    Game game(window);
    game.customizeWindow();

    while (window.isOpen()) {
        game.update(clock);
        game.handleEvents();
        game.render();
    }
}