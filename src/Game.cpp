#include <iostream>
#include "Game.h"

Game::Game(sf::RenderWindow &window) : window(window) {
    music.openFromFile("../res/music.wav");
    music.setLoop(true);
    music.play();
}

void Game::customizeWindow() {
    window.create(sf::VideoMode(BLOCK_SIZE * GAME_WIDTH, BLOCK_SIZE * GAME_HEIGHT), "Snake!");
}

void Game::play() {
    snake.update();

    if (snake.checkAppleCollision(apple.getPosition())) {
        apple.updatePosition();
    }

    if (snake.checkOrangeCollision(orange.getPosition())) {
        orange.updatePosition();
    }

    if (snake.checkSpeedUpCollision(speedUp.getPosition())) {
        delay = speedUp.updatePosition(delay);
        isSpeedUpActive = true;
    }

    if (snake.checkSpeedDownCollision(speedDown.getPosition())) {
        delay = speedDown.updatePosition(delay);
        isSpeedDownActive = true;
    }

    game = !snake.checkLose();
}


void Game::handleEvents() {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::update(sf::Clock &clock) {
    std::cout << delay << std::endl;
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;
    if (isSpeedUpActive) {
        speedUpDuration += time;
        if (speedUpDuration >= SPEED_UP_DURATION) {
            speedUpDuration = 0;
            isSpeedUpActive = false;
            isSpeedUpOnCooldown = true;
            delay += 0.3;
        }
    } else if (isSpeedUpOnCooldown) {
        speedUpCooldown += time;
        if (speedUpCooldown >= SPEED_UP_COOLDOWN) {
            isSpeedUpOnCooldown = false;
            speedUpCooldown = 0;
        }
    }
    if (isSpeedDownActive) {
        speedDownDuration += time;
        if (speedDownDuration >= SPEED_DOWN_DURATION) {
            speedDownDuration = 0;
            isSpeedDownActive = false;
            isSpeedDownOnCooldown = true;
            delay -= 0.3;
        }
    } else if (isSpeedDownOnCooldown) {
        speedDownCooldown += time;
        if (speedDownCooldown >= SPEED_DOWN_COOLDOWN) {
            isSpeedDownOnCooldown = false;
            speedDownCooldown = 0;
        }
    }
    snake.updateDirection();
    if (timer > delay && game) {
        timer = 0;
        play();
    }
    if (gameState == GAME_STATE::PLAY) {
        return;
    }
    int state;
    if (gameState == GAME_STATE::MENU) {
        state = mainMenu.update(window);
    } else {
        state = customizationMenu.update(window);
        snake.updateColors(state);
    }
    if (state == 1 || state == 4 || state == 5 || state == 6) {
        gameState = GAME_STATE::PLAY;
    } else if (state == 2) {
        gameState = GAME_STATE::CUSTOMIZATION;
    } else if (state == 3) {
        gameState = GAME_STATE::MENU;
    }
}

void Game::render() {
    window.clear();
    if (gameState == GAME_STATE::MENU) {
        window.draw(mainMenu.firstButton);
        window.draw(mainMenu.secondButton);
        window.draw(mainMenu.thirdButton);
    } else if (gameState == GAME_STATE::CUSTOMIZATION) {
        window.draw(customizationMenu.firstButton);
        window.draw(customizationMenu.secondButton);
        window.draw(customizationMenu.thirdButton);
    } else {
        map.draw(window);
        window.draw(apple.block);
        if (snake.width % 4 == 0) {
            window.draw(orange.block);
        }
        if (!isSpeedUpActive && !isSpeedUpOnCooldown) {
            window.draw(speedUp.block);
        }
        if (!isSpeedDownActive && !isSpeedDownOnCooldown) {
            window.draw(speedDown.block);
        }
        snake.draw(window, !game);
        if (!game) {
            window.draw(loseGameScreen.block);
        }
    }
    window.display();
}
